//Array implementation of Queue  using template classes

#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
class Queue{
  public:
  int front,rear,size;
  T *queue;
  Queue(int size){
    this->front=0;
    this->rear=-1;
    this->size=size;
    this->queue=new T[size];
  }
  bool isEmpty();
  bool isFull();
  void enqueue(T);
  T dequeue();
  T peek();
  void traverse();
};

template<class T>
bool Queue<T>:: isEmpty(){
    return (this->front==0 && this->rear==-1) || (this->front > this->rear);
}

template<class T>
bool Queue<T>:: isFull(){
    return this->rear+1==this->size;
}

template<class T>
void Queue<T>:: enqueue(T data){
    if(isFull()){
        cout<<"Full";
    }
    else{
        this->rear++;
        this->queue[this->rear]=data;
    }
}

template<class T>
T Queue<T>:: dequeue(){
    if(isEmpty()){
        cout<<"empty";
    }
    else{
        T temp=this->queue[this->front];
        if(this->rear==this->front){
            this->rear=-1;
            this->front=0;
        }
        else{
            this->front++;        
        }
        return temp;
    }
}

// template<class T>
// T Queue<T>::peek(){
//     return isEmpty() ? -1 : this->queue[this->front];
// }

template<class T>
void Queue<T>:: traverse(){
    for(int i=this->front;i<=this->rear;i++){
        cout<<this->queue[i]<<" ";
    }
}

int main(){
    Queue<int> q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    return 0;
}