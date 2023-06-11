// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            next=NULL;
            delete next;
        }
        cout<<"Memory freed for node with data="<<val<<endl;
        
    }
};
void insertAtHead(Node*&head,int d){
    Node*temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAtTail(Node*&tail,int d){
    Node*temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertAtPosition(Node*&head,Node*&tail,int position,int d){
    Node*temp=new Node(d);
    Node*ptr=head;
    int cnt=1;
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    
    while(cnt<position-1){
        ptr=ptr->next;
        cnt++;
    }
    if(ptr->next==NULL){
        insertAtTail(tail,d);
        return;
    }
    ptr->next->prev=temp;
    temp->prev=ptr;
     temp->next=ptr->next;
    ptr->next=temp;

   

}
void deleteNode(int position,Node*&head,Node*&tail){
    if(position==1){
        Node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node*prev=NULL;
        Node*curr=head;
        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
        if(curr->next==NULL){
            tail=prev;
        }
        prev->next=curr->next;
curr->next=NULL;
curr->prev=NULL;

delete curr;
    }

}
void printLL(Node*&head,Node*&tail){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
    cout<<"head->"<<head->data<<endl;
    cout<<"tail->"<<tail->data<<endl;
}
int main() {
    Node*temp=new Node(5);
    Node*head=temp;
    Node*tail=temp;
    insertAtHead(head,8);
    insertAtTail(tail,9);
    insertAtHead(head,6);
    insertAtPosition(head,tail,1,11);
        insertAtPosition(head,tail,3,13);
        deleteNode(6,head,tail);
printLL(head,tail);
    return 0;
}