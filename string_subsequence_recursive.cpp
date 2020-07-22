#include<iostream>
#include<string>
using namespace std;
int sequence(string input,string output){
	if(input.length()==0){
		cout<<output<<endl;
		return 0;
	}
    char a=input[0];
    input.erase(0,1);
    sequence(input,output+a);
    sequence(input,output);
	return 0;
}
int main() {
	int t;
	cin>>t;
	for(int k=0;k<t;k++){
		string input,output;
        cin>>input;
		sequence(input,output);
	}
	return 0;
}