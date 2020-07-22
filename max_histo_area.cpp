#include<iostream>
#include<stack>
#include<climits>
using namespace std;

void max_area(int arr[],int n){
	stack<int> s;
	int area=INT_MIN,max_area_so_far=INT_MIN;
	int i=0;
    while(i<n){

		if(s.empty() || arr[s.top()]<=arr[i]) 
			{s.push(i);
            i++;}
		else{
			while(arr[s.top()]>arr[i]){
				int a=s.top();
				s.pop();
				//int l=s.top();
		        area=arr[a]*(s.empty()?i:s.top()-i-1);
                s.push(i);
                i++;
			}	
		}
		max_area_so_far=area>max_area_so_far?area:max_area_so_far;


	}
	while(!s.empty()){
		int a=s.top();
		s.pop();
		area=arr[a]*(s.empty()?i:i-s.top()-1);
		max_area_so_far=area>max_area_so_far?area:max_area_so_far;
        i--;
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