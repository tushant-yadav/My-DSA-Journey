#include<iostream>
using namespace std;

int  main()
{
	int no,sum=0;

	cin>>no;
	while(no>0)
	{
		int last_digit = no%10;
		sum=sum+last_digit;
		no=no/10;
	}
	cout<<sum;





	return 0;
}
