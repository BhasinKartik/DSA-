#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int d){
this->data=d;
this->left=NULL;
this->right=NULL;
    }
};
Node* buildTree(Node*root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    if(data==-1){       
        return NULL;
    }
    root=new Node(data);   
 cout<<"Enter data for inserting to the left of "<<data<<endl;
 root->left=buildTree(root->left);
 cout<<"Enter data for inserting to the right of "<<data<<endl;
 root->right=buildTree(root->right);
return root;
}


void inOrder(Node*root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void PreOrder(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void PostOrder(Node*root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);

    cout<<root->data<<" ";
}
int main(){
 Node*root=NULL; 
 root=buildTree(root);
 cout<<"Printing the levelOrderTraversal output "<<endl;
 levelOrderTraversal(root);
 

return 0;
}
//8 4 3 -1 -1 5 -1 6 -1 15 10 -1 -1 16 -1 -1
