#include<iostream>
#include<stack>
using namespace std;

void max_area(int arr[],int n){
	stack<int> s;
	int area=0,max_area_so_far=0;
	for(int i=0;i<n;i++){
		if(arr[s.top]<=arr[i] ||s.empty()) 
			s.push(i);
		else{
			while(arr[s.top()]>arr[i]){
				int a=s.top()
				s.pop();
				int l=s.top();
				area=arr[a]*(i-l-1);
				max_area_so_far=area>max_area_so_far?area:max_area_so_far;

			}	
		}

	}
	while(!s.empty()){
		int a=s.top()
		s.pop();
		int l=s.top();
		area=arr[a]*(i-l-1);
		max_area_so_far=area>max_area_so_far?area:max_area_so_far;
	}

	cout<<max_area_so_far<<endl;
}


int main(){
	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	max_area(arr,n);
}