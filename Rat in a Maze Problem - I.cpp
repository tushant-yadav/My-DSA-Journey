/*
https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
*/
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isallowed(vector<vector<int>> &m, int x, int y,int n,vector<vector<int>> vis){
        if(x>=0 && y>=0 && x<n && y<n && vis[x][y]==0){
            if(  m[x][y]==1) return 1;
        }
        return 0;
    }
    void path(vector<vector<int>> &m,
                vector<string> &ans, 
                int x, int y, string s,
                int n,
                vector<vector<int>> &vis){
        
        if(x==n-1 && y==n-1){
            ans.push_back(s);
            vis[x][y]=0;
            return;
        }
        vis[x][y]=1;
if(isallowed(m,x+1,y,n,vis))
        path(m,ans,x+1,y,s+"D",n,vis);
if(isallowed(m,x,y-1,n,vis))
        path(m,ans,x,y-1,s+"L",n,vis);
if(isallowed(m,x,y+1,n,vis))
        path(m,ans,x,y+1,s+"R",n,vis);
if(isallowed(m,x-1,y,n,vis))
        path(m,ans,x-1,y,s+"U",n,vis);
        vis[x][y]=0;
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis( n , vector<int> (n, 0));
        vector<string> ans;
        if(isallowed(m,0,0,n,vis)){
            path(m, ans, 0 , 0,"", n,vis);    
        }
        if(ans.empty()){
            vector<string> out;
            out.push_back("-1");
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
