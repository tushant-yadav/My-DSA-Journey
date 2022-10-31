/*
https://leetcode.com/problems/combination-sum-ii/description/
40. Combination Sum II
Medium
7.2K
176
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/
class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& ans,vector<int> v, int idx,int target){
        if(0==target){
            ans.push_back(v);
            return;
        }
        //if(idx>=nums.size()) return;
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(0>target) break;
            v.push_back(nums[i]);
            helper(nums,ans,v,i+1,target-nums[i]);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        helper(nums, ans,{},0,target);
        return ans;
    }
};
