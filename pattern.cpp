#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	cout<<"1"<<endl;
	for(int i=1;i<n;i++){
		cout<<"1";
		for(int j=0;j<i-1;j++){
			if(i%2==0) cout<<"0";
			else cout<<"1";
		}
	cout<<"1"<<endl;	
	}
	return 0;
}