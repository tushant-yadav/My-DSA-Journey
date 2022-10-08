/*
50. Pow(x, n)
https://leetcode.com/problems/powx-n/
Medium
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;        
        if(n<0){
            if(n==(-1)) return 1/x;            
            if(abs(n%2)){
                n = n/2;
                n*=(-1);
                double a = myPow(x,n);
                return 1/(a*a*x);
            }
            n = n/2;
            n*=(-1);
            double a = myPow(x,n);
            return 1/(a*a);
        }
        if(n==1) return x;
        double a = myPow(x,n/2);
        if(abs(n%2))
            return (a*a*x);
        return (a*a);
    }
};
