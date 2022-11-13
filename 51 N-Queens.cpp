/*
51. N-Queens
https://leetcode.com/problems/n-queens/description/
Hard
8.7K
192
Companies
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/
class Solution {
    vector<vector<string>> ans;
public:
    bool ispossible(vector<string> &v, int &idx,int &i,int n){
        for(int a=1;a<=idx;a++){           
            if(v[idx-a][i]=='Q') return 0;
            if(i-a>-1 && v[idx-a][i-a]=='Q') return 0;
            if(i+a<n && v[idx-a][i+a]=='Q') return 0;
        }
        return 1;        
    }
    void helper(vector<string> &v, int idx,int &n){
        if(idx>=n) {
            if(count(ans.begin(),ans.end(),v)==0)
            ans.push_back(v);
            return;
        } 
        for(int i=0;i<n;i++){
            if(ispossible(v,idx,i,n)){
                v[idx][i]='Q';
                helper(v,idx+1,n);
                v[idx][i]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i=0;i<n;i++){
            s.append(".");
        }
        vector<string> v(n,s);
        helper(v,0,n);
        return ans;
    }
};
