/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1);
        res[0] = 1;
        for(int i = 1; i <= rowIndex; ++i)
        {
            int pre = 1;
            int cur = 0;
            for(int j = 1; j <= i; j++)
            {
                // 要先保存当前值
                cur = res[j];
                res[j] += pre;
                pre = cur;
            }
        }
        return res;
    }
};

