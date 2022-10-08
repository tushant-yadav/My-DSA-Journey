/*

62. Unique Paths
Medium
https://leetcode.com/problems/unique-paths/
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 
*/

class Solution {
public:
    int arr[100][100]={0};
    int uniquePaths(int m, int n) {
        int cnt = 0;
        for(int i=0;i<n;i++){
            arr[m-1][i] = 1;
        }
        for(int i=0;i<m;i++){
            arr[i][n-1] = 1;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                arr[j][i] = arr[j+1][i]+arr[j][i+1];
            }
        }
    
        return arr[0][0];
    }
};
