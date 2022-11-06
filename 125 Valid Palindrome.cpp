/*
125. Valid Palindrome
https://leetcode.com/problems/valid-palindrome/description/
Easy
5.3K
6.2K
Companies
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int j = 0;
        for(int i =0;i<n;i++){
            if('a' <= s[i] && s[i]<='z' || '0'<=s[i] && '9'>=s[i] ) {
                s[j]=s[i];
                j++;
            }
            else if('A' <= s[i] && s[i]<='Z'){
                s[j] = 'a' + s[i]- 'A';
                j++;
            }

        }
        for(int i=0;i<j/2;i++){
            if(s[i]!=s[j-i-1]){
                return 0;
            } 
        }
        return 1;
    }

};
