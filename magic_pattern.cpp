#include <iostream>
using namespace std;
int main() {
    int n=4;
    for(int i=0;i<2*n+1;i++){
        cout<<"*";
    }
    cout<<endl;
    for(int p=0;p<n;p++){
        for(int i=p;i<n;i++){
            cout<<"*";
        }
        for(int i=p-1;i<n;i++){
            cout<<" ";
        }
        for(int i=p;i<n;i){
            cout<<"*";
        }
        cout<<endl;
    }
}
