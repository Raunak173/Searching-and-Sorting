#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[],int n){
    //first we'll find the largest element in the array.
    int largest=INT_MIN;
    for(int i=0;i<n;i++){
        largest=max(largest,arr[i]);
    }
    //create a freq arr of size largest+1 and int each element with 0.
    vector <int> freq(largest+1,0);
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    //put elements back in array
    int j=0;
    for(int i=0;i<=largest;i++){
        while(freq[i]>0){
            arr[j]=i;
            freq[i]--;
            j++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    countingSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}