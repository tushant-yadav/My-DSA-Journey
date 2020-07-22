#include<iostream>
using namespace std;

void subseq( char *in, char *out,int i,int j){
	//base case
	if(in[i]=='\0'){
		out[j]=='\0';
		cout<<out<<endl; 
		return;
	}
	//rec

	out[j]=in[i];
	subseq(in,out,i+1,j+1);
	subseq(in,out,i+1,j); 

}
int main(){
	char input[]="abc";
	char output[10]={'\0'};
	subseq(input,output,0,0);	

}; 