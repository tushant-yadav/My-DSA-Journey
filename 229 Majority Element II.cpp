/*
229. Majority Element II
https://leetcode.com/problems/majority-element-ii/
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> um;
        unordered_map<int,bool> ins;
        vector<int> ans ;
        for(int num: nums){
            um[num]+=1;
            if(um[num]>(nums.size()/3)) {
                if(!ins[num])
                ans.push_back(num);
                ins[num]=1;
                }
        }
        //cout<<ans[0];
        return ans;
        
    }
};
