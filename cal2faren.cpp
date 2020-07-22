#include<iostream>
using namespace std;
int main() {
	int s,r,d;
	cin>>s>>r>>d;
	int c=0;
	for (int i=s;i<=r;i=i+d)
	{
		c = 5*(i – 32)/9 ;
		cout<<i<<" "<c<<endl;
	}

	return 0;
}