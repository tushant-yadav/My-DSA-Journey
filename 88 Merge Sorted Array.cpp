/*
https://leetcode.com/problems/merge-sorted-array
88. Merge Sorted Array
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/
 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        while(i<m&&j<n){
            if(nums2[j]<nums1[i]){
                swap(nums2[j],nums1[i]);
                sort(nums2.begin(),nums2.end());
                i++;
            }
            else i++;
        }
        for(int j=0;j<n;j++){
            nums1[i]=nums2[j];
            i++;
        }
        
    }
};
