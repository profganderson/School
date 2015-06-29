# Class 4 - June 29
#### Topics
* Table Driven Parsing
* Recursive Descent Parsers
* Project 2 Notes (Parser)

#### Class Example

Build a parse table for the following grammar.

```
S -> if E then S
S -> E = E
E -> number | ident
```

Table
```
         if          then       =        number      ident
S   if E then S                           E=E         E=E     
E                                        number      ident
```

| _ | if          | then | = | number | ident |
| - | ----------- | ---- | - | ------ | ----- |
| S | if E then S | ____ | _ | E = E  | E = E |
| E | ___________ | ____ | _ | number | ident |