//Doubly linked list implementation using template classes


#include<iostream>
using namespace std;

template<class T>
class Node{
  public:
  Node* prev;
  T data;
  Node* next;
  Node(Node* prev,T data,Node* next){
    this->next=next;
    this->data=data;
    this->prev=prev;
  }
};

template<class T>
class DoublyLL{
  public:
  Node<T> *head ,*tail;
  DoublyLL(){
      this->head=NULL;
      this->tail=NULL;
  }
  void insertBegin(T);
  void insertSpecified(T,int);
  void deleteBegin();
  void deleteSpecified(int);
  void displayForward();
  void displayBackward();
};

//INSERTION

template<class T>
void DoublyLL<T> :: insertBegin(T data){
    Node<T>* node=new Node<T>(NULL,data,NULL);
    if(this->head==NULL){
        this->head=this->tail=node;
    }
    else{
        node->next=this->head;
        this->head->prev=node;
        this->head=node;
    }
}

template<class T>
void DoublyLL<T> :: insertSpecified(T data,int position){
    Node<T>* node =new Node<T>(NULL,data,NULL);
    Node<T>* temp=this->head;
    --position;
    if(position==0){
        cout<<"Use insertBegin";
    }
    else{
         while(--position){
            temp=temp->next;
        }
        Node<T>* x=temp->next;
        temp->next=node;
        node->prev=temp;
        node->next=x;
        x->prev=node;
    }
}

//DELETION
template<class T>
void DoublyLL<T> :: deleteBegin(){
    if(this->head==NULL){
        cout<<"Nothing to delete";
    }
    else{
        Node<T>* temp=this->head;
        this->head=temp->next;
        this->head->prev=NULL;
        temp->next=NULL;
    }
}

template<class T>
void DoublyLL<T> :: deleteSpecified(int position){
    Node<T>* temp=this->head;
    --position;
    while(position--){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp->next=NULL;
    temp->prev=NULL;
}


//TRAVERSING
template<class T>
void DoublyLL<T> :: displayForward(){
    if(this->head==NULL){
        cout<<"Nothing to display";
    }
    Node<T>* temp=this->head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

template<class T>
void DoublyLL<T> :: displayBackward(){
    if(this->head==NULL){
        cout<<"Nothing to display";
    }
    Node<T>* temp=this->tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}

int main(){
    DoublyLL<char> d;
    d.insertBegin('a');
    d.insertBegin('b');
    d.insertBegin('c');
    d.insertSpecified('d',2);
    d.deleteSpecified(2);
    d.deleteSpecified(2);
    d.displayForward();
    d.displayBackward();
    return 0;
}