/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int buy = INT_MAX;
        for(int i = 0; i < prices.size(); ++i)
        {
            buy = min(buy, prices[i]);
            res = max(res, prices[i] - buy);
        }
        return res;
    }
};

