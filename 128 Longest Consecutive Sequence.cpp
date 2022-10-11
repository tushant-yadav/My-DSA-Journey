/*
128. Longest Consecutive Sequence
https://leetcode.com/problems/longest-consecutive-sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums),end(nums));
        int longest = 0;
        for(auto& i:s){
            if(s.count(i-1)) continue;
            int j=1;
            while(s.count(i+j)) j++;
            longest = max(longest,j);
        }
        return longest;
    }
};
