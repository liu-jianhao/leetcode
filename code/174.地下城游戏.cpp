/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n, INT_MIN);
        dp[n-1] = 0;

        for(int i = m - 1; i >= 0; --i)
        {
            dp[n-1] += dungeon[i][n-1];
            dp[n-1] = (dp[n-1] > 0) ? 0 : dp[n-1];
            for(int j = n - 2; j >= 0; --j)
            {
                dp[j] = max(dp[j+1], dp[j]) + dungeon[i][j];
                dp[j] = (dp[j] > 0) ? 0 : dp[j];
            }
        }

        return 1 - dp[0];
    }
};

