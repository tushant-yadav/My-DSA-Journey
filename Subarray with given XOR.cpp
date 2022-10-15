/*
Subarray with given XOR
https://www.interviewbit.com/problems/subarray-with-given-xor/
Problem Description
Given an array of integers A and an integer B.
Find the total number of subarrays having bitwise XOR of all elements equals to B.
Problem Constraints
1 <= length of the array <= 105
1 <= A[i], B <= 109
Input Format
The first argument given is the integer array A.
The second argument given is integer B.
Output Format
Return the total number of subarrays having bitwise XOR equals to B.

*/

int Solution::solve(vector<int> &A, int B) {
        int tot_cnt=0,xr=0;
        unordered_map<int, int> um;
        for(int i=0;i<A.size();i++){
            xr=(A[i]^xr);
            if(xr == B) tot_cnt++;
            if(um.find((xr^B))!=um.end()){
                tot_cnt+=um[xr^B];
            }
            um[xr]++;
        }
        return tot_cnt;
    }

