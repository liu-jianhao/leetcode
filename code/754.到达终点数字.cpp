/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 */
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        int sum = 0;
        while(sum < target || (sum >= target && ((sum - target) % 2 != 0 )))
        {
            sum += (++k);
        }
        return k; 
    }
};

