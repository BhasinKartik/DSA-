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


Node* insertIntoBST(Node*&root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
if(d>root->data){
    root->right=insertIntoBST(root->right,d);
}
else{
    root->left=insertIntoBST(root->left,d);
}
return root;
}
void takeInput(Node*&root){
    int data;
    cin>>data;
    while(data!=-1){
    insertIntoBST(root,data);    
    cin>>data;
    }
}
void levelOrderTraversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
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
cout<<"Enter data to create BST "<<endl;
takeInput(root);
cout<<"Printing the BST "<<endl;
levelOrderTraversal(root);
cout<<"InOrder:"<<endl;
 inOrder(root);
 cout<<endl;
 cout<<"PreOrder:"<<endl;
 PreOrder(root);
 cout<<endl;

 cout<<"PostOrder:"<<endl;
 PostOrder(root);
 cout<<endl;
return 0;
}