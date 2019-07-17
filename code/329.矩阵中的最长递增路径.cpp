/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int res = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                res = max(res, dfs(matrix, i, j, dp));
            }
        }
        return res;
    }

    int dfs(const vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp)
    {
        if(dp[i][j] != -1)
            return dp[i][j];
        
        dp[i][j] = 1;
        static int dir[] = {0, -1, 0, 1, 0};
        for(int k = 0; k < 4; ++k)
        {
            int cx = i + dir[k];
            int cy = j + dir[k+1];
            if(cx < 0 || cy < 0 || cx >= matrix.size() || cy >= matrix[0].size() 
               || matrix[i][j] >= matrix[cx][cy])
               continue;
            dp[i][j] = max(dp[i][j], 1 + dfs(matrix, cx, cy, dp));
        }
        return dp[i][j];
    }
};

