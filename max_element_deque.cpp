#include <iostream>
#include<deque>
using namespace std;

void max_window(int arr[],int k,int n){
    deque<int> window(k);
    int i=0;
    while(i<k){
        if(!window.empty() && arr[window.back()]<arr[i]) window.pop_back();
        window.push_back(i);
        i++;
    }
    while(i<n){
        while(!window.empty() && arr[window.front()]<=i-k) window.pop_front();
        while(!window.empty() && arr[window.back()]<=arr[i]) window.pop_back();
        window.push_back(i);
        i++;
        cout<<arr[window.front()];

    }
    return ;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;
    max_window(arr,k,n);
    return 0;
}
