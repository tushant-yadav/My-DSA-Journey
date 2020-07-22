#include <iostream>
#include<algorithm>
using namespace std;
bool checktriplet(int arr[],int n,int target){
    //initizalization
    int start=0,end=n-1,mid=start+1;
    //looping
    while(start<end){
        int sum=arr[start]+arr[end]+arr[mid];
        //ans
        if(sum==target){
            return true;}
        // to  make sure mid dont exceed end index
        if(mid<end){
            if(sum<target){
                mid++;}
            if(sum>target){
                end--;}
        //if mid reaches to end        
        if(mid==end){
            start++;
            mid=start+1;}
        }
    }
    // when couldnt find any true condition
    return false;
}    
int main() {
    int n,arr[1000],target;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>target;
    sort(arr,arr+n);
    cout<<checktriplet(arr,n,target);
    return 0;
}
