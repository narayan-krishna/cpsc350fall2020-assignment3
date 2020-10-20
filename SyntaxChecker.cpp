#include "SyntaxChecker.h"

void SyntaxChecker::processFile(){
  int numLine = 0;

  ifstream myfile (file);
  string line;
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      numLine += 1;
      for(int i = 0; i < line.length()-1; ++i){
        char current = line.at(i);
        if(current == '{' || current == '(' || current == '['){
          // cout << current << "--current" << endl;
          delims->push(current);
          // cout << delims->peek() << "--peek" << endl;
        }
        if(current == '}' || current == ')' || current == ']'){
          if(delims->isEmpty()){
            cout << "Found " << current << ", but didn't find matching " << match(current);
            cout << " earlier in the program" << endl;
            exit(EXIT_FAILURE);
          }
          if((current == '}' && delims->peek() != '{') || (current == ')' && delims->peek() != '(') || (current == ']' && delims->peek() != '[')){
            cout << "Line " << numLine << ": expected " << match(delims->peek()) << " and found " << current << endl;
            exit(EXIT_FAILURE);
          }else{
            delims->pop();
          }
        }
      }
    }
    myfile.close();
    if(!delims->isEmpty()){
      cout << "1" << endl;
      string missingDelims;
      while(!delims->isEmpty()){
        char topdelim = delims->pop();
        missingDelims += match(topdelim);
      }
      cout << "Reached end of file, missing the following delimiters: " << missingDelims;
      cout << endl;
    }
  }else{
    cout << 0 << endl;
  }
}

char SyntaxChecker::match(char curr){
  char match;
  if(curr == '}'){
    match = '{';
  }else if(curr == ')'){
    match = '(';
  }else if(curr == ']'){
    match = '[';
  }else if(curr == '{'){
    match = '}';
  }else if(curr == '('){
    match = '(';
  }else if(curr == '['){
    match = ']';
  }
  return match;
}

SyntaxChecker::SyntaxChecker(string fileName){
  file = fileName;
}

SyntaxChecker::~SyntaxChecker(){
  delete delims;
}

void SyntaxChecker::run(){
  delims = new GenStack<char>();

  processFile();
  // delims->printStack();
}
