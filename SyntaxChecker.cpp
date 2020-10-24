#include "SyntaxChecker.h"

//run through the file and look for an error
//counts the line so that when an error is found, the line number
//of that error can be sent to the user.
void SyntaxChecker::processFile(){
  int numLine = 0;

  //open the file
  ifstream myfile (file);
  string line;
  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      numLine += 1;
      for(int i = 0; i < line.length()-1; ++i){
        char current = line.at(i);
        //push opening delimiters to the stack
        if(current == '{' || current == '(' || current == '['){
          // cout << current << "--current" << endl;
          delims->push(current);
          // cout << delims->peek() << "--peek" << endl;
        }
        //upon closing delimiter, check the stack for match delimiter
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
    //if there are delimiters that haven't been matched, show what they are
    if(!delims->isEmpty()){
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


//a simple function that returns an input delimiter to its match. meant to
//limit the amount of if statements needed in the process function.
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

//Constructor
SyntaxChecker::SyntaxChecker(string fileName){
  file = fileName;
}

//Destructor
SyntaxChecker::~SyntaxChecker(){
  delete delims;
}

//run the syntax checker
void SyntaxChecker::run(){
  delims = new GenStack<char>();

  processFile();
}
