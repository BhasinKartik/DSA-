#include<iostream>
using namespace std;
int main(){
int n=7;

int arr1[7]={3,4,61,82,84,85,87};
int arr2[8]={1,5,7,10,55,98,99,100};
int m=8;
int arr[15]={};
int k=15;
int i=0;
int j=0;
int x=0;
while((i<=n &&j<m) ||(j<=m &&i<n) ){
     if(j==m && i<n){
arr[x++]=arr1[i++];
continue;
    }
     if(i==n&& j<m){
arr[x++]=arr2[j++];
continue;
    }

    if(arr1[i]>=arr2[j]){
        arr[x++]=arr2[j++];

    }
    
    else if(arr1[i]<=arr2[j]){
        arr[x++]=arr1[i++];
    
    }
   
    if(x==k)break;
}
for(int y=0;y<k;y++){
    cout<<arr[y]<<" ";
}
return 0;
}