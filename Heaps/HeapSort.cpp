#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n &&arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n &&arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void HeapSort(int arr[],int size){
    while(size>1){
swap(arr[size],arr[1]);
size--;

heapify(arr,size,1);
    }
}
int main(){
int arr[7]={-1,13,16,10,2,19,5};
int size=6;
int n=6;
//Heap Creation
for(int i=n/2;i>0;i--){
heapify(arr,n,i);
}
HeapSort(arr,size);
//Sorted array:
for(int i=1;i<=size;i++){
cout<<arr[i]<<" ";
}cout<<endl;

return 0;
}