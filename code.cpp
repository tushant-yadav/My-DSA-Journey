#include <iostream> 
using namespace std; 
class gfg 
{ 
public : int gcd(int a, int b){ 
	if (a == 0) 
		return b; 
	return gcd(b % a, a); 
} 
int lcm(int a, int b) 
{ 
	return (a*b)/gcd(a, b); 
} 
} ; 
int main() 
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
    	int flag=0;
        gfg g; 
    	int a , b ;
    	cin>>a>>b;
    	int x=a,y=a+1;
    	for(x;x<=b-1;x++){
            for(y;y<=b;y++){            
                int l = g.lcm(x, y);
                if(l<=b){
                    cout<<x<<" "<<y<<" "<<endl;
                    flag=1;
                    break;
                }
                if(flag==1) break;
            }
            if(flag==1) break;
        }
        if(flag==0) cout<<-1<<" "<<-1<<endl;
    }
return 0;
} 
