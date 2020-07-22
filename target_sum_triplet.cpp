#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n,arr[1000],target;
	cin>>n;
	for(int i ;i<n;i++){
		cin>>arr[i];
	}
	cin>>target;
	sort(arr,arr+n);

	for(int i=0;i<n;i++){
		int j=i+1,k=n-1;
			while(j<k){
			if(arr[i]+arr[j]+arr[k] == target)
				{cout<<arr[i]<<", "<<arr[j]<<" and "<<arr[k]<<endl;
				j++;}
			else if((arr[i]+arr[j]+arr[k])>target){
				k--;}	
			else
			{j++;}
			}}
	return 0;
}