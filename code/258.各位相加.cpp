/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */
class Solution {
public:
    int addDigits(int num) {
        while(num >= 10)
        {
            int sum = 0;
            while(num > 0)
            {
                int tmp = num % 10;
                sum += tmp;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

