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
    ~Node(){
       int value=this->data;
       if(this->next!=NULL){
           this->next=NULL;
           delete next;
           
       }
           cout<<"Memory is freed for node with data "<<value<<endl;
    }
};
void insertAtHead(Node*&head,int d){
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTail(Node*&tail,int d){
    Node*temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertAtPosition(Node*&head,Node*&tail,int position,int d){
    Node*temp=new Node(d);
    int count=1;
    Node*ptr=head;
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    
    while(count<position-1){
        ptr=ptr->next;
        count++;
    }
        temp->next=ptr->next;
    ptr->next=temp;
    if(temp->next==NULL){
        tail=temp;
    }
}
void deleteNode(int position,Node*&head,Node*&tail){
    if(position==1){
        Node*temp=head;
        head=head->next;
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
        prev->next=curr->next;
    if(curr->next==NULL){
        tail=prev;
    }
        delete curr;
    }

}
void printLL(Node*&head,Node*&tail){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;
}
int main() {
    Node*temp=new Node(5);
    Node*head=temp;
    Node*tail=temp;
    insertAtHead(head,10);
    insertAtHead(head,15);
    insertAtTail(tail,00);
    insertAtPosition(head,tail,3,25);
    insertAtPosition(head,tail,1,35);
    insertAtPosition(head,tail,7,45);
    deleteNode(6,head,tail);

    printLL(head,tail);
    return 0;
}