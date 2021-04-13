#include<iostream>
#include <queue> 
using namespace std;

template<class T>
class Node{
    public:
    Node* left;
    T data;
    Node* right;
    Node(Node* left,T data,Node*right){
        this->left=left;
        this->data=data;
        this->right=right;
    }
};

template<class T>
class Bst{
    public:
    Node<T>* root;
    Bst(){
        this->root=NULL;
    }
    void insert(T);
    int lookUp(T,Node<T>*&,Node<T>*&);
    void deleteEle(T);
    void inOrder(Node<T>*);
    void preOrder(Node<T>*);
    void postOrder(Node<T>*);
    int levelOrder(Node<T>*);
    Node<T>* getRoot();
    Node<T>* getMinimum(Node<T>*);
    Node<T>* getMaximum(Node<T>*);
};

//insertion
template<class T>
void Bst<T> :: insert(T data){
    Node<T>* node=new Node<T>(NULL,data,NULL);
    if(this->root==NULL){
        this->root=node;
    }
    else{
        Node<T>* currNode=this->root;
        while(true){
            if(data < currNode->data){
                if(!currNode->left){
                    currNode->left=node;
                    break;
                }
                currNode=currNode->left;
            }
            else if(data > currNode->data){
                if(!currNode->right){
                    currNode->right=node;
                    break;
                }
                currNode=currNode->right;
            }
            else{
                cout<<"You are trying to add duplicate ele"<<"\n";
                break;
            }
        }
    }
}

//search
template<class T>
int Bst<T> :: lookUp(T data,Node<T>* &currNode,Node<T>* &parent){
    currNode=parent=this->root;
    while(currNode!=NULL){
        if(data < currNode->data){
            parent=currNode;
            currNode=currNode->left;
        }
        else if(data > currNode->data){
            parent=currNode;
            currNode=currNode->right;           
        }
        else{
            return 1;
        }
    }
    return 0;
}

//Minimun key for successor
template<class T>
Node<T>* Bst<T> :: getMinimum(Node<T>* currNode){
    while(currNode->left!=NULL){
        currNode=currNode->left;
    }
    return currNode;
}
template<class T>
Node<T>* Bst<T> :: getMaximum(Node<T>* currNode){
    while(currNode->right){
        currNode=currNode->right;
    }
    return currNode;
}

//Deletion
template<class T>
void Bst<T> :: deleteEle(T data){
    Node<T> *currNode,*parent;
    parent=currNode=this->root;
    lookUp(data,currNode,parent);
    
    //No child (leaf Node)
    if(!currNode->left && !currNode->right){
        if(parent->left==currNode){
            parent->left=NULL;
        }
        else{
            parent->right=NULL;
        }
        free(currNode);
        return;
    }
    
    //Two children
    else if(currNode->left && currNode->right){
        
       /*using predecessor
        Node<T>* predecessor=getMaximum(currNode->left);
        int val=predecessor->data;
        deleteEle(predecessor->data);
        currNode->data=val;
        */
        Node<T>* successor=getMinimum(currNode->right);
        int val=successor->data;
        deleteEle(successor->data);
        currNode->data=val;
    }
    
    //One Child
    else{
        Node<T>* child=currNode->left ? currNode->left :
        currNode->right;
        if(parent->left->data=data){
            parent->left=child;
        }
        else{
            parent->right=child;
        }
        free(currNode);
        return;
    }
}

//Traversal
template<class T>
void Bst<T> :: inOrder(Node<T>* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

template<class T>
void Bst<T> :: preOrder(Node<T>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

template<class T>
void Bst<T> :: postOrder(Node<T>* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

template<class T>
int Bst<T> :: levelOrder(Node<T>* root){
    if(root==NULL){
        return -1;
    }
    queue<Node<T>*>q;
    int height=0;
    q.push(root);
    while(true){
        int size=q.size();
        if(size==0){
            break;
        }
        while(size>0){
            Node<T>* temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            else if(temp->right){
                q.push(temp->right);
            }
            size--;
        }
        height=height+1;
    }
    return height-1;
}

//Root node
template<class T>
Node<T>* Bst<T> :: getRoot(){
    return this->root;
}

int main(){
    Bst<int> b;
    b.insert(10);
    b.insert(20);
    b.insert(5);
    b.insert(8);
    b.insert(15);
    b.insert(16);
    b.insert(30);
    b.deleteEle(20);
    b.inOrder(b.getRoot());
    cout<<"\nHeight: "<<b.levelOrder(b.getRoot());
    return 0;
}