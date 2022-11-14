/*
54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/description/
Medium
9.6K
945
Companies
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        vector<int> res;
        if(n==0 || m==0) return res;
        int arr[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int step[2] ={n,m-1} ;
        int dir=0;
        int r=0,c=-1;
        while(step[dir%2]){
            for(int i=0;i<step[dir%2];i++){
                r+=arr[dir][0];
                c+=arr[dir][1];
                res.emplace_back(matrix[r][c]);
            }
            step[dir%2]--;
            dir = (dir+1)%4;
        }
        return res;
    }
};
