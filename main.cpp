#include "Lexer.h"
#include "Parser.h"
int main(int argc, char* argv[]) {
  if (argc != 2){
    return 1;
  }
  Lexer lexer(argv[1]);
  std::vector<std::string> commands = lexer.lex();
  Parser parser = Parser(&commands);
  try {
    parser.parse();
  } catch (char const* exception){
    std::cout<<exception<<std::endl;
    return 1;
  }

  return 0;
}
