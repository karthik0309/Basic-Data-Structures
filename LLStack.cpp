//Stack implementation using template classes and linked list


#include<iostream>
using namespace std;

template<class T>
class Node{
  public:
  T data;
  Node* next;
  Node(T data,Node* next){
      this->next=next;
      this->data=data;
  }
};

template<class T>
class Stack{
  public:
  Node<T>* head;
  Stack(){
      this->head=NULL;
  }
  bool isEmpty();
  void push(T);
  T pop();
  T peek();
  void traverse();
  
};

template<class T>
bool Stack<T> :: isEmpty(){
      return this->head==NULL;
}
  
template<class T>
void Stack<T> :: push(T data){
    Node<T>* node=new Node<T>(data,NULL);
    if(this->head==NULL){
        this->head=node;
    }
    else{
        node->next=this->head;
        this->head=node;
    }
}

template<class T>
T Stack<T> :: pop(){
    T temp;
    if(isEmpty()){
        cout<<"Underflow";
    }
    else{
        temp=this->head->data;
        Node<T>* a=this->head->next;
        this->head->next=NULL;
        this->head=a;
    }
    return temp;
}

template<class T>
T Stack<T> :: peek(){
    T temp;
    if(isEmpty()){
        cout<<"Underflow";
    }
    else{
        temp=this->head->data;
    }
    return temp;
}

template<class T>
void Stack<T> :: traverse(){
    Node<T>* temp=this->head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Stack<string> s;
    s.push("karthik");
    s.push("arjun");
    s.push("varun");
    s.pop();
    s.pop();
    s.traverse();
    return 0;
}