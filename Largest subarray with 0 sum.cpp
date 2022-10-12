/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
-1000 <= A[i] <= 1000, for each valid i
*/
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int cnt=0,tot_cnt=0;
        if(A[0]==0) tot_cnt=1;
        
        unordered_map<int, int> um;
        um[A[0]]=1;
        for(int i=1;i<A.size();i++){
            cnt=0;
            A[i]+=A[i-1];
            if(um[A[i]]!=0){
                cnt = i+1 - um[A[i]];

            }
            else um[A[i]] = i+1;
            if(A[i]==0) cnt = i+1;
            tot_cnt = tot_cnt>cnt?tot_cnt:cnt;            
            //cout<<A[i]<<":"<<tot_cnt<<":"<<um[A[i]]<<endl;
        }
        return tot_cnt;
        // Your code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
