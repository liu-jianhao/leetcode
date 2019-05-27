/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(; n; n = n & (n-1))
            ++res;
        return res;
    }
};

