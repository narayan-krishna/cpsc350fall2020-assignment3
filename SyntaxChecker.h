#include <iostream>
#include <fstream>
#include "GenStack.h"
#include <string>
using namespace std;

class SyntaxChecker{

  private:
    string file;
    GenStack<char> *delims;

    void processFile();
    char match(char curr);

  public:
    SyntaxChecker(string fileName);
    ~SyntaxChecker();
    void run();
};
