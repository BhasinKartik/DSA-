#include<iostream>
#include<stack>
using namespace std;
int deletedElement;
void solve(stack<int>&s,int count,int N){
if(count==N/2){
     deletedElement=s.top();
    s.pop();
    return;
}
int top=s.top();
s.pop();
solve(s,count+1,N);
s.push(top);

}
void deleteMiddle(stack<int>&s, int N){
	
	int count=0;
   solve(s,count,N);
  

   
}
int main(){
stack<int>s;
s.push(4);
s.push(7);
s.push(13);
s.push(40);
s.push(14);
int size=5;
while(!s.empty()){
    int top=s.top();
    s.pop();
    
    cout<<top<<" ";
}
cout<<endl;
cout<<size<<endl;
deleteMiddle(s,size);
 cout<<"deleted element="<<deletedElement<<endl;
   while(!s.empty()){
    int top=s.top();
    s.pop();
    
    cout<<top<<" ";
   }
return 0;
}