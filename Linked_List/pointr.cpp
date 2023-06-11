// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    
};
void push(int data,Node*&head,Node*&top){
    if(head==NULL){
        head=new Node(data);
        top=head;
    }
    else{
    Node*temp=new Node(data);
    top->next=temp;
    top=temp;
    }
}
void pop(Node*&head,Node*&top){
    if(head==NULL){
        cout<<"stack empty"<<endl;
        return;
    }
    else if(head->next==NULL){
        head=NULL;
        top=NULL;
        return;
    }
    Node*temp=head;
    
   
    while(temp->next!=NULL){
        if(temp->next->next==NULL){
             Node*temp1=temp;
             temp1->next=NULL;
              top=temp1;
             
        }
         else temp=temp->next;
    }
    
   
}
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main() {
   Node*top=NULL; 
Node*head=NULL;
push(5,head,top);
push(6,head,top);
push(7,head,top);
push(8,head,top);
push(17,head,top);
pop(head,top);
pop(head,top);
pop(head,top);
// push(9,head,top);
pop(head,top);
pop(head,top);
push(17,head,top);
pop(head,top);
pop(head,top);
print(head);
    return 0;
}