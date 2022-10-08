/*
16. 3Sum Closest
https://leetcode.com/problems/3sum-closest/
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0,k=0;
        int close = INT_MAX;
        int ans=0,finans = 0;
        for( i =0;i<n;i++){
            j=i+1; k=n-1;
            while(j<k){
                ans = nums[i]+nums[j]+nums[k];
                if(ans == target) return target;
                if(abs(target-ans)<close){
                    finans = ans;
                    close = abs(target-ans);
                }
                if(ans>target) k--;
                else j++;
            }
        }
        return finans;
        
    }
};
