#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i=1;i<=n-1;i++){ //n-1 operations. loop starts from 1st index
        int e=arr[i]; //element to be compared
        int j=i-1;
        //To check for correct position of e
        while(j>=0 and arr[j]>e){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=e;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}