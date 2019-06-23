/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班 
 */
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int maxCost = 1e9;
        vector<vector<int>> dp(K+2, vector<int>(n, maxCost));
        dp[0][src] = 0;

        for(int i = 1; i <= K+1; ++i)
        {
            dp[i][src] = 0;
            for(auto f : flights)
            {
                dp[i][f[1]] = min(dp[i][f[1]], dp[i-1][f[0]] + f[2]);
            }
        }
        return dp[K+1][dst] >= 1e9 ? -1 : dp[K+1][dst];
    }
};

