/*
4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/description/
Hard
20.7K
2.3K
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
class Solution {

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
        
        sort(nums1.begin(), nums1.end());
        
        int n =  nums1.size();
        
        if(n%2 ==1)
            return nums1[n/2];
        
        else
        {
            int a = nums1[(n-1)/2] ; 
            int b = nums1[(n/2)];

            return ((a+b)/2.0);
        }
                  
    }
};
