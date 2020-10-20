//header file GenStack.h
#include <iostream>
using namespace std;

template <class T>
class GenStack{
  private:
    T *myArray;

  public:
    int top;
    int maxSize;

    GenStack(){
      maxSize = 1;
      myArray = new T[maxSize];
      top = -1;
    }

    GenStack(int mSize){
      maxSize = mSize;
      myArray = new T[maxSize];
      top = -1;
    }

    ~GenStack(){
      delete myArray;
    }//destructor

    void push(T data){
      if(isFull()){
        // cout << "ERROR FULL STACK" << endl;
        // exit(EXIT_FAILURE);
        resize();
      
      myArray[++top] = data;
    }

    T pop(){
      if(isEmpty()){
        cout << "ERROR EMTPY STACK" << endl;
        exit(EXIT_FAILURE);
      }
      return myArray[top--];
    }

    T peek(){
      return myArray[top];
    }

    bool isFull(){
      return(top == maxSize-1);
    } //ERROR HERE

    bool isEmpty(){
      return(top == -1);
    }

    int getSize(){
      return top + 1;
    }

    void printStack(){
      for(int i = 0; i < maxSize; ++i){
        cout << myArray[i];
      }
      cout << endl;
    }

    void popStack(){
      while(!isEmpty()){
        cout << pop();
      }
      cout << endl;
    }

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
