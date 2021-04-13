//Queue implementation using template classes and linked list


#include<iostream>
using namespace std;

template<class T>
class Node{
  public:
  T data;
  Node* next;
  Node(T data,Node* next){
    this->data=data;
    this->next=next;
  }
};

template<class T>
class Queue{
  public:
  Node<T> *front,*rear;
  Queue(){
    this->front=NULL;
    this->rear=NULL;
  }
  bool isEmpty();
  void enqueue(T);
  T dequeue();
  void traverse();
};

template<class T>
bool Queue<T> :: isEmpty(){
    return this->front==NULL && this->rear==NULL ;
}

template<class T>
void Queue<T> :: enqueue(T data){
    Node<T>* node=new Node<T>(data,NULL);
    if(isEmpty()){
        this->front=this->rear=node;
    }
    else{
        Node<T>* temp=this->rear;
        temp->next=node;
        this->rear=node;
    }
}

template<class T>
T Queue<T> :: dequeue(){
    T temp;
    if(isEmpty()){
        cout<<"Underflow";
    }
    else{
        temp=this->front->data;
       if(this->rear==this->front){
           this->rear=this->front=NULL;
       }
       else{
            Node<T>* temp=this->front;
            this->front=temp->next;
            temp->next=NULL;
       }
    }
    return temp;
}

template<class T>
void Queue<T> :: traverse(){
    Node<T>* temp=this->front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Queue<char> a;
    a.enqueue('a');
    a.enqueue('b');
    a.enqueue('c');
    a.dequeue();
    a.traverse();
    return 0;
}
