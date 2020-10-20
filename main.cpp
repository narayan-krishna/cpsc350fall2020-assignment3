#include "SyntaxChecker.h"

int main(int argc, char **argv){
  // GenStack<char> *stack = new GenStack<char>();
  // stack->push('h');
  // cout << stack->top << endl;
  // stack->push('e');
  // cout << stack->top << endl;
  // stack->push('l');
  // cout << stack->top << endl;
  // stack->push('1');
  // cout << stack->top << endl;
  // stack->push('0');
  // cout << stack->top << endl;
  // stack->printStack();
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
