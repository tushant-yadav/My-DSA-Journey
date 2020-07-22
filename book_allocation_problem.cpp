#include <iostream>
#include<climits>
using namespace std;

bool isitpossible(int arr[],int m,int n,int mid){
      // cout<<"came func pos pagess "<<mid<<" mid "<<endl;

    int i=0,students=0,pages=0;
    while(i<m){
        
        if(pages+arr[i]<=mid){
            pages+=arr[i];
        }
        else{
            students++;
            pages=arr[i];
        }   
        //cout<<pages<<" pages "<<i<<" i "<<students<<" student"<< endl;
            
        if(students>=n){
            //cout<<"returning false"<<endl;
            return false;
        }
        i++;

    }
    //cout<<"returning true"<<endl;
    return true;
}    

int maxpages(int arr[],int m,int n){
    //cout<<"came func max pagess";
    if(m<n){
        return false;
    }
    int end=0;
    int start=arr[m-1];
    int ans=INT_MAX;
    for (int i=0;i<m;i++){
        end+=arr[i];
    }
    //cout<<end<<endl;
    while(start<=end){
    int mid=(start+end)/2;
        if(isitpossible(arr,m,n,mid)){
            end=mid-1;
            //cout<<ans<<endl;
            ans=min(ans,mid); 
           // cout<<ans<<" ans max func"<<endl;       
        }
        else{
            start=mid+1;
        }
    }
    return ans;

}
int main() {
    int t,m,n,arr[1000];
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>m>>n;
        for(int j=0;j<m;j++){
            cin>>arr[j];
        }
        int ans=maxpages(arr,m,n);
        cout<<ans;
    }
    return 0;
}
