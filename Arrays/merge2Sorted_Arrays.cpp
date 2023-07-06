#include<iostream>
#include<vector>
using namespace std;
// MERGE TWO SORTED ARRAYS
void merge(vector<int>&v,vector<int>& nums1, vector<int>& nums2){
     int m=nums1.size();
     int n=nums2.size();
int i=0;
int j=0;
int index=0;
while(i<m && j<n){
    if(nums1[i]<=nums2[j])v[index++]=nums1[i++];
    else if(nums1[i]>nums2[j])v[index++]=nums2[j++];
}
while(i<m)v[index++]=nums1[i++];
while(j<n)v[index++]=nums2[j++];
 }
 // Leetcode
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int m=nums1.size();
     int n=nums2.size();
        vector<int>ans(m+n,-1);
        merge(ans,nums1,nums2);
double median=-1;
        if((m+n)&1)median=ans[(m+n)/2];
        else median=(ans[(m+n)/2]+ans[(m+n)/2-1])/2.0;
        return median;
    }
int main(){
int n=15;
int arr1[7]={3,4,61,82,84,85,87};
int arr2[8]={1,5,7,10,55,98,99,100};

return 0;
}