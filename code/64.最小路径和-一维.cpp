/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);

        for(int i = 0; i < m; ++i)
        {
            dp[0] += grid[i][0];
            for(int j = 1; j < n; ++j)
            {
                if(i == 0)
                {
                    dp[j] = dp[j-1] + grid[i][j];
                }
                else
                {
                    dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
                }
            }
        }
        return dp[n-1];
    }
};

