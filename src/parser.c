#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 48
#define LARGE_STATE_COUNT 6
#define SYMBOL_COUNT 44
#define ALIAS_COUNT 0
#define TOKEN_COUNT 28
#define EXTERNAL_TOKEN_COUNT 3
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
  sym_shebang = 1,
  sym_string_short = 2,
  aux_sym_dec_number_token1 = 3,
  anon_sym_0 = 4,
  aux_sym_hex_number_token1 = 5,
  aux_sym_hex_number_token2 = 6,
  aux_sym_bin_number_token1 = 7,
  aux_sym_dec_prefix_token1 = 8,
  anon_sym_DOT = 9,
  aux_sym_dec_prefix_token2 = 10,
  aux_sym_hex_prefix_token1 = 11,
  aux_sym_hex_prefix_token2 = 12,
  aux_sym_bin_prefix_token1 = 13,
  aux_sym_bin_prefix_token2 = 14,
  sym_exp_digits = 15,
  anon_sym_POUND_POUND = 16,
  aux_sym_preprocess_short_token1 = 17,
  anon_sym_POUND_LBRACK = 18,
  aux_sym_preprocess_expr_token1 = 19,
  anon_sym_RBRACK_POUND = 20,
  anon_sym_POUND_PIPE = 21,
  aux_sym_preprocess_name_token1 = 22,
  anon_sym_PIPE_POUND = 23,
  anon_sym_DASH_DASH = 24,
  sym__block_start = 25,
  sym__block_content = 26,
  sym__block_end = 27,
  sym_source_file = 28,
  sym_string = 29,
  sym_string_long = 30,
  sym_number = 31,
  sym_dec_number = 32,
  sym_hex_number = 33,
  sym_bin_number = 34,
  sym_dec_prefix = 35,
  sym_hex_prefix = 36,
  sym_bin_prefix = 37,
  sym_preprocess = 38,
  sym_preprocess_short = 39,
  sym_preprocess_expr = 40,
  sym_preprocess_name = 41,
  sym_comment_short = 42,
  aux_sym_source_file_repeat1 = 43,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_shebang] = "shebang",
  [sym_string_short] = "string_short",
  [aux_sym_dec_number_token1] = "dec_number_token1",
  [anon_sym_0] = "0",
  [aux_sym_hex_number_token1] = "hex_number_token1",
  [aux_sym_hex_number_token2] = "hex_number_token2",
  [aux_sym_bin_number_token1] = "bin_number_token1",
  [aux_sym_dec_prefix_token1] = "dec_prefix_token1",
  [anon_sym_DOT] = ".",
  [aux_sym_dec_prefix_token2] = "dec_prefix_token2",
  [aux_sym_hex_prefix_token1] = "hex_prefix_token1",
  [aux_sym_hex_prefix_token2] = "hex_prefix_token2",
  [aux_sym_bin_prefix_token1] = "bin_prefix_token1",
  [aux_sym_bin_prefix_token2] = "bin_prefix_token2",
  [sym_exp_digits] = "exp_digits",
  [anon_sym_POUND_POUND] = "##",
  [aux_sym_preprocess_short_token1] = "preprocess_short_token1",
  [anon_sym_POUND_LBRACK] = "#[",
  [aux_sym_preprocess_expr_token1] = "preprocess_content",
  [anon_sym_RBRACK_POUND] = "]#",
  [anon_sym_POUND_PIPE] = "#|",
  [aux_sym_preprocess_name_token1] = "preprocess_content",
  [anon_sym_PIPE_POUND] = "|#",
  [anon_sym_DASH_DASH] = "--",
  [sym__block_start] = "_block_start",
  [sym__block_content] = "string_content",
  [sym__block_end] = "_block_end",
  [sym_source_file] = "source_file",
  [sym_string] = "string",
  [sym_string_long] = "string_long",
  [sym_number] = "number",
  [sym_dec_number] = "dec_number",
  [sym_hex_number] = "hex_number",
  [sym_bin_number] = "bin_number",
  [sym_dec_prefix] = "dec_prefix",
  [sym_hex_prefix] = "hex_prefix",
  [sym_bin_prefix] = "bin_prefix",
  [sym_preprocess] = "preprocess",
  [sym_preprocess_short] = "preprocess_short",
  [sym_preprocess_expr] = "preprocess_expr",
  [sym_preprocess_name] = "preprocess_name",
  [sym_comment_short] = "comment_short",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_shebang] = sym_shebang,
  [sym_string_short] = sym_string_short,
  [aux_sym_dec_number_token1] = aux_sym_dec_number_token1,
  [anon_sym_0] = anon_sym_0,
  [aux_sym_hex_number_token1] = aux_sym_hex_number_token1,
  [aux_sym_hex_number_token2] = aux_sym_hex_number_token2,
  [aux_sym_bin_number_token1] = aux_sym_bin_number_token1,
  [aux_sym_dec_prefix_token1] = aux_sym_dec_prefix_token1,
  [anon_sym_DOT] = anon_sym_DOT,
  [aux_sym_dec_prefix_token2] = aux_sym_dec_prefix_token2,
  [aux_sym_hex_prefix_token1] = aux_sym_hex_prefix_token1,
  [aux_sym_hex_prefix_token2] = aux_sym_hex_prefix_token2,
  [aux_sym_bin_prefix_token1] = aux_sym_bin_prefix_token1,
  [aux_sym_bin_prefix_token2] = aux_sym_bin_prefix_token2,
  [sym_exp_digits] = sym_exp_digits,
  [anon_sym_POUND_POUND] = anon_sym_POUND_POUND,
  [aux_sym_preprocess_short_token1] = aux_sym_preprocess_short_token1,
  [anon_sym_POUND_LBRACK] = anon_sym_POUND_LBRACK,
  [aux_sym_preprocess_expr_token1] = aux_sym_preprocess_expr_token1,
  [anon_sym_RBRACK_POUND] = anon_sym_RBRACK_POUND,
  [anon_sym_POUND_PIPE] = anon_sym_POUND_PIPE,
  [aux_sym_preprocess_name_token1] = aux_sym_preprocess_expr_token1,
  [anon_sym_PIPE_POUND] = anon_sym_PIPE_POUND,
  [anon_sym_DASH_DASH] = anon_sym_DASH_DASH,
  [sym__block_start] = sym__block_start,
  [sym__block_content] = sym__block_content,
  [sym__block_end] = sym__block_end,
  [sym_source_file] = sym_source_file,
  [sym_string] = sym_string,
  [sym_string_long] = sym_string_long,
  [sym_number] = sym_number,
  [sym_dec_number] = sym_dec_number,
  [sym_hex_number] = sym_hex_number,
  [sym_bin_number] = sym_bin_number,
  [sym_dec_prefix] = sym_dec_prefix,
  [sym_hex_prefix] = sym_hex_prefix,
  [sym_bin_prefix] = sym_bin_prefix,
  [sym_preprocess] = sym_preprocess,
  [sym_preprocess_short] = sym_preprocess_short,
  [sym_preprocess_expr] = sym_preprocess_expr,
  [sym_preprocess_name] = sym_preprocess_name,
  [sym_comment_short] = sym_comment_short,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_shebang] = {
    .visible = true,
    .named = true,
  },
  [sym_string_short] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_dec_number_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_0] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_hex_number_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_hex_number_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_bin_number_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_dec_prefix_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_dec_prefix_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_hex_prefix_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_hex_prefix_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_bin_prefix_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_bin_prefix_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_exp_digits] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_POUND_POUND] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_preprocess_short_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_POUND_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_preprocess_expr_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_RBRACK_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND_PIPE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_preprocess_name_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PIPE_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [sym__block_start] = {
    .visible = false,
    .named = true,
  },
  [sym__block_content] = {
    .visible = true,
    .named = true,
  },
  [sym__block_end] = {
    .visible = false,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_string_long] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_dec_number] = {
    .visible = true,
    .named = true,
  },
  [sym_hex_number] = {
    .visible = true,
    .named = true,
  },
  [sym_bin_number] = {
    .visible = true,
    .named = true,
  },
  [sym_dec_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym_hex_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym_bin_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym_preprocess] = {
    .visible = true,
    .named = true,
  },
  [sym_preprocess_short] = {
    .visible = true,
    .named = true,
  },
  [sym_preprocess_expr] = {
    .visible = true,
    .named = true,
  },
  [sym_preprocess_name] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_short] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [1] = aux_sym_preprocess_expr_token1,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(18);
      ADVANCE_MAP(
        '"', 2,
        '#', 1,
        '\'', 5,
        '-', 10,
        '.', 29,
        '0', 22,
        '1', 27,
        ']', 3,
        '|', 4,
        'B', 26,
        'b', 26,
        'E', 21,
        'e', 21,
        'P', 25,
        'p', 25,
        'X', 24,
        'x', 24,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 1:
      if (lookahead == '!') ADVANCE(19);
      if (lookahead == '#') ADVANCE(33);
      if (lookahead == '[') ADVANCE(37);
      if (lookahead == '|') ADVANCE(44);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(43);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(50);
      END_STATE();
    case 5:
      if (lookahead == '\'') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"') ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '+') ADVANCE(14);
      if (lookahead == '-') ADVANCE(11);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 7:
      if (lookahead == '-') ADVANCE(10);
      if (lookahead == '.') ADVANCE(29);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(31);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      END_STATE();
    case 8:
      if (lookahead == '-') ADVANCE(10);
      if (lookahead == '.') ADVANCE(29);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(30);
      END_STATE();
    case 9:
      if (lookahead == '-') ADVANCE(10);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(51);
      END_STATE();
    case 11:
      if (lookahead == '-') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 12:
      if (lookahead == '-') ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(49);
      END_STATE();
    case 13:
      if (lookahead == '-') ADVANCE(55);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(42);
      END_STATE();
    case 14:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 15:
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(49);
      END_STATE();
    case 16:
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(42);
      END_STATE();
    case 17:
      if (eof) ADVANCE(18);
      ADVANCE_MAP(
        '"', 2,
        '#', 1,
        '\'', 5,
        '-', 10,
        '.', 29,
        '0', 23,
        'E', 21,
        'e', 21,
        'P', 25,
        'p', 25,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(17);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_shebang);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_string_short);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_dec_number_token1);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_0);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(27);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_hex_number_token1);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_hex_number_token2);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym_bin_number_token1);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_dec_prefix_token1);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(27);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_dec_prefix_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_hex_prefix_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_bin_prefix_token1);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_exp_digits);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_POUND_POUND);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_preprocess_short_token1);
      if (lookahead == '-') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == 0x0b ||
          lookahead == '\f' ||
          lookahead == ' ') ADVANCE(34);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(36);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_preprocess_short_token1);
      if (lookahead == '-') ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(36);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_preprocess_short_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_POUND_LBRACK);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym_preprocess_expr_token1);
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == '-') ADVANCE(39);
      if (lookahead == ']') ADVANCE(42);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(38);
      if (lookahead != 0) ADVANCE(40);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym_preprocess_expr_token1);
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == '-') ADVANCE(53);
      if (lookahead == ']') ADVANCE(42);
      if (lookahead != 0) ADVANCE(40);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_preprocess_expr_token1);
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == ']') ADVANCE(42);
      if (lookahead != 0) ADVANCE(40);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym_preprocess_expr_token1);
      if (lookahead == '-') ADVANCE(13);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(38);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(16);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym_preprocess_expr_token1);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(16);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_RBRACK_POUND);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_POUND_PIPE);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_preprocess_name_token1);
      if (lookahead == '#') ADVANCE(15);
      if (lookahead == '-') ADVANCE(46);
      if (lookahead == '|') ADVANCE(49);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(45);
      if (lookahead != 0) ADVANCE(47);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_preprocess_name_token1);
      if (lookahead == '#') ADVANCE(15);
      if (lookahead == '-') ADVANCE(52);
      if (lookahead == '|') ADVANCE(49);
      if (lookahead != 0) ADVANCE(47);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym_preprocess_name_token1);
      if (lookahead == '#') ADVANCE(15);
      if (lookahead == '|') ADVANCE(49);
      if (lookahead != 0) ADVANCE(47);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_preprocess_name_token1);
      if (lookahead == '-') ADVANCE(12);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(45);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(15);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_preprocess_name_token1);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(15);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_PIPE_POUND);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      if (lookahead == '#') ADVANCE(15);
      if (lookahead == '|') ADVANCE(49);
      if (lookahead != 0) ADVANCE(47);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      if (lookahead == '#') ADVANCE(16);
      if (lookahead == ']') ADVANCE(42);
      if (lookahead != 0) ADVANCE(40);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(36);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != ']') ADVANCE(16);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      if (lookahead != 0 &&
          lookahead != '|') ADVANCE(15);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 17, .external_lex_state = 2},
  [2] = {.lex_state = 17, .external_lex_state = 2},
  [3] = {.lex_state = 17, .external_lex_state = 2},
  [4] = {.lex_state = 17, .external_lex_state = 2},
  [5] = {.lex_state = 17, .external_lex_state = 2},
  [6] = {.lex_state = 17, .external_lex_state = 2},
  [7] = {.lex_state = 17, .external_lex_state = 2},
  [8] = {.lex_state = 17, .external_lex_state = 2},
  [9] = {.lex_state = 17, .external_lex_state = 2},
  [10] = {.lex_state = 17, .external_lex_state = 2},
  [11] = {.lex_state = 17, .external_lex_state = 2},
  [12] = {.lex_state = 17, .external_lex_state = 2},
  [13] = {.lex_state = 17, .external_lex_state = 2},
  [14] = {.lex_state = 17, .external_lex_state = 2},
  [15] = {.lex_state = 17, .external_lex_state = 2},
  [16] = {.lex_state = 17, .external_lex_state = 2},
  [17] = {.lex_state = 17, .external_lex_state = 2},
  [18] = {.lex_state = 17, .external_lex_state = 2},
  [19] = {.lex_state = 17, .external_lex_state = 2},
  [20] = {.lex_state = 17, .external_lex_state = 2},
  [21] = {.lex_state = 17, .external_lex_state = 2},
  [22] = {.lex_state = 17, .external_lex_state = 2},
  [23] = {.lex_state = 17, .external_lex_state = 2},
  [24] = {.lex_state = 17, .external_lex_state = 2},
  [25] = {.lex_state = 17, .external_lex_state = 2},
  [26] = {.lex_state = 17, .external_lex_state = 2},
  [27] = {.lex_state = 17, .external_lex_state = 2},
  [28] = {.lex_state = 17, .external_lex_state = 2},
  [29] = {.lex_state = 8},
  [30] = {.lex_state = 7},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 7},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 48},
  [35] = {.lex_state = 41},
  [36] = {.lex_state = 34},
  [37] = {.lex_state = 8},
  [38] = {.lex_state = 6},
  [39] = {.lex_state = 9},
  [40] = {.lex_state = 6},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 6},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 34},
  [45] = {.lex_state = 0, .external_lex_state = 3},
  [46] = {.lex_state = 0, .external_lex_state = 4},
  [47] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment_short] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_shebang] = ACTIONS(1),
    [sym_string_short] = ACTIONS(1),
    [aux_sym_dec_number_token1] = ACTIONS(1),
    [anon_sym_0] = ACTIONS(1),
    [aux_sym_hex_number_token1] = ACTIONS(1),
    [aux_sym_hex_number_token2] = ACTIONS(1),
    [aux_sym_bin_number_token1] = ACTIONS(1),
    [aux_sym_dec_prefix_token1] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [aux_sym_bin_prefix_token1] = ACTIONS(1),
    [anon_sym_POUND_POUND] = ACTIONS(1),
    [anon_sym_POUND_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK_POUND] = ACTIONS(1),
    [anon_sym_POUND_PIPE] = ACTIONS(1),
    [anon_sym_PIPE_POUND] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(3),
    [sym__block_start] = ACTIONS(1),
    [sym__block_content] = ACTIONS(1),
    [sym__block_end] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(33),
    [sym_string] = STATE(28),
    [sym_string_long] = STATE(22),
    [sym_number] = STATE(28),
    [sym_dec_number] = STATE(25),
    [sym_hex_number] = STATE(25),
    [sym_bin_number] = STATE(25),
    [sym_dec_prefix] = STATE(16),
    [sym_preprocess] = STATE(28),
    [sym_preprocess_short] = STATE(19),
    [sym_preprocess_expr] = STATE(28),
    [sym_preprocess_name] = STATE(28),
    [sym_comment_short] = STATE(1),
    [aux_sym_source_file_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_shebang] = ACTIONS(7),
    [sym_string_short] = ACTIONS(9),
    [anon_sym_0] = ACTIONS(11),
    [aux_sym_dec_prefix_token1] = ACTIONS(13),
    [anon_sym_DOT] = ACTIONS(15),
    [anon_sym_POUND_POUND] = ACTIONS(17),
    [anon_sym_POUND_LBRACK] = ACTIONS(19),
    [anon_sym_POUND_PIPE] = ACTIONS(21),
    [anon_sym_DASH_DASH] = ACTIONS(3),
    [sym__block_start] = ACTIONS(23),
  },
  [2] = {
    [sym_string] = STATE(28),
    [sym_string_long] = STATE(22),
    [sym_number] = STATE(28),
    [sym_dec_number] = STATE(25),
    [sym_hex_number] = STATE(25),
    [sym_bin_number] = STATE(25),
    [sym_dec_prefix] = STATE(16),
    [sym_preprocess] = STATE(28),
    [sym_preprocess_short] = STATE(19),
    [sym_preprocess_expr] = STATE(28),
    [sym_preprocess_name] = STATE(28),
    [sym_comment_short] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(25),
    [sym_string_short] = ACTIONS(9),
    [anon_sym_0] = ACTIONS(11),
    [aux_sym_dec_prefix_token1] = ACTIONS(13),
    [anon_sym_DOT] = ACTIONS(15),
    [anon_sym_POUND_POUND] = ACTIONS(17),
    [anon_sym_POUND_LBRACK] = ACTIONS(19),
    [anon_sym_POUND_PIPE] = ACTIONS(21),
    [anon_sym_DASH_DASH] = ACTIONS(3),
    [sym__block_start] = ACTIONS(23),
  },
  [3] = {
    [sym_string] = STATE(28),
    [sym_string_long] = STATE(22),
    [sym_number] = STATE(28),
    [sym_dec_number] = STATE(25),
    [sym_hex_number] = STATE(25),
    [sym_bin_number] = STATE(25),
    [sym_dec_prefix] = STATE(16),
    [sym_preprocess] = STATE(28),
    [sym_preprocess_short] = STATE(19),
    [sym_preprocess_expr] = STATE(28),
    [sym_preprocess_name] = STATE(28),
    [sym_comment_short] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(27),
    [sym_string_short] = ACTIONS(9),
    [anon_sym_0] = ACTIONS(11),
    [aux_sym_dec_prefix_token1] = ACTIONS(13),
    [anon_sym_DOT] = ACTIONS(15),
    [anon_sym_POUND_POUND] = ACTIONS(17),
    [anon_sym_POUND_LBRACK] = ACTIONS(19),
    [anon_sym_POUND_PIPE] = ACTIONS(21),
    [anon_sym_DASH_DASH] = ACTIONS(3),
    [sym__block_start] = ACTIONS(23),
  },
  [4] = {
    [sym_string] = STATE(28),
    [sym_string_long] = STATE(22),
    [sym_number] = STATE(28),
    [sym_dec_number] = STATE(25),
    [sym_hex_number] = STATE(25),
    [sym_bin_number] = STATE(25),
    [sym_dec_prefix] = STATE(16),
    [sym_preprocess] = STATE(28),
    [sym_preprocess_short] = STATE(19),
    [sym_preprocess_expr] = STATE(28),
    [sym_preprocess_name] = STATE(28),
    [sym_comment_short] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(29),
    [sym_string_short] = ACTIONS(31),
    [anon_sym_0] = ACTIONS(34),
    [aux_sym_dec_prefix_token1] = ACTIONS(37),
    [anon_sym_DOT] = ACTIONS(40),
    [anon_sym_POUND_POUND] = ACTIONS(43),
    [anon_sym_POUND_LBRACK] = ACTIONS(46),
    [anon_sym_POUND_PIPE] = ACTIONS(49),
    [anon_sym_DASH_DASH] = ACTIONS(3),
    [sym__block_start] = ACTIONS(52),
  },
  [5] = {
    [sym_string] = STATE(28),
    [sym_string_long] = STATE(22),
    [sym_number] = STATE(28),
    [sym_dec_number] = STATE(25),
    [sym_hex_number] = STATE(25),
    [sym_bin_number] = STATE(25),
    [sym_dec_prefix] = STATE(16),
    [sym_preprocess] = STATE(28),
    [sym_preprocess_short] = STATE(19),
    [sym_preprocess_expr] = STATE(28),
    [sym_preprocess_name] = STATE(28),
    [sym_comment_short] = STATE(5),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(27),
    [sym_string_short] = ACTIONS(9),
    [anon_sym_0] = ACTIONS(11),
    [aux_sym_dec_prefix_token1] = ACTIONS(13),
    [anon_sym_DOT] = ACTIONS(15),
    [anon_sym_POUND_POUND] = ACTIONS(17),
    [anon_sym_POUND_LBRACK] = ACTIONS(19),
    [anon_sym_POUND_PIPE] = ACTIONS(21),
    [anon_sym_DASH_DASH] = ACTIONS(3),
    [sym__block_start] = ACTIONS(23),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(6), 1,
      sym_comment_short,
    ACTIONS(57), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(55), 8,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      aux_sym_hex_number_token2,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [21] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(7), 1,
      sym_comment_short,
    ACTIONS(61), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(59), 8,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      aux_sym_hex_number_token2,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [42] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(8), 1,
      sym_comment_short,
    ACTIONS(65), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(63), 8,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      aux_sym_hex_number_token2,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [63] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(9), 1,
      sym_comment_short,
    ACTIONS(69), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(67), 8,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      aux_sym_hex_number_token2,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [84] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(10), 1,
      sym_comment_short,
    ACTIONS(73), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(71), 8,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      aux_sym_dec_number_token1,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [105] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(11), 1,
      sym_comment_short,
    ACTIONS(77), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(75), 8,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      aux_sym_dec_number_token1,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [126] = 5,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(83), 1,
      aux_sym_hex_number_token2,
    STATE(12), 1,
      sym_comment_short,
    ACTIONS(81), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(79), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [149] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(13), 1,
      sym_comment_short,
    ACTIONS(87), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(85), 8,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      aux_sym_hex_number_token2,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [170] = 5,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(93), 1,
      aux_sym_hex_number_token2,
    STATE(14), 1,
      sym_comment_short,
    ACTIONS(91), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(89), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [193] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(15), 1,
      sym_comment_short,
    ACTIONS(97), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(95), 8,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      aux_sym_hex_number_token2,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [214] = 5,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(101), 1,
      aux_sym_dec_number_token1,
    STATE(16), 1,
      sym_comment_short,
    ACTIONS(103), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(99), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [237] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(17), 1,
      sym_comment_short,
    ACTIONS(107), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(105), 8,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      aux_sym_dec_number_token1,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [258] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(18), 1,
      sym_comment_short,
    ACTIONS(111), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(109), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [278] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(19), 1,
      sym_comment_short,
    ACTIONS(115), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(113), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [298] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(20), 1,
      sym_comment_short,
    ACTIONS(119), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(117), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [318] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(21), 1,
      sym_comment_short,
    ACTIONS(123), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(121), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [338] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(22), 1,
      sym_comment_short,
    ACTIONS(127), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(125), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [358] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(23), 1,
      sym_comment_short,
    ACTIONS(131), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(129), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [378] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(24), 1,
      sym_comment_short,
    ACTIONS(135), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(133), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [398] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(25), 1,
      sym_comment_short,
    ACTIONS(139), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(137), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [418] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(26), 1,
      sym_comment_short,
    ACTIONS(143), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(141), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [438] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(27), 1,
      sym_comment_short,
    ACTIONS(147), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(145), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [458] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    STATE(28), 1,
      sym_comment_short,
    ACTIONS(151), 2,
      anon_sym_0,
      aux_sym_dec_prefix_token1,
    ACTIONS(149), 7,
      sym__block_start,
      ts_builtin_sym_end,
      sym_string_short,
      anon_sym_DOT,
      anon_sym_POUND_POUND,
      anon_sym_POUND_LBRACK,
      anon_sym_POUND_PIPE,
  [478] = 5,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(153), 1,
      anon_sym_DOT,
    ACTIONS(155), 1,
      aux_sym_hex_prefix_token1,
    STATE(14), 1,
      sym_hex_prefix,
    STATE(29), 1,
      sym_comment_short,
  [494] = 5,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(157), 1,
      anon_sym_DOT,
    ACTIONS(159), 1,
      aux_sym_bin_prefix_token1,
    STATE(12), 1,
      sym_bin_prefix,
    STATE(30), 1,
      sym_comment_short,
  [510] = 4,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(161), 1,
      aux_sym_hex_number_token1,
    ACTIONS(163), 1,
      aux_sym_bin_number_token1,
    STATE(31), 1,
      sym_comment_short,
  [523] = 3,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(165), 1,
      aux_sym_bin_prefix_token1,
    STATE(32), 1,
      sym_comment_short,
  [533] = 3,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(167), 1,
      ts_builtin_sym_end,
    STATE(33), 1,
      sym_comment_short,
  [543] = 3,
    ACTIONS(169), 1,
      aux_sym_preprocess_name_token1,
    ACTIONS(171), 1,
      anon_sym_DASH_DASH,
    STATE(34), 1,
      sym_comment_short,
  [553] = 3,
    ACTIONS(171), 1,
      anon_sym_DASH_DASH,
    ACTIONS(173), 1,
      aux_sym_preprocess_expr_token1,
    STATE(35), 1,
      sym_comment_short,
  [563] = 3,
    ACTIONS(171), 1,
      anon_sym_DASH_DASH,
    ACTIONS(175), 1,
      aux_sym_preprocess_short_token1,
    STATE(36), 1,
      sym_comment_short,
  [573] = 3,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(177), 1,
      aux_sym_hex_prefix_token1,
    STATE(37), 1,
      sym_comment_short,
  [583] = 3,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(179), 1,
      sym_exp_digits,
    STATE(38), 1,
      sym_comment_short,
  [593] = 3,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(181), 1,
      aux_sym_dec_prefix_token1,
    STATE(39), 1,
      sym_comment_short,
  [603] = 3,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(183), 1,
      sym_exp_digits,
    STATE(40), 1,
      sym_comment_short,
  [613] = 3,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(185), 1,
      anon_sym_PIPE_POUND,
    STATE(41), 1,
      sym_comment_short,
  [623] = 3,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(187), 1,
      sym_exp_digits,
    STATE(42), 1,
      sym_comment_short,
  [633] = 3,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(189), 1,
      anon_sym_RBRACK_POUND,
    STATE(43), 1,
      sym_comment_short,
  [643] = 3,
    ACTIONS(171), 1,
      anon_sym_DASH_DASH,
    ACTIONS(191), 1,
      aux_sym_preprocess_short_token1,
    STATE(44), 1,
      sym_comment_short,
  [653] = 3,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(193), 1,
      sym__block_content,
    STATE(45), 1,
      sym_comment_short,
  [663] = 3,
    ACTIONS(3), 1,
      anon_sym_DASH_DASH,
    ACTIONS(195), 1,
      sym__block_end,
    STATE(46), 1,
      sym_comment_short,
  [673] = 1,
    ACTIONS(197), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(6)] = 0,
  [SMALL_STATE(7)] = 21,
  [SMALL_STATE(8)] = 42,
  [SMALL_STATE(9)] = 63,
  [SMALL_STATE(10)] = 84,
  [SMALL_STATE(11)] = 105,
  [SMALL_STATE(12)] = 126,
  [SMALL_STATE(13)] = 149,
  [SMALL_STATE(14)] = 170,
  [SMALL_STATE(15)] = 193,
  [SMALL_STATE(16)] = 214,
  [SMALL_STATE(17)] = 237,
  [SMALL_STATE(18)] = 258,
  [SMALL_STATE(19)] = 278,
  [SMALL_STATE(20)] = 298,
  [SMALL_STATE(21)] = 318,
  [SMALL_STATE(22)] = 338,
  [SMALL_STATE(23)] = 358,
  [SMALL_STATE(24)] = 378,
  [SMALL_STATE(25)] = 398,
  [SMALL_STATE(26)] = 418,
  [SMALL_STATE(27)] = 438,
  [SMALL_STATE(28)] = 458,
  [SMALL_STATE(29)] = 478,
  [SMALL_STATE(30)] = 494,
  [SMALL_STATE(31)] = 510,
  [SMALL_STATE(32)] = 523,
  [SMALL_STATE(33)] = 533,
  [SMALL_STATE(34)] = 543,
  [SMALL_STATE(35)] = 553,
  [SMALL_STATE(36)] = 563,
  [SMALL_STATE(37)] = 573,
  [SMALL_STATE(38)] = 583,
  [SMALL_STATE(39)] = 593,
  [SMALL_STATE(40)] = 603,
  [SMALL_STATE(41)] = 613,
  [SMALL_STATE(42)] = 623,
  [SMALL_STATE(43)] = 633,
  [SMALL_STATE(44)] = 643,
  [SMALL_STATE(45)] = 653,
  [SMALL_STATE(46)] = 663,
  [SMALL_STATE(47)] = 673,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bin_prefix, 3, 0, 0),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bin_prefix, 3, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hex_prefix, 3, 0, 0),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_hex_prefix, 3, 0, 0),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bin_prefix, 2, 0, 0),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bin_prefix, 2, 0, 0),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hex_prefix, 2, 0, 0),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_hex_prefix, 2, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dec_prefix, 1, 0, 0),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dec_prefix, 1, 0, 0),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dec_prefix, 3, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dec_prefix, 3, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bin_number, 3, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bin_number, 3, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bin_prefix, 1, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bin_prefix, 1, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hex_number, 3, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_hex_number, 3, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hex_prefix, 1, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_hex_prefix, 1, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dec_number, 1, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dec_number, 1, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dec_prefix, 2, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dec_prefix, 2, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_preprocess_short, 2, 0, 1),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_preprocess_short, 2, 0, 1),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_preprocess, 1, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_preprocess, 1, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bin_number, 5, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bin_number, 5, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_hex_number, 5, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_hex_number, 5, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 1, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 1, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dec_number, 3, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_dec_number, 3, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_preprocess_name, 3, 0, 0),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_preprocess_name, 3, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number, 1, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_long, 3, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_long, 3, 0, 0),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_preprocess_expr, 3, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_preprocess_expr, 3, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 1, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 1, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [167] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [169] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [171] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [173] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [175] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [191] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_short, 2, 0, 0),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__block_start = 0,
  ts_external_token__block_content = 1,
  ts_external_token__block_end = 2,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__block_start] = sym__block_start,
  [ts_external_token__block_content] = sym__block_content,
  [ts_external_token__block_end] = sym__block_end,
};

static const bool ts_external_scanner_states[5][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__block_start] = true,
    [ts_external_token__block_content] = true,
    [ts_external_token__block_end] = true,
  },
  [2] = {
    [ts_external_token__block_start] = true,
  },
  [3] = {
    [ts_external_token__block_content] = true,
  },
  [4] = {
    [ts_external_token__block_end] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_nelua_external_scanner_create(void);
void tree_sitter_nelua_external_scanner_destroy(void *);
bool tree_sitter_nelua_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_nelua_external_scanner_serialize(void *, char *);
void tree_sitter_nelua_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_nelua(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_nelua_external_scanner_create,
      tree_sitter_nelua_external_scanner_destroy,
      tree_sitter_nelua_external_scanner_scan,
      tree_sitter_nelua_external_scanner_serialize,
      tree_sitter_nelua_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
