#include<iostream>
using namespace std;
int main(){
  int m;
  cin>>m;
  int count=0;
  count+=m/100;
  m=m%100;
  count+=m/20;
  m=m%20;
  count+=m/10;
  m=m%10;
  count+=m/5;
  m=m%5;
  count+=m;
  cout<<count;
  return 0;

}
