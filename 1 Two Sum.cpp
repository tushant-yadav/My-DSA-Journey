/*
1. Two Sum

https://leetcode.com/problems/two-sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/
class Solution {
public:
    static bool comap(pair<int,int> a, pair<int,int>b){
        return (a.first<b.first);
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> a;
        for(int i=0;i<nums.size();i++){
            a.push_back(make_pair(nums[i],i));
        }
        sort(a.begin(),a.end(), comap);
        int i=0,j=nums.size()-1;
        vector<int> ans;
        while(i<j){
            int temp = a[i].first+a[j].first;
            if(temp==target){
                ans.push_back(a[i].second);
                ans.push_back(a[j].second);
                break;
            }
            if(temp>target) j--;
            else i++;
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
