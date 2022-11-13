/*
Matrix Median
https://www.interviewbit.com/problems/matrix-median/
Bookmark
Medium
29.9% Success

518

22
Asked In:
Amazon
Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.




Input Format

The first and only argument given is the integer matrix A.
Output Format

Return the overall median of the matrix A.
Constraints

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd
For Example

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
Output 2:
    17 ``` Matrix=
```
*/

int Solution::findMedian(vector<vector<int> > &A) {
    int mini=INT_MAX,maxi=INT_MIN;
    int r=A.size();
    int c=A[0].size();
    for(int i=0;i<r;i++){
        mini=min(mini,A[i][0]);
        maxi=max(maxi,A[i][c-1]);
    }
    int desired=((r*c)+1)/2;
    while(mini<maxi){
        int mid=(maxi+mini)/2;
        int places=0;
        for(int i=0;i<r;i++){
            places+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        }
        if(places<desired) mini=mid+1;
        else  maxi=mid;
    }
    return mini;
}
