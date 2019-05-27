/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int maxi = prices.size();
        // [i][j][k]的表示为第i天，j为0表示现在没有持股，j为1表示现在有持股，k表示这天之前已经买过k次了
        vector<vector<vector<int>>> dp(maxi+1, vector<vector<int>>(2, vector<int>(3)));

        for(int i = maxi-1; i >= 0; --i)
        {
            for(int j = 1; j >= 0; --j)
            {
                for(int k = 2; k >= 0; --k)
                {
                    // 买过2次并且现在没有持股，说明已经买卖两次了
                    if(k == 2 && j == 0)
                        continue;
                    if(j == 1)
                        dp[i][j][k] = max(prices[i] + dp[i+1][0][k], dp[i+1][1][k]);
                    else
                        dp[i][j][k] = max(-prices[i] + dp[i+1][1][k+1], dp[i+1][0][k]);
                }
            }
        }

        return dp[0][0][0];
    }
};

