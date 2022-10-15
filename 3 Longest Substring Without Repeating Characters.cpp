/*
3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/
Given a string s, find the length of the longest substring without repeating characters.

*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> um;
        int n = s.length();
        int cur_len = 0, max_len = 0;
        for(int i=0;i<n;i++){
                if(um[s[i]]!=0){
                    cur_len = min(i+1-um[s[i]],cur_len);
                    if(cur_len<i+1-um[s[i]]) cur_len++;
                }
                
                else cur_len++;
                
                um[s[i]] = i+1;
                max_len = max_len<cur_len?cur_len:max_len;
            
        }
        return max_len;
    }
};
