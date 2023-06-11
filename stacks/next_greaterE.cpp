#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long>ans;
        stack<long long>st;
        for(int i=n-1;i>=0;i--){
          if(st.empty()){
              ans[i]=-1;
            st.push(arr[i]);
            continue;
              
          }
            while(!st.empty()&&st.top()<=arr[i] ){
                
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
                st.push(arr[i]);
            }
            else
            {
                ans[i]=-1;
                st.push(arr[i]);
            }
        }
        for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
}
        return ans;
    }
int main(){
vector<long long>arr;
int n=4;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
vector<long long>ans;

ans=nextLargerElement(arr,n);
for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
}
return 0;
}