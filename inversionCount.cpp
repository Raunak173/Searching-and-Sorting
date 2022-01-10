#include <bits/stdc++.h>
using namespace std;

int merge(int arr[],int n,int s,int e){
    int mid=(s+e)/2;
    //Now we'll need to keep 3 pointers
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[n]; //temp array to store the sorted result
    int cnt=0; //count inv.
    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            cnt+=mid-i+1; //The main crux of the pb
        }
    }
    //For remainng elements
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=e) temp[k++]=arr[j++];
    //Copy all elements back to array
    for(int i=s;i<=e;i++){
        arr[i]=temp[i];
    }
    return cnt;
}

int helper(int arr[],int n,int s,int e){
    //base case
    if(s>=e) return 0;
    //Step 1 divide
    int mid=(s+e)/2;
    //step 2 recursive count
    int x=helper(arr,n,s,mid);
    int y=helper(arr,n,mid+1,e);
    int z=merge(arr,n,s,e); //Cross inv.
    return (x+y+z);
}

int invCount(int arr[],int n){
    int s=0;
    int e=n-1;
    return helper(arr,n,s,e);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<invCount(arr,n);
    return 0;
}