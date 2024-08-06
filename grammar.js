/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const PREC = {
  OR: 1, // or
  AND: 2, // and
  CMP: 3, // == ~= >= <= > <
  BOR: 4, // |
  BXOR: 5, // ~
  BAND: 6, // &
  BSHIFT: 7, // >> << >>>
  CONCAT: 8, // ..
  ARITH: 9, // + -
  FACTOR: 10, // * /// // / %%% %
  POWER: 11, // ^
  UNARY: 12, // not - # ~ $
};

module.exports = grammar({
  name: "nelua",

  externals: $ => [$._block_start, $._block_content, $._block_end],

  extras: $ => [/[\n\r]/, /\s/, $.comment],

  inline: $ => [$._expression],

  rules: {
    // TODO: add the actual grammar rules
    source_file: $ =>
      seq(
        optional($.shebang),
        repeat(
          choice(
            $._expression
          ),
        ),
      ),

    shebang: $ => /#![^\n\r]*/,

    _expression: $ =>
      prec.left(choice($.id, $.nil, $.nilptr, $.boolean, $.number, $.string, $.type, $.binary_operations, $.unary_operations)),
      
    type: $ => seq("@", $.name),

    nil: $ => "nil",

    nilptr: $ => "nilptr",

    boolean: $ => choice("true", "false"),

    string: $ => choice($._string_short, $._string_long),
    _string_short: $ => {
      const content = field(
        "content",
        alias(prec(1, /[^\n'"]*/), $.string_content),
      );
      const double_quote = seq('"', content, '"');
      const single_quote = seq("'", content, "'");
      return token(choice(double_quote, single_quote));
    },
    _string_long: $ =>
      seq(
        $._block_start,
        field("content", alias($._block_content, $.string_content)),
        $._block_end,
      ),

    number: $ => choice($.hex_number, $.bin_number, $.dec_number),
    dec_number: $ =>
      seq(
        field("number", $.dec_prefix),
        optional(seq(/[eE]/, field("exponent", $.exp_digits))),
      ),
    hex_number: $ =>
      seq(
        "0",
        /[xX]/,
        field("number", $.hex_prefix),
        optional(seq(/[pP]/, field("exponent", $.exp_digits))),
      ),
    bin_number: $ =>
      seq(
        "0",
        /[bB]/,
        field("number", $.bin_prefix),
        optional(seq(/[pP]/, field("exponent", $.exp_digits))),
      ),
    dec_prefix: $ =>
      choice(
        prec.left(2, seq(/[0-9]+/, optional(seq(".", /[0-9]*/)))),
        prec.left(1, seq(".", /[0-9]+/)),
      ),
    hex_prefix: $ =>
      choice(
        prec.left(2, seq(/[0-9a-fA-F]+/, optional(seq(".", /[0-9a-fA-F]*/)))),
        prec.left(1, seq(".", /[0-9a-fA-F]+/)),
      ),
    bin_prefix: $ =>
      choice(
        prec.left(2, seq(/[01]+/, optional(seq(".", /[01]*/)))),
        prec.left(1, seq(".", /[01]+/)),
      ),
    exp_digits: $ => /[+-]?[0-9]+/,

    preprocess_expr: $ =>
      seq("#[", alias($._expression, $.preprocess_content), "]#"),
    preprocess_name: $ =>
      seq("#|", alias($._expression, $.preprocess_content), "|#"),

    binary_operations: $ =>
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

    unary_operations: $ =>
      prec.left(
        PREC.UNARY,
        seq(choice("not", "-", "#", "~", "&", "$"), $._expression),
      ),

    name: $ =>
      choice($.preprocess_name, /[_a-zA-Z][_a-zA-Z0-9]*/),
    id: $ => choice($.preprocess_expr, $.name),

    preprocess: $ =>
      choice(
        seq("##", field("content", alias(/[^\n\r]*/, $.preprocess_content))),
        seq(
          "##",
          $._block_start,
          field("content", alias($._block_content, $.preprocess_content)),
          $._block_end,
        ),
      ),

    comment: $ =>
      choice(
        seq("--", field("content", /[^\n\r]*/)),
        seq(
          "--",
          $._block_start,
          field("content", $._block_content),
          $._block_end,
        ),
      ),
  },
});
