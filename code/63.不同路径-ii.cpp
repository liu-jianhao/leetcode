/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        long long dp[rows][cols];
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;

        for(int i = 1; i < rows; ++i)
            dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i-1][0];
        for(int j = 1; j < cols; ++j)
            dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j-1];

        for(int i = 1; i < rows; ++i)
        {
            for(int j = 1; j < cols; ++j)
            {
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[rows-1][cols-1];
    }
};

