/*219. Contains Duplicate II
https://leetcode.com/problems/contains-duplicate-ii
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n = nums.size();
        m[nums[0]]=1;
        for(int i=1;i<n;i++){
            if(m[nums[i]]!=0 && (i-m[nums[i]]<k )) return 1;
            m[nums[i]] =i+1;
        }
        return 0;

    }
};
