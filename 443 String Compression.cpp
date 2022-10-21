/*
443. String Compression
https://leetcode.com/problems/string-compression
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string a;
        for(int i=0;i<n;i=i){
            char temp = chars[i];
            int cnt=0;
            while(i<n && chars[i]==temp){
                cnt++;
                i++;
            }
            a +=temp;
            if(cnt>1) a+=to_string(cnt);
        }
        chars.clear();
        for(auto s:a){
            chars.push_back(s);
        }

        return a.length();
    }
};
