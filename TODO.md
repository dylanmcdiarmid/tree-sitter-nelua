# TODO
- [ ] Port nelua-lang tests
  - `spec/syntaxdef_spec.lua`
  - Change things up where it makes sense
  - We'll match the AST that is currently being generated for now, with the understanding that we may want to change it later when writing queries.
- [ ] Fix `-- [[` parsing as long instead of short comments
- [x] Change README to have brief setup instructions
- [ ] Write tests for long comments inside of double quoted strings (they should be parsed as strings, not long comments)
