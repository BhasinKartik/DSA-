#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
Node(int d){
    this->data=d;
    this->next=NULL;
}
~Node(){
    int val=this->data;
    if(this->next!=NULL){
        next=NULL;
        delete next;
    }
        cout<<"Memory freed for node with data="<<val<<endl;

}
};
void insertNode(int node,int d,Node*&tail){
if(tail==NULL){
    Node*newNode=new Node(d);
    tail=newNode;
    newNode->next=newNode;
}
else{
Node*temp=tail;
    while(temp->data!=node){
        temp=temp->next;
    }
   Node*curr=new Node(d);
   curr->next=temp->next;
   temp->next=curr;
}
}
void print(Node*tail){
    Node*temp=tail;
    if(tail==NULL){
        cout<<"List empty"<<endl;
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail!=temp);
    cout<<endl;
}
void deleteNode(int element,Node*&tail){
    Node*prev=tail;
    Node*curr=prev->next; 
     if(curr==prev){
        tail=NULL;
    }
    while(curr->data!=element){
        prev=curr;
        curr=curr->next;
    }
   
    if(curr==tail){
        tail=prev;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;

}
int main(){
Node*tail=NULL;
insertNode(3,5,tail);

insertNode(5,6,tail);
// insertNode(5,7,tail);
// insertNode(7,9,tail);
deleteNode(5,tail);
print(tail);
return 0;
}