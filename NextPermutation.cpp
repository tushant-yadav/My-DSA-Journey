/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

https://leetcode.com/problems/next-permutation/description/

*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),i1=0,i2=0;
        for(i1=n-2;i1>=0;i1--){
            if(nums[i1]<nums[i1+1]) break;
        }
        if(i1<0) {
            cout<<i1;
            reverse(nums.begin(),nums.end());
            return;
        }
        for(i2=n-1 ;i2>i1;i2--){
            if(nums[i2]>nums[i1]) break;
        }
        swap(nums[i1],nums[i2]);
        reverse(nums.begin()+i1+1,nums.end());
    }
};
/*
1234
1243
1324
1342
1423
1432

*/
