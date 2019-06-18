/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        // ??????2????
        if(num < 0 || num & (num-1))
            return false;

        // 4?????????????????1????????
        // ?2???????????1???????????
        return num & 0x55555555;
    }
};

