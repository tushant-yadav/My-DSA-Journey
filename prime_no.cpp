#include <iostream>
using namespace std;
int seive(int n){
    int prime[n+1]={0};
    for(int i=3;i<=n+1;i=i+2){
        prime[i]=1;
    }
    for(int i=3;i<n+1;i++){
        if(prime[i]==1){
            for(int j=i*i;j<n+1;j=j+i){
                prime[j]=0;
            }
        }
    }
    prime[2]=1;
    for(int i=-1;i<n;i=i){
        i++;
        if(prime[i]==1){
            cout<<i;
            
            if(i<n-1){
                cout<<", ";
            }
        }
    }
return 0;
}

int main() {
    int n;
    cin>>n;
    seive(n);
    return 0;
}



#include<iostream>
#include<cmath>
using namespace std;

bool seive(int n){
	bool prime[n+1]={0};
    for(int i=3;i<=n+1;i=i+2){
        prime[i]=true;
    }
    for(int i=3;i<n+1;i++){
        if(prime[i]==true){
            for(int j=i*i;j<n+1;j=j+i){
                prime[j]=false;
            }
        }
    }
    prime[2]=true;
return prime[n];
}


int main() {
	long long int a;
	cin>>a;
	if(a<2){
			cout<<"Not Prime";
			return 0;

	}
	if(seive(a)){
		cout<<"Prime";
	}
	else{
	cout<<"Not Prime";}
return 0;
}3