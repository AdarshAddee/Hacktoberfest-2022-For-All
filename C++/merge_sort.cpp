// Github username: heisenberg070
// Aim: Implementing the merge sort algorithm
// Date: 4 october 2022

#include <iostream>
using namespace std;

void merge(int arr[],int l,int mid,int r){
    int b[l+r+1];
    int i=l;
    int j=mid+1;
    int k=l;
    while(i<=mid && j<=r){
        if(arr[i]<arr[j]){
            b[k]=arr[i];
            i++;
            k++;
        }
        else{
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    if(i>mid){
        while(j<=r){
            b[k]=arr[j];
            k++;
            j++;
        }
    }
    else{
        while(i<=mid){
            b[k]=arr[i];
            i++;
            k++;
        }
    }
    for(int k=l;k<=r;k++){
        arr[k]=b[k];
    }

}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}