#include "SyntaxChecker.h"

//main -- takes a command line argument for the file. if there are too many
//or not enough arguments, code will throw an error/example input for user
int main(int argc, char **argv){
  if(argc != 2){
    cout << "command line requires a file input" << endl;
    cout << "example: " << endl;
    cout << "'./assignment3.exe main.cpp'" << endl;
  }
  else{
    SyntaxChecker *checker1 = new SyntaxChecker(argv[1]);
    checker1->run();
  }
  return 0;
}
