//Array implementation of Stack  using template classes


#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
class Stack{
  public:
  int top,size;
  T *stack;
  Stack(int size){
    this->top=-1;
    this->size=size;
    this->stack=new T[size];
  }
  bool isEmpty();
  bool isFull();
  void push(T);
  T pop();
  T peek();
  void traverse();
};

template<class T>
bool Stack<T>:: isEmpty(){
   return this->top==-1;
}

template<class T>
bool Stack<T>:: isFull(){
    return this->top+1==this->size;
}

template<class T>
void Stack<T> :: push(T data){
    if(isFull()){
        cout<<"overflow";
    }
    else{
        this->top++;
        this->stack[this->top]=data;
    }
}

template<class T>
T Stack<T>::pop(){
    if(isEmpty()){
        cout<<"nothing to pop";
        exit(EXIT_FAILURE);
    }
    else{
        T temp=this->stack[this->top];
        this->top--;
        return temp;
    }
}
template<class T>
T Stack<T>::peek(){
    if(isEmpty()){
        cout<<"nothing to pop";
        exit(EXIT_FAILURE);
    }
    else{
        return  stack[this->top];
    }
}
template<class T>
void Stack<T>:: traverse(){
    for(int i=top;i>=0;i--){
        cout<<" "<<this->stack[i]<<" ";
    }
}

int main(){
    Stack<char>s(50);
}
