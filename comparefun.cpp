#include<iostream>
using namespace std;
int main() {
	int n,no,digit,evensum=0,oddsum=0;
	cin>>n;
	for(int i =0;i<n;i++)
	{
		cin>>no;
		for(int j=0;no>0;j++)
		{
			digit=no%10;
			if (digit%2==0)
			{
				evensum+=digit;

			}
			else
			{
				oddsum+=digit;
			}
			no=no/10;
		}
		if(evensum%4==0)
		{
			cout<<"Yes"<<endl;
		}
		else if(oddsum%3==0)
		{
			cout<<"Yes"<<endl;
			}
		else
		{
			cout<<"No"<<endl;
		}
		
	}
	return 0;
}