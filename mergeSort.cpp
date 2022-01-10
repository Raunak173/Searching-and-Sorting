#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int n,int s,int e){
    int mid=(s+e)/2;
    //Now we'll need to keep 3 pointers
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[n]; //temp array to store the sorted result
    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    //For remainng elements
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=e) temp[k++]=arr[j++];
    //Copy all elements back to array
    for(int i=s;i<=e;i++){
        arr[i]=temp[i];
    }

}

void helper(int arr[],int n,int s,int e){
    //base case
    if(s>=e) return;
    //Step 1 divide
    int mid=(s+e)/2;
    //step 2 recursive sort
    helper(arr,n,s,mid);
    helper(arr,n,mid+1,e);
    //step 3 merge 2 parts
    merge(arr,n,s,e);
}

void mergeSort(int arr[],int n){
    int s=0;
    int e=n-1;
    helper(arr,n,s,e);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}