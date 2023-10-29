// Exercise 1-3. Spot the errors. 
// The correct version should closely resemble the answer to Exercise 1.1.

#import std                        // The # character is not allowed for import directives,
                                   // and a missing semicolon at the end of the line.
Int main                           // Should be int, not Int. main() needs parentheses.
{                                  // There's no closing curly brace, but a parenthesis instead.
  std:printn("Holla Mundo!")       // A semicolon is missing from the end of this line as well,
)                                  // the correct function name is println() ("print line"),
                                   // the correct syntax for the namespace prefix is std:: (two colons),
                                   // and the correct spelling of Hello in Spanish is Hola.