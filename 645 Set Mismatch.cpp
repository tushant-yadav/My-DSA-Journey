/*
645. Set Mismatch
https://leetcode.com/problems/set-mismatch/
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v(nums.size(),0);
        for(auto num:nums){
            v[num-1]++;
        }
        vector<int> ans ={0,0};
        for(int i=0;i<nums.size();i++){
            if(v[i]==2) ans[0] = i+1;
            else if(v[i]==0) ans[1] = i+1;
        }
        return ans;

    }
};
