/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;
        
        int rn = 0;
        while(x > rn)
        {
            rn = rn * 10 + x % 10;
            x /= 10;
        }
        return rn == x || rn / 10 == x;
    }
};

