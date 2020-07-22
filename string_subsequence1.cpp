#include<iostream>
#include<string>
using namespace std;
int sequence(string input,string output){
	if(input.length()==0){
		cout<<output<<endl;

       // cout<<"...:";
		return 0;
	}
    //cout<<input<<endl;
    sequence(input,output);
    char a=input[0];
    //output+=input[0];
	sequence(input,output+a);
    input.erase(0,1);
	
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