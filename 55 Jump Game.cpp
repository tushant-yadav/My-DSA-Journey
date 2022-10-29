/*
https://leetcode.com/problems/jump-game/description/
55. Jump Game
Medium
13.5K
710
Companies
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/class Solution {
public:
    bool poss[10000]={0}; 
    bool jumptolast(vector<int> &nums, int idx){
        if(poss[idx] == 1) return 0;
        int len = idx+nums[idx]; 
        if(len>=nums.size()-1) return 1;
        for(int i=len;i>idx;i--){
            if(jumptolast(nums,i)) return true;
        }
        poss[idx] = 1;
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        if(nums[0]==0) return 0;
        return jumptolast(nums,0);
    }
};
