/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;

        int res = 0;
        int minus1 = 2;
        int minus2 = 1;
        for(int i = 3; i <= n; ++i)
        {
            res = (minus1 + minus2);
            minus2 = minus1;
            minus1 = res;
        }
        return res;
    }
};

