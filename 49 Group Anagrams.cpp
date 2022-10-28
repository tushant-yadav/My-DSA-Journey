/*
49. Group Anagrams
https://leetcode.com/problems/group-anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(um.find(s)!=um.end()) um[s].push_back(strs[i]);
            else
            um[s] = {strs[i]};
        }
        vector<vector<string>> ans;
        for(auto i:um){
            ans.push_back(i.second);
        }
        return ans;



        
    }
};
