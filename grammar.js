
/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: 'nelua',

  extras: $ => [
  /[\n]/, /\s/
],

  rules: {
    // TODO: add the actual grammar rules
    source_file: $ => $.number,
    
    string: $ => choice($.string_short),
    string_short: $ => {
      const content = alias(prec(1, /[^'"]*/), $.string_content)
      const double_quote = seq('"', content, '"')
      const single_quote = seq("'", content, "'")
      return token(choice(double_quote, single_quote))
    },

    number: $ => choice($.dec_number),
    dec_number: $ => seq($.dec_prefix, optional(seq(/[eE]/, $.exp_digits))),
    dec_prefix: $ => choice(
      seq(
        /[0-9]+/,
        optional(seq(
          '.', repeat(/[0-9]/)
        ))
      ),
      seq(
        '.', repeat1(/[0-9]/)
      )
    ),
    exp_digits: $ => /[+-]?[0-9]+/
  }
});
