/*
42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

*/
class Solution {
public: 

    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3) return 0;
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i=1;i<n-1;i++){
            left[i] = max(left[i-1],height[i]);
            right[n-i-1] = max(right[n-i],height[n-i-1]);
        }
        left[n-1] = max(left[n-2],height[n-1]);
        right[0] = max(right[1],height[0]);
        int count=0;
        for(int i=0;i<n;i++){
            //cout<<left[i]<<":"<<height[i]<<":"<<right[i]<<endl;
            
            count+= min(left[i],right[i])-height[i]; 
            //cout<<count<<endl;
        }
        return count;
    }
};
