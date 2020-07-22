#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	cout<<"*";
	for(int i=0;i<(n/2)-1;i++){
		cout<<" ";
	}
	for(int i=0;i<n/2+1;i++){
		cout<<"*";
	}
	cout<<endl;
	for(int i=0;i<n/2-1;i++){
		cout<<"*";
		for(int j=0;j<(n/2)-1;j++){
			cout<<" ";
		}
		cout<<"*"<<endl;
	}
	for(int i=0;i<n;i++){
		cout<<"*";
	}
	cout<<endl;
	for(int i=0;i<n/2-1;i++){
		for(int j=0;j<n/2;j++){
			cout<<" ";
		}
		cout<<"*";
		for(int j=0;j<(n/2)-1;j++){
			cout<<" ";
			}
		cout<<"*"<<endl;

	}
	for(int i=0;i<n/2+1;i++){
		cout<<"*";
	}
	for(int i=0;i<(n/2)-1;i++){
		cout<<" ";
	}
	cout<<"*"<<endl;

return 0;
}
/*

*  ****
*  *
*  *
*******
   *  *
   *  *
****  *
*/