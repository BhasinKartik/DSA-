#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

    int partition (int* arr, int low, int high)
    {
       int i=low;
       int j=high;
       int pivot=arr[low];
       while(i<j){
           
           while(arr[i]<=pivot && i<high)i++;
           
           while(arr[j]>pivot && j>low)j--;
           if(i<j)swap(arr[i],arr[j]);
       }
       swap(arr[low],arr[j]);
       return j;
    }

    //Function to sort an array using quick sort algorithm.
    void quickSort(int*arr, int low, int high)
    {
        if(low<high){
            int p=partition(arr,low,high);
            quickSort(arr,low,p-1);
            quickSort(arr,p+1,high);
        }
    }
    
    

int main(){
    int n=8;
int arr[]={5,56,34,12,7,3,76,90};
quickSort(arr,0,n-1);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
return 0;
}