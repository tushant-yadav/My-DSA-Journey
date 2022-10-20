/*
485. Max Consecutive Ones
https://leetcode.com/problems/max-consecutive-ones
Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cntc=0,cntm=0;
        for(auto n:nums){
            if(n==1) cntm = max(cntm,++cntc);
            else cntc=0;
        }
        return cntm;
    }
};
