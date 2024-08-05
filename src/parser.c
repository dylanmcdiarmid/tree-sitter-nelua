#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 14
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 12
#define ALIAS_COUNT 0
#define TOKEN_COUNT 7
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_string_short = 1,
  aux_sym_dec_number_token1 = 2,
  aux_sym_dec_prefix_token1 = 3,
  anon_sym_DOT = 4,
  aux_sym_dec_prefix_token2 = 5,
  sym_exp_digits = 6,
  sym_source_file = 7,
  sym_number = 8,
  sym_dec_number = 9,
  sym_dec_prefix = 10,
  aux_sym_dec_prefix_repeat1 = 11,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_string_short] = "string_short",
  [aux_sym_dec_number_token1] = "dec_number_token1",
  [aux_sym_dec_prefix_token1] = "dec_prefix_token1",
  [anon_sym_DOT] = ".",
  [aux_sym_dec_prefix_token2] = "dec_prefix_token2",
  [sym_exp_digits] = "exp_digits",
  [sym_source_file] = "source_file",
  [sym_number] = "number",
  [sym_dec_number] = "dec_number",
  [sym_dec_prefix] = "dec_prefix",
  [aux_sym_dec_prefix_repeat1] = "dec_prefix_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_string_short] = sym_string_short,
  [aux_sym_dec_number_token1] = aux_sym_dec_number_token1,
  [aux_sym_dec_prefix_token1] = aux_sym_dec_prefix_token1,
  [anon_sym_DOT] = anon_sym_DOT,
  [aux_sym_dec_prefix_token2] = aux_sym_dec_prefix_token2,
  [sym_exp_digits] = sym_exp_digits,
  [sym_source_file] = sym_source_file,
  [sym_number] = sym_number,
  [sym_dec_number] = sym_dec_number,
  [sym_dec_prefix] = sym_dec_prefix,
  [aux_sym_dec_prefix_repeat1] = aux_sym_dec_prefix_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
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
  [sym_exp_digits] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
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
  [sym_dec_prefix] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_dec_prefix_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(7);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '\'') ADVANCE(2);
      if (lookahead == '.') ADVANCE(11);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '\'') ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '.') ADVANCE(11);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 4:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 5:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    case 6:
      if (eof) ADVANCE(7);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(12);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_string_short);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(aux_sym_dec_number_token1);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(aux_sym_dec_prefix_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(aux_sym_dec_prefix_token2);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_exp_digits);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(13);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 3},
  [2] = {.lex_state = 6},
  [3] = {.lex_state = 6},
  [4] = {.lex_state = 6},
  [5] = {.lex_state = 6},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 6},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 4},
  [13] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_string_short] = ACTIONS(1),
    [aux_sym_dec_number_token1] = ACTIONS(1),
    [aux_sym_dec_prefix_token1] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [aux_sym_dec_prefix_token2] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(9),
    [sym_number] = STATE(10),
    [sym_dec_number] = STATE(11),
    [sym_dec_prefix] = STATE(8),
    [aux_sym_dec_prefix_token1] = ACTIONS(3),
    [anon_sym_DOT] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(9), 1,
      aux_sym_dec_prefix_token2,
    STATE(4), 1,
      aux_sym_dec_prefix_repeat1,
    ACTIONS(7), 2,
      ts_builtin_sym_end,
      aux_sym_dec_number_token1,
  [11] = 3,
    ACTIONS(11), 1,
      aux_sym_dec_prefix_token2,
    STATE(5), 1,
      aux_sym_dec_prefix_repeat1,
    ACTIONS(7), 2,
      ts_builtin_sym_end,
      aux_sym_dec_number_token1,
  [22] = 3,
    ACTIONS(11), 1,
      aux_sym_dec_prefix_token2,
    STATE(5), 1,
      aux_sym_dec_prefix_repeat1,
    ACTIONS(13), 2,
      ts_builtin_sym_end,
      aux_sym_dec_number_token1,
  [33] = 3,
    ACTIONS(17), 1,
      aux_sym_dec_prefix_token2,
    STATE(5), 1,
      aux_sym_dec_prefix_repeat1,
    ACTIONS(15), 2,
      ts_builtin_sym_end,
      aux_sym_dec_number_token1,
  [44] = 2,
    ACTIONS(22), 1,
      anon_sym_DOT,
    ACTIONS(20), 2,
      ts_builtin_sym_end,
      aux_sym_dec_number_token1,
  [52] = 2,
    ACTIONS(24), 1,
      aux_sym_dec_prefix_token2,
    STATE(3), 1,
      aux_sym_dec_prefix_repeat1,
  [59] = 2,
    ACTIONS(26), 1,
      ts_builtin_sym_end,
    ACTIONS(28), 1,
      aux_sym_dec_number_token1,
  [66] = 1,
    ACTIONS(30), 1,
      ts_builtin_sym_end,
  [70] = 1,
    ACTIONS(32), 1,
      ts_builtin_sym_end,
  [74] = 1,
    ACTIONS(34), 1,
      ts_builtin_sym_end,
  [78] = 1,
    ACTIONS(36), 1,
      sym_exp_digits,
  [82] = 1,
    ACTIONS(38), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 11,
  [SMALL_STATE(4)] = 22,
  [SMALL_STATE(5)] = 33,
  [SMALL_STATE(6)] = 44,
  [SMALL_STATE(7)] = 52,
  [SMALL_STATE(8)] = 59,
  [SMALL_STATE(9)] = 66,
  [SMALL_STATE(10)] = 70,
  [SMALL_STATE(11)] = 74,
  [SMALL_STATE(12)] = 78,
  [SMALL_STATE(13)] = 82,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dec_prefix, 2, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dec_prefix, 3, 0, 0),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_dec_prefix_repeat1, 2, 0, 0),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_dec_prefix_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [20] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dec_prefix, 1, 0, 0),
  [22] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dec_number, 1, 0, 0),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [30] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1, 0, 0),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_dec_number, 3, 0, 0),
};

#ifdef __cplusplus
extern "C" {
#endif
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
