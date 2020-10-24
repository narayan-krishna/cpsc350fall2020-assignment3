//header file GenStack.h
#include <iostream>
using namespace std;

//creates a templatized stack
template <class T>
class GenStack{
  private:
    T *myArray;

  public:
    int top;
    int maxSize;

    //default constructor for a stack
    GenStack(){
      maxSize = 1;
      myArray = new T[maxSize];
      top = -1;
    }

    //contstruct a stack with a specified size
    GenStack(int mSize){
      maxSize = mSize;
      myArray = new T[maxSize];
      top = -1;
    }

    //destruct stack by deleting root array
    ~GenStack(){
      delete myArray;
    }//destructor

    //push an item onto the stack
    void push(T data){
      if(isFull()){
        // cout << "ERROR FULL STACK" << endl;
        // exit(EXIT_FAILURE);
        resize();
      }
      myArray[++top] = data;
    }

    //pop off the top stack, return it.
    T pop(){
      if(isEmpty()){
        cout << "ERROR EMTPY STACK" << endl;
        exit(EXIT_FAILURE);
      }
      return myArray[top--];
    }

    //return the peek of the stack without popping it off.
    T peek(){
      return myArray[top];
    }

    //return if stack is full
    bool isFull(){
      return(top == maxSize-1);
    }

    //return if stack is empty
    bool isEmpty(){
      return(top == -1);
    }

    //return the size of the stack (how many items are on the stack, not
    //the capacity)
    int getSize(){
      return top + 1;
    }

    // void printStack(){
    //   for(int i = 0; i < maxSize; ++i){
    //     cout << myArray[i];
    //   }
    //   cout << endl;
    // }

    //pop the entire stack to empty the stack and print get all contents
    void popStack(){
      while(!isEmpty()){
        cout << pop();
      }
      cout << endl;
    }

    //dynamically resizes the array upon reaching capacity.
    //array size is doubled in this specific iteration of the function
    void resize(){
      T *temp = new T[maxSize];
      for(int i = 0; i < maxSize; ++i){
        temp[i] = myArray[i];
      }
      delete myArray;
      myArray = new T[maxSize*2];
      for(int i = 0; i < maxSize; ++ i){
        myArray[i] = temp[i];
      }
      delete temp;
      maxSize = maxSize*2;
    }
};
