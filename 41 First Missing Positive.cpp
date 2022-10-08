/*
https://leetcode.com/problems/first-missing-positive/
41. First Missing Positive

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool> um;
        for(int i=0;i<n;i++){
            um[nums[i]] = 1;
        }
        for(int i=1;i<=n;i++){
            if(um[i]==0)
            return i;
        }
        return n+1;
    }
};
