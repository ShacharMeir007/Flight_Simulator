#include "Lexer.h"
#include "Parser.h"
#include "SharedData.h"
int main(int argc, char* argv[]) {
  if (argc != 2){
    return 1;
  }
  SharedData* shared_data = new SharedData();
  Lexer lexer(argv[1]);
  std::vector<std::string> commands = lexer.lex();
  Parser parser = Parser(shared_data);
  try {
    parser.parse(&commands);
    //Parser::shared_data_.safe_getVarsLeftBind();
  } catch (char const* exception){
    std::cout<<exception<<std::endl;
    return 1;
  }

  return 0;
}

