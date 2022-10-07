/*
https://leetcode.com/problems/merge-intervals/description/
56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

*/class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> newinter;
        newinter.push_back(intervals[0]);
        for(int i=0;i<n;i++){
            if(newinter.back()[1]>=intervals[i][0]){
                newinter.back()[1] = max(intervals[i][1],newinter.back()[1]);
            }
            else newinter.push_back(intervals[i]);
        }
        return newinter;

        
    }
};
