#include <iostream>
using namespace std;
int swarp(int &a, int &b){ 
    int temp=a;
    a=b;
    b=temp;
    return 0;
}

int bubblesort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            } 
        }   
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


int main() {
    int n,arr[1000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubblesort(arr,n);
    return 0;
}
