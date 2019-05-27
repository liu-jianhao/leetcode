/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */
class Solution {
public:
    int binaryGap(int N) {
        if((N & (N-1)) == 0)
            return 0;

        int res = 1;
        int start = -1;
        int cur = 0;
        while(N)
        {
            if(N & 1)
            {
                if(start != -1)
                {
                    res = max(res, cur-start);
                }
                start = cur;
            }
            cur++;
            N = N >> 1;
        }

        return res;
    }
};

