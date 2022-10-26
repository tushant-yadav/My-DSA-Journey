/*523. Continuous Subarray Sum
Medium
3.8K
377
Companies
Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    	// initialize the hash map with index 0 for sum 0
        unordered_map<int, int> hashMap{{0, 0}};
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            // if the remainder sum % k occurs for the first time
            if (!hashMap.count(sum % k))
                hashMap[sum % k] = i + 1;
            // if the subarray size is at least two
            else if (hashMap[sum % k] < i)
                return true;
        }
        return false;
    }
};
