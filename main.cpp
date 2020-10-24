#include "SyntaxChecker.h"

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
