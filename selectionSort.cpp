#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){ //Loop will run only till 1 element is left in the unsorted part.
        //find out the smallest index element in the unsorted part
        int min_idx=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        //After this loop we can finally swap
        swap(arr[i],arr[min_idx]);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}