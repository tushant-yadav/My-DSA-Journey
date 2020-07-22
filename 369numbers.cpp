#include<iostream>
#include<string>
using namespace std;

bool isnum(int a){
	string s=to_string(a);
	//cout<<s<<endl;
	int three=0,nine=0,six=0;
	while(s.find('3')!=-1){
		int index=s.find('3');
		s[index]='d';
		three++;
	}
	while(s.find('6')!=-1){
		int index=s.find('6');
		s[index]='d';
		six++;
	}
	while(s.find('9')!=-1){
		int index=s.find('9');
		s[index]='d';
		nine++;
	}
	//cout<<three<<":"<<six<<":"<<nine<<endl;
	if(three==nine && six==three && six!=0){
		return true;
	}
	return false;
	
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int a,b,count=0;
		cin>>a>>b;
		a=a%2==0?a+1:a;
		for(int j=a;j<b;j++){
			if(isnum(j)){
				count++;
			}
		}
		cout<<count<<endl;
	}
}