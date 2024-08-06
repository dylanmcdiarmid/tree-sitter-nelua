/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "nelua",

  externals: $ => [
    $._block_start,
    $._block_content,
    $._block_end
  ],

  extras: $ => [/[\n\r]/, /\s/, $.comment_short],

  rules: {
    // TODO: add the actual grammar rules
    source_file: $ =>
      seq(
        optional($.shebang),
        repeat(choice($.number, $.string, $.preprocess, $.preprocess_expr, $.preprocess_name)),
      ),

    shebang: $ => /#![^\n\r]*/,

    string: $ => choice($.string_short, $.string_long),
    string_short: $ => {
      const content = alias(prec(1, /[^\n'"]*/), $.string_content);
      const double_quote = seq('"', content, '"');
      const single_quote = seq("'", content, "'");
      return token(choice(double_quote, single_quote));
    },
    string_long: $ => seq($._block_start, alias($._block_content, $.string_content), $._block_end),

    number: $ => choice($.hex_number, $.bin_number, $.dec_number),
    dec_number: $ => seq($.dec_prefix, optional(seq(/[eE]/, $.exp_digits))),
    hex_number: $ =>
      seq("0", /[xX]/, $.hex_prefix, optional(seq(/[pP]/, $.exp_digits))),
    bin_number: $ =>
      seq("0", /[bB]/, $.bin_prefix, optional(seq(/[pP]/, $.exp_digits))),
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

    preprocess: $ => choice($.preprocess_short),
    preprocess_short: $ => seq("##", alias(/[^\n\r]*/, $.preprocess_content)),

    preprocess_expr: $ =>
      seq("#[", alias(/(?:[^\]][^#])*/, $.preprocess_content), "]#"),
    preprocess_name: $ =>
      seq("#|", alias(/(?:[^\|][^#])*/, $.preprocess_content), "|#"),

    comment_short: $ => seq("--", /[^\n\r]*/),
  },
});
