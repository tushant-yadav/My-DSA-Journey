#include <iostream>
using namespace std;
int N,count=0;
bool board[30][30]={0};
//to print the arrangment
void print(int n){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==1){
                cout<<"{"<<i<<"-"<<j<<"}"<<" ";
            }
        }
    }
    return;
}
//**********************************************************
//to check if we can place queen here or not
int is_possible(int col,int row){
    for(int i=0;i<row;i++){
        if(board[i][col]){
            return false;
        }}
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }}
    for(int i=row,j=col;i>=0 && j<N;i--,j++){
        if(board[i][j]){
            return false;            
        }}   
    return true;
}
//*****************************************************
bool place_queen(int n,int i,int row){
    if(row>N-1) {
       // cout<<"true from base"<<endl;
        count++;
        print(n);
        return false;}
    for(int col=i;col<N;col++){
        if(is_possible(col,row)){
            board[row][col]=1;
            //recursive function to place queens
            if(place_queen(n,0,row+1)){
                return true;
            }
        //back tracking incase further recursion we got false we undo placed queens   
        board[row][col]=0;
        }
    }
   // cout<<"false place queen "<<row<<endl;
    return false;
}
//*********************************************************

int main() {
    cin>>N;
    place_queen(N,0,0);
    cout<<endl<<count<<endl;
    return 0;
}
