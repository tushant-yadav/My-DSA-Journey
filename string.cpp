#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cin>>s;
	char a;
	cin>>a;
	int n=s.find(a);
	cout<<n;
	return 0;
}