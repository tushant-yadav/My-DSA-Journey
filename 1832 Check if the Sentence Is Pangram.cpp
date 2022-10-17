/*
1832. Check if the Sentence Is Pangram
https://leetcode.com/problems/check-if-the-sentence-is-pangram/
A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.*/
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.length();
        if(n<26) return 0;
        vector<bool> a(26,0);
        for(int i=0;i<n;i++){
            a[sentence[i]-'a']=1;
        }
        for(int i=0;i<26;i++){
            if(a[i]==0) return 0;
        }
        return 1;
    }
};
