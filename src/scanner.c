#include <tree_sitter/parser.h>
#include <wctype.h>
#include <stdio.h>

/* Taken from tree-sitter-lua */

enum TokenType {
  BLOCK_START,
  BLOCK_COMMENT_START,
  BLOCK_CONTENT,
  BLOCK_END,
};

static inline void consume(TSLexer *lexer) { lexer->advance(lexer, false); }
static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

static inline bool consume_char(char c, TSLexer *lexer) {
  if (lexer->lookahead != c) {
    return false;
  }

  consume(lexer);
  return true;
}

static inline uint8_t consume_and_count_char(char c, TSLexer *lexer) {
  uint8_t count = 0;
  while (lexer->lookahead == c) {
    ++count;
    consume(lexer);
  }
  return count;
}

static inline void skip_whitespaces(TSLexer *lexer) {
  while (iswspace(lexer->lookahead)) {
    skip(lexer);
  }
}

void *tree_sitter_nelua_external_scanner_create() { return NULL; }
void tree_sitter_nelua_external_scanner_destroy(void *payload) {}

char ending_char = 0;
uint8_t level_count = 0;

static inline void reset_state() {
  ending_char = 0;
  level_count = 0;
}

unsigned tree_sitter_nelua_external_scanner_serialize(void *payload, char *buffer) {
  buffer[0] = ending_char;
  buffer[1] = level_count;
  return 2;
}

void tree_sitter_nelua_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
  if (length == 0) return;
  ending_char = buffer[0];
  if (length == 1) return;
  level_count = buffer[1];
}

static bool scan_block_start(TSLexer *lexer) {
  if (consume_char('[', lexer)) {
    uint8_t level = consume_and_count_char('=', lexer);

    if (consume_char('[', lexer)) {
      level_count = level;
      return true;
    }
  }

  return false;
}

static bool scan_block_end(TSLexer *lexer) {
  if (consume_char(']', lexer)) {
    uint8_t level = consume_and_count_char('=', lexer);

    if (level_count == level && consume_char(']', lexer)) {
      return true;
    }
  }

  return false;
}

static bool scan_block_content(TSLexer *lexer) {
  while (lexer->lookahead != 0) {
    if (lexer->lookahead == ']') {
      lexer->mark_end(lexer);

      if (scan_block_end(lexer)) {
        return true;
      }
    } else {
      consume(lexer);
    }
  }

  return false;
}

static bool scan_block_start_outer(TSLexer *lexer) {
  if (scan_block_start(lexer)) {
    lexer->mark_end(lexer);
    lexer->result_symbol = BLOCK_START;
    return true;
  }

  return false;
}

static bool scan_comment_start(TSLexer *lexer) {
  if (scan_block_start(lexer)) {
    lexer->mark_end(lexer);
    lexer->result_symbol = BLOCK_COMMENT_START;
    return true;
  }

  return false;
}

static bool scan_comment_content(TSLexer *lexer) {
  if (ending_char == 0) { // block comment
    if (scan_block_content(lexer)) {
      lexer->result_symbol = BLOCK_CONTENT;
      return true;
    }

    return false;
  }

  while (lexer->lookahead != 0) {
    if (lexer->lookahead == ending_char) {
      reset_state();
      lexer->result_symbol = BLOCK_CONTENT;
      return true;
    }

    consume(lexer);
  }

  return false;
}

bool tree_sitter_nelua_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  if (valid_symbols[BLOCK_END] && ending_char == 0 && scan_block_end(lexer)) {
    reset_state();
    lexer->result_symbol = BLOCK_END;
    return true;
  }

  if (valid_symbols[BLOCK_CONTENT] && scan_comment_content(lexer)) {
    return true;
  }

  // Comments need the equivalent of a `token.immediate`, so don't skip whitespace
  if (valid_symbols[BLOCK_COMMENT_START]) {
    if (scan_comment_start(lexer)) {
      return true;
    }
  }

  skip_whitespaces(lexer);

  if (valid_symbols[BLOCK_START]) {
    if (scan_block_start_outer(lexer)) {
      return true;
    }
  }

  return false;
}
