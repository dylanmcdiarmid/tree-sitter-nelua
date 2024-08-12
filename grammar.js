/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const PREC = {
  COMMA: -1,
  FUNCTION: 1,
  DEFAULT: 1,
  PRIORITY: 2,

  OR: 3, // or
  AND: 4, // and
  CMP: 5, // == ~= >= <= > <
  BOR: 6, // |
  BXOR: 7, // ~
  BAND: 8, // &
  BSHIFT: 9, // >> << >>>
  CONCAT: 10, // ..
  ARITH: 11, // + -
  FACTOR: 12, // * /// // / %%% %
  POWER: 13, // ^
  UNARY: 14, // not - # ~ $

  TUNARY: 3, // *T
  TVARIS: 4, // T|I
  TGENERIC: 5, // T(v)

  STATEMENT: 15,
  PROGRAM: 16,
};

module.exports = grammar({
  name: "nelua",

  externals: ($) => [$.block_start, $.block_comment_start, $.block_content, $.block_end],

  extras: ($) => [/[\n\r]/, /\s/, $.comment],

  inline: ($) => [$._expression],

  rules: {
    // TODO: add the actual grammar rules

    source_file: ($) =>
      prec(
        PREC.PROGRAM,
        seq(
          optional($.shebang),
          repeat($._statement),
          optional(alias($.return_statement, $.module_return_statement)),
        ),
      ),

    _statement: ($) =>
      prec.right(
        PREC.STATEMENT,
        seq(
          choice(
            $._call,
            $.label,
            $.do_statement,
            $.defer_statement,
            $.while_statement,
            $.repeat_statement,
            $.if_statement,
            $.for_statement,
            $.switch_statement,
            $.preproces_statement,
          ),
          optional(";"),
        ),
      ),

    shebang: ($) => /#![^\n\r]*/,

    _last_statement: ($) =>
      choice(
        $.return_statement,
        $.break_statement,
        $.continue_statement,
        $.fallthrough_statement,
        $.in_statement,
        $.goto_statement,
      ),

    _chunk: ($) =>
      choice(
        seq(repeat1(seq($._statement)), optional($._last_statement)),
        $._last_statement,
      ),

    _block: ($) => $._chunk,

    label: ($) => seq("::", $._name, "::"),

    return_statement: ($) =>
      prec(
        PREC.PRIORITY,
        seq(
          "return",
          optional_seq($._expression, repeat(seq(",", $._expression))),
        ),
      ),

    in_statement: ($) => seq("in", $._expression),

    break_statement: ($) => "break",

    continue_statement: ($) => "continue",

    fallthrough_statement: ($) => "fallthrough",

    goto_statement: ($) => seq("goto", $._name),

    do_statement: ($) =>
      seq(alias("do", $.do_start), optional($._block), alias("end", $.do_end)),

    defer_statement: ($) =>
      seq(
        alias("defer", $.defer_start),
        optional($._block),
        alias("end", $.defer_end),
      ),

    while_statement: ($) =>
      seq(
        alias("while", $.while_start),
        $._expression,
        alias("do", $.while_do),
        optional($._block),
        alias("end", $.while_end),
      ),

    for_statement: ($) =>
      seq(
        alias("for", $.for_start),
        choice($._fornum_statement, $._forin_statement),
      ),
    _fornum_statement: ($) =>
      seq(
        $._iddecl,
        "=",
        $._expression,
        ",",
        alias(optional(choice("~=", ">=", ">", "<=", "<")), $.for_cmp),
        $._expression,
        optional_seq(",", $._expression),
        alias("do", $.for_do),
        optional($._block),
        alias("end", $.for_end),
      ),
    _forin_statement: ($) =>
      seq(
        $._iddecls,
        alias("in", $.for_in),
        $._expression,
        alias("do", $.for_do),
        optional($._block),
        alias("end", $.for_end),
      ),

    repeat_statement: ($) =>
      seq(
        alias("repeat", $.repeat_start),
        optional($._block),
        alias("until", $.repeat_until),
        $._expression,
      ),

    if_statement: ($) =>
      seq(
        alias("if", $.if_start),
        $._expression,
        alias("then", $.if_then),
        optional($._block),
        repeat(
          seq(
            alias("elseif", $.if_elseif),
            $._expression,
            alias("then", $.if_then),
            optional($._block),
          ),
        ),
        optional_seq(alias("else", $.if_else), optional($._block)),
        alias("end", $.if_end),
      ),

    switch_statement: ($) =>
      seq(
        alias("switch", $.switch_start),
        $._expression,
        alias("do", $.switch_do),
        repeat1(
          seq(
            alias("case", $.switch_case),
            $._expression,
            alias("then", $.switch_then),
            optional($._block),
          ),
        ),
        optional_seq(alias("else", $.switch_else), optional($._block)),
        alias("end", $.switch_end),
      ),

    preproces_statement: ($) =>
      choice(
        seq("##", alias(/[^\n\r]*/, $.preprocess_content)),
        seq(
          "##",
          $.block_start,
          alias($.block_content, $.preprocess_content),
          $.block_end,
        ),
      ),

    // Expressions

    _expression: ($) =>
      prec.left(
        choice(
          $.number,
          $.string,
          $.boolean,
          $.nil,
          $.nilptr,
          $.varargs,
          $.id,
          $.paren,
          $.do_expr,
          $.type_expr,
          $.init_list,
          $.binary_operations,
          $.unary_operations,
        ),
      ),

    _exprprim: ($) => choice($._ppcallprim, $.id, $.do_expr, $.paren),

    varargs: ($) => "...",

    type_expr: ($) => seq("@", $.type),

    nil: ($) => "nil",

    nilptr: ($) => "nilptr",

    boolean: ($) => choice("true", "false"),

    paren: ($) => seq("(", $._expression, ")"),

    do_expr: ($) =>
      seq(
        "(",
        alias("do", $.do_start),
        $._statement,
        alias("end", $.do_end),
        ")",
      ),

    string: ($) => choice($._string_short, $._string_long),
    _string_short: ($) => {
      const content = prec(1, /[^\n'"]*/);
      const double_quote = seq('"', content, '"');
      const single_quote = seq("'", content, "'");
      return token(choice(double_quote, single_quote));
    },
    _string_long: ($) => seq($.block_start, $.block_content, $.block_end),

    number: ($) => choice($._hex_number, $._bin_number, $._dec_number),
    _dec_number: ($) =>
      seq(
        alias($._dec_prefix, $.dec_number),
        optional_seq(/[eE]/, alias($._exp_digits, $.exponent)),
      ),
    _hex_number: ($) =>
      seq(
        "0",
        /[xX]/,
        alias($._hex_prefix, $.hex_number),
        optional_seq(/[pP]/, alias($._exp_digits, $.exponent)),
      ),
    _bin_number: ($) =>
      seq(
        "0",
        /[bB]/,
        alias($._bin_prefix, $.bin_number),
        optional_seq(/[pP]/, alias($._exp_digits, $.exponent)),
      ),
    _dec_prefix: ($) =>
      choice(
        prec.left(2, seq(/[0-9]+/, optional_seq(".", /[0-9]*/))),
        prec.left(1, seq(".", /[0-9]+/)),
      ),
    _hex_prefix: ($) =>
      choice(
        prec.left(2, seq(/[0-9a-fA-F]+/, optional_seq(".", /[0-9a-fA-F]*/))),
        prec.left(1, seq(".", /[0-9a-fA-F]+/)),
      ),
    _bin_prefix: ($) =>
      choice(
        prec.left(2, seq(/[01]+/, optional_seq(".", /[01]*/))),
        prec.left(1, seq(".", /[01]+/)),
      ),
    _exp_digits: ($) => /[+-]?[0-9]+/,

    binary_operations: ($) =>
      choice(
        ...[
          ["or", PREC.OR],
          ["and", PREC.AND],
          ["==", PREC.CMP],
          ["~=", PREC.CMP],
          ["<=", PREC.CMP],
          [">=", PREC.CMP],
          ["<", PREC.CMP],
          [">", PREC.CMP],
          ["|", PREC.BOR],
          ["~", PREC.BXOR],
          ["&", PREC.AND],
          ["<<", PREC.BSHIFT],
          [">>", PREC.BSHIFT],
          [">>>", PREC.BSHIFT],
          ["..", PREC.CONCAT],
          ["+", PREC.ARITH],
          ["-", PREC.ARITH],
          ["*", PREC.FACTOR],
          ["///", PREC.FACTOR],
          ["//", PREC.FACTOR],
          ["/", PREC.FACTOR],
          ["%%%", PREC.FACTOR],
          ["%", PREC.FACTOR],
          ["^", PREC.POWER],
        ].map(([operator, precedence]) =>
          prec.left(precedence, seq($._expression, operator, $._expression)),
        ),
      ),

    unary_operations: ($) =>
      prec.left(
        PREC.UNARY,
        seq(choice("not", "-", "#", "~", "&", "$"), $._expression),
      ),

    preprocess_expr: ($) =>
      seq("#[", alias($._expression, $.preprocess_content), "]#"),
    preprocess_name: ($) =>
      seq("#|", alias($._expression, $.preprocess_content), "|#"),
    _ppcallprim: ($) => alias(seq($._name, "!"), $.preprocess_expr),

    init_list: ($) =>
      seq(
        "{",
        optional_seq(
          $._field,
          repeat_seq($._fieldsep, $._field),
          optional($._fieldsep),
        ),
        "}",
      ),
    _field: ($) => choice($.pair, $._expression),
    _fieldsep: ($) => choice(",", ";"),

    pair: ($) =>
      choice(
        seq("[", $._expression, "]", "=", $._expression),
        seq($._name, "=", $._expression),
        seq("=", $.id),
      ),

    _typedecl: ($) =>
      prec(2, seq(alias($._name, $.argname), ":", $.type, optional($._annots))),

    id: ($) => choice($.preprocess_expr, $._name),
    iddecl: ($) => seq($._iddecl, optional($._annots)),
    _iddecl: ($) => seq(alias($._name, $.id), optional_seq(":", $.id)),

    annotation: ($) =>
      seq(alias($._name, $.annotname), alias($._annotargs, $.args)),

    _name: ($) => choice($.preprocess_name, /[_a-zA-Z][_a-zA-Z0-9]*/),

    // Suffixes

    default_call: ($) => $._callargs,
    call_method: ($) => seq(":", alias($._name, $.funcname), $._callargs),
    dot_index: ($) => seq(".", $._name),
    colon_index: ($) => seq(":", $._name),
    key_index: ($) => seq("[", $._expression, "]"),

    indexsuffix: ($) => choice($.dot_index, $.key_index),
    callsuffix: ($) => choice($.default_call, $.call_method),

    _call: ($) =>
      prec.left(
        seq(
          repeat1(
            choice($._exprprim, seq(repeat1($.indexsuffix), $.callsuffix)),
          ),
        ),
      ),

    // Lists

    _callargs: ($) =>
      prec(
        2,
        choice(
          seq(
            "(",
            optional_seq($._expression, repeat_seq(",", $._expression)),
            ")",
          ),
          $.init_list,
          $.string,
        ),
      ),

    _annotargs: ($) =>
      choice(
        seq(
          "(",
          optional_seq($._expression, repeat_seq(",", $._expression)),
          ")",
        ),
        $.init_list,
        $.string,
        $.preprocess_expr,
      ),

    _funcargs: ($) =>
      optional(
        choice(
          seq(
            $._iddecl,
            repeat_seq(",", $._iddecl),
            optional_seq(",", $.varargs_type),
          ),
          $.varargs_type,
        ),
      ),

    _funcrets: ($) =>
      choice(
        seq(
          "(",
          alias($.type, $.rettype),
          repeat_seq(",", alias($.type, $.rettype)),
          ")",
        ),
        alias($.type, $.rettype),
      ),

    _annots: ($) => seq("<", $.annotation, repeat_seq(",", $.annotation), ">"),
    _iddecls: ($) => seq($._iddecl, repeat_seq(",", $._iddecl)),

    // Types

    record_type: ($) =>
      seq(
        "record",
        "{",
        optional_seq(
          $._record_field,
          repeat_seq($._fieldsep, $._record_field),
          optional($._fieldsep),
        ),
        "}",
      ),
    _record_field: ($) => seq($._name, ":", $.type),

    union_type: ($) =>
      seq(
        "union",
        "{",
        optional_seq(
          $._union_field,
          repeat_seq($._fieldsep, $._union_field),
          optional($._fieldsep),
        ),
        "}",
      ),
    _union_field: ($) => choice(seq($._name, ":", $.type), seq($.type)),

    enum_type: ($) =>
      seq(
        "enum",
        optional_seq("(", $.type, ")"),
        "{",
        optional_seq(
          $._enum_field,
          repeat_seq($._fieldsep, $._enum_field),
          optional($._fieldsep),
        ),
        "}",
      ),
    _enum_field: ($) => seq($._name, optional_seq("=", $._expression)),

    func_type: ($) =>
      seq(
        "function",
        "(",
        optional($._functypeargs),
        ")",
        optional_seq(":", $._funcrets),
      ),

    array_type: ($) =>
      seq("array", "(", $.type, optional_seq(",", $._expression), ")"),

    pointer_type: ($) => seq("pointer", "(", $.type, ")"),

    variant_type: ($) => seq("variant", "(", $._typeargs, ")"),

    varargs_type: ($) => prec(2, seq("...", optional_seq(":", $._name))),

    // Type lists

    _typearg: ($) =>
      prec(1, choice($.type, seq("(", $._expression, ")"), $._expression)),
    _typeargs: ($) => seq($._typearg, repeat_seq(",", $._typearg)),

    _functypeargs: ($) =>
      choice(
        seq(
          alias($._functypearg, $.argtype),
          repeat_seq(",", alias($._functypearg, $.argtype)),
          optional_seq(alias($.varargs_type, $.argtype)),
        ),
        alias($.varargs_type, $.argtype),
      ),
    _functypearg: ($) => choice($._typedecl, $._typearg),

    _typegeneric: ($) => choice(seq("(", $._typeargs, ")"), $.init_list),

    type: ($) =>
      prec(
        2,
        choice(
          $.id,
          $.record_type,
          $.union_type,
          $.enum_type,
          $.func_type,
          $.array_type,
          $.pointer_type,
          $.variant_type,
          prec.left(
            PREC.TGENERIC,
            seq(
              alias($.id, $.genericname),
              alias($._typegeneric, $.genericargs),
            ),
          ),
          repeat1_seq(
            choice(
              ...["*", "?", seq("[", optional($._expression))].map((c) =>
                prec.left(PREC.TUNARY, c),
              ),
            ),
            $.type,
          ),
          prec.left(
            PREC.TVARIS,
            seq($.type, "|", $.type, repeat_seq("|", $.type)),
          ),
        ),
      ),

    comment: ($) =>
      choice(
        seq("--", field("content", /[^\n\r]*/)),
        seq(
          "--",
          $.block_comment_start,
          field("content", $.block_content),
          $.block_end,
        ),
      ),
  },
});

function optional_seq(...args) {
  return optional(seq(...args));
}
function repeat_seq(...args) {
  return repeat(seq(...args));
}
function repeat1_seq(...args) {
  return repeat1(seq(...args));
}
