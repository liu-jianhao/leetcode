/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 1)
            return true;
        else if(num == 0)
            return false;
        else
            return isPowerOfFour(num/4) && (num % 4 == 0);        
    }
};

