#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int s,int e){
    int pi=arr[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(arr[j]<pi){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

void helper(int arr[],int n,int s,int e){
    //base case
    if(s>=e) return;
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(arr, s, e);

    // recursive call on the left of pivot
    helper(arr,n,s,pi - 1);

    // recursive call on the right of pivot
    helper(arr,n,pi + 1,e);
}

void quickSort(int arr[],int n){
    int s=0;
    int e=n-1;
    helper(arr,n,s,e);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    quickSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}