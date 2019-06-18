/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1)
            return true;
        else if(n == 0)
            return false;
        else
            return isPowerOfThree(n/3) && (n % 3 == 0);
    }
};

