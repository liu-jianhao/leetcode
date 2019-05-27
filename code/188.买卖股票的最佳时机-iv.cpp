/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
// 最后两个测试没通过，超时
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty())
            return 0;
        int maxi = prices.size();
        k = min(maxi/2, k);
        vector<vector<vector<int>>> dp(maxi+1, vector<vector<int>>(2, vector<int>(k+1)));

        for(int i = maxi-1; i >= 0; --i)
        {
            for(int j = 1; j >= 0; --j)
            {
                for(int x = k; x >= 0; --x)
                {
                    if(x == k && j == 0)
                        continue;
                    if(j > 0)
                        dp[i][j][x] = max(prices[i] + dp[i+1][0][x], dp[i+1][1][x]);
                    else
                        dp[i][j][x] = max(-prices[i] + dp[i+1][1][x+1], dp[i+1][0][x]);
                }
            }
        }

        return dp[0][0][0];
    }
};

