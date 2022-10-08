/*
https://leetcode.com/problems/search-a-2d-matrix
74. Search a 2D Matrix

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i=0;
        while(i<n && matrix[i][0]<=target){
            i++;
        }
        i--;
        if(i<0) return 0;
        for(int j=0;j<m;j++){
            if(matrix[i][j] == target) {
                return 1;
            }
            if(matrix[i][j]>target) return 0;
        }
        return 0;
    }
};
