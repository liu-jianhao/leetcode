/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0)
            return 1;
        if(n < 0)
            return 1 / myPow(x, -n);
        if(n % 2)
            return x * myPow(x, n-1);
        return myPow(x*x, n/2);
    }
};

