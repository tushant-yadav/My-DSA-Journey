#include<iostream>
using namespace std;
bool possible(int n,int m, int x, int y, int mid){
	cout<<n<<":"<<m<<":"<<x<<":"<<y<<":"<<":"<<mid<<endl;
	int scholar=m/x;
    m=m%x;
    if(scholar>=mid)
    {cout<<"going short true"<<endl;
        return true;
    }
	int rem_studs=n-scholar;
    while(rem_studs>0){
        cout<<"rem_studs"<<rem_studs<<"coupens"<<m<<endl;
		if(m>=x){
			m-=x;
			scholar++;
		}

		else{
            int r=x-m;
            
			m=m+y;   
		}

		cout<<"scholar"<<scholar<<endl;
		if(scholar>=mid){
            cout<<"going true"<<endl;
			return true;
		
        }
        rem_studs--;
    }*/
cout<<"going false"<<endl;    
return false;	
}
int max_students(int n,int m, int x, int y){

	int start=0;
	int end=n;
	int mid=(start+end)/2;
    int ans;
	while(start<=end){
		mid=(start+end)/2;
		if(possible(n,m,x,y,mid)){
			start=mid+1;
            ans=mid;
		}
		else{
			end=mid-1;
		}
	}
	return ans;
}
int main() {
	int M,N,X,Y;
	cin>>N>>M>>X>>Y;
	cout<<max_students(N,M,X,Y);
	return 0;
}