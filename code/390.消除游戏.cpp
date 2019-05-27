/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */
class Solution {
public:
    int lastRemaining(int n) {
        int start = 1;
        int end = n;
        int step = 1;
        bool lefttoright = true;
        while(start < end)
        {
            int count = (end - start) / step + 1;
            if(lefttoright)
            {
                start += step;
                end -= step * (count % 2);
            }
            else
            {
                start += step * (count % 2);
                end -= step;
            }
            
            step *= 2;
            lefttoright = !lefttoright;
        }

        return start;
    }
};

