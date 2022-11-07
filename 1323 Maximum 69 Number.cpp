/*
1323. Maximum 69 Number
https://leetcode.com/problems/maximum-69-number/description/
Easy
2K
175
Companies
You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

 

Example 1:

Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
 

Constraints:

1 <= num <= 104
num consists of only 6 and 9 digits.
*/
class Solution {
public:
    int maximum69Number (int num) {
        int new1 = num;
        int idx=-1,idxnt=-1;
        while(new1!=0){
            int temp1 = new1%10;
            idxnt++;
            idx = temp1==6?idxnt : idx;
            new1 = new1/10;
        }
        if(idx == -1) return num;
        num = num-(6*pow(10,idx));
        num = num+(9*pow(10,idx));
        return num;
        
    }
};
