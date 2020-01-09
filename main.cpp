#include "Lexer.h"
#include "Parser.h"
int main(int argc, char* argv[]) {
  if (argc != 2){
    return 1;
  }
  Lexer lexer(argv[1]);
  lexer.lex();
  Parser parser;
  parser.parse();
  return 0;
}
