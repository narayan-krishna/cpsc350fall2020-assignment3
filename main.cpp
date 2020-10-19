#include "GenStack.h"

int main(int argc, char **argv){
  GenStack<char> *stack = new GenStack<char>();
  // cout << stack->top << endl;
  // cout << stack->maxSize << endl;
  // stack->push('h');
  // stack->push('o');
  // stack->push('o');
  // cout << stack->pop() << endl;
  // cout << stack->pop() << endl;
  // cout << stack->pop() << endl;
  stack->push('h');
  cout << stack->maxSize << endl;
  stack->push('e');
  cout << stack->maxSize << endl;
  stack->push('l');
  cout << stack->maxSize << endl;
  stack->push('1');
  cout << stack->maxSize << endl;
  stack->push('0');
  cout << stack->maxSize << endl;
  // stack->push('l');
  // stack->push('1');
  // stack->push('0');
  // cout << stack->pop() << endl;
  stack->printStack();
}
