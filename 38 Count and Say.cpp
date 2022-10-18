/*
38. Count and Say
https://leetcode.com/problems/count-and-say
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":


Given a positive integer n, return the nth term of the count-and-say sequence.

*/class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s = countAndSay(n-1);//21
        int len = s.length(); //2
        string sn;
        int cnt = 0;
        char prev=s[0];//2
        for(int i=0;i<len;i){
            prev = s[i];
            cnt = 0;    
            while(prev==s[i]){
                i++;//1
                cnt++;//1
            }
            sn+=(cnt+'0');//2
            sn+=(prev);//21
        }
        return sn;
    }
};
