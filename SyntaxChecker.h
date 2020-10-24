#include <iostream>
#include <fstream>
#include "GenStack.h"
#include <string>
using namespace std;

//creates a syntax checker -- checks for non-matching delmiters in a given
//script. if the specific mismatched delmiter can be found, the code will
//returna  location.
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
