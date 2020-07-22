#include <iostream>
#include<stack>
using namespace std;

void push_atbottom(stack<int> &s1, int data){
    if(s1.empty()){
        s1.push(data);
        return;
    }
        //cout<<s1.top()<<":"<<data<<endl;

    int x=s1.top();
    s1.pop();
    push_atbottom(s1,data);
    s1.push(x);
    return;
}

void reduction(stack<int> &s1){
    if(s1.empty()){
        return;
    }
    //cout<<s1.top()<<endl;
    int x=s1.top();
    s1.pop();
    reduction(s1);
    push_atbottom(s1,x);
    return;

}

void print(stack<int> s1){
    if(s1.empty()){
        return;
    }
    
    cout<<s1.top()<<" ";
    s1.pop();
    print(s1);
    return;
}

int main() {
    stack<int> s1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s1.push(x);
    }
    //print(s1);
    reduction(s1);
    print(s1);
    return 0;
}
