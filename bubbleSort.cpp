#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
   for(int i=0;i<n;i++){
       //n-1 operations
       for(int j=0;j<=(n-i-1);j++){ //n-i-1 operations
           if(arr[j]>arr[j+1]){
               swap(arr[j],arr[j+1]);
           }
       }
   }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}