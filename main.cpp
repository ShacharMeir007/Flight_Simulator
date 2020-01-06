#include <iostream>
#include "Lexer.h"
int main(int argc, char* argv[]) {
  Lexer lexer(argv[1]);
  lexer.lex();
  return 0;
}
