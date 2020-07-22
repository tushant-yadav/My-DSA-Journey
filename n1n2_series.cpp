#include<iostream>
using namespace std;
int main() {
	int n1,n2,out;
	cin>>n1>>n2;
	int j=1;
	for(int i=0;i<=n1;j=j+1)
	{
		
		out=(3*j)+2;
		cout<<out<<endl;
		if (out/n2!=0)
		{
			cout<<"in if"<<out<<endl;
			i=i+1;

		}
	}

	return 0;
}