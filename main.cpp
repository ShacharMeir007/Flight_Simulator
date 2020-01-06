#include "Lexer.h"
int main(int argc, char* argv[]) {
  if (argc != 2){
    return 1;
  }
  Lexer lexer(argv[1]);
  lexer.lex();
  return 0;
}
