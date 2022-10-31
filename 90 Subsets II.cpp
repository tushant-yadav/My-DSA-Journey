/*
https://leetcode.com/problems/subsets-ii
90. Subsets II
Medium
6.9K
194
Companies
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution {
public:
    
    void solve(int ind, vector<int>&nums, vector<int>&path, vector<vector<int>>&paths)
    {
        paths.push_back(path);
        
        for(int i=ind;i<nums.size();i++)
        {    
            if(i!=ind and nums[i] == nums[i-1]) continue; // To avoid duplicate subsets
            
            path.push_back(nums[i]);
            solve(i+1, nums, path, paths);
            path.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {    
        vector<vector<int>>paths;
        vector<int>path;
        sort(nums.begin(), nums.end()); // sorting is most important --- so that order of duplicate subsets is same
        solve(0, nums, path, paths);    // [1,4,4] == [4,1,4] , both are same so no need to include both in answer
        return paths; 
    }
};
