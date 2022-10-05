/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
https://leetcode.com/problems/set-matrix-zeroes/description/
*/

public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size(),m=matrix[0].size();
        vector<pair<int,int>> zeros;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    zeros.push_back({i,j});
                }
                
            }
        
        }
        for(auto k:zeros){
            for(int i=0;i<n;i++) matrix[i][k.second]=0;
            for(int j=0;j<m;j++) matrix[k.first][j]=0;
        }
    }
};
