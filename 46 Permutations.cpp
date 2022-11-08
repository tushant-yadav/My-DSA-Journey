/*
46. Permutations
https://leetcode.com/problems/permutations/description/
Medium
13.6K
225
Companies
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/
class Solution {
    vector<vector<int>> ans;
    void helper(int n, vector<int> &temp, vector<int> &nums){
        if(n==0) ans.push_back(temp);
        for(int i=0;i<n;i++){
            int t= nums[i];
            temp.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            helper(n-1,temp,nums);
            temp.pop_back();
            nums.insert(nums.begin()+i,t);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        helper(n,temp,nums);
        return ans;
    }
};
