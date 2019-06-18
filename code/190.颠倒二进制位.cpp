/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       int res = 0;
       int i = 32;
       while (i--)
       {
           res <<= 1;
           res += n & 1;
           n >>= 1;
       }
       return res;
    }
};
