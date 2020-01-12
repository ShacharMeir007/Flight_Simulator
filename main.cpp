#include "Lexer.h"
#include "Parser.h"
#include "SharedData.h"
int main(int argc, char* argv[]) {
  //checking that the amount of arguments
  //is suitable
  if (argc != 2){
    return 1;
  }
  //creates shared data for the rest of the program
  SharedData* shared_data = new SharedData();
  //creates lexer and uses lex on file
  Lexer lexer(argv[1]);
  std::vector<std::string> commands = lexer.lex();
  //creates parser and trying to parse
  Parser parser = Parser(shared_data);
  try {
    parser.parse(&commands);
  } catch (char const* exception){
    std::cout<<exception<<std::endl;
    return 1;
  }
  //notifies intent to end the program
  shared_data->setTerminate();
  //waits until other threads terminate
  while (!shared_data->checkTerminated()){}
  return 0;
}

