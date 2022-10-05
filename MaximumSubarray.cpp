/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.
https://leetcode.com/problems/maximum-subarray/

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int local_max=0, global_max=INT_MIN;
        for(int i = 0;i<n;i++){
            local_max+=nums[i];
            global_max = (global_max<local_max)?local_max:global_max;
            if(local_max<0) local_max = 0;
        }
        return global_max; 
        
    }
};
