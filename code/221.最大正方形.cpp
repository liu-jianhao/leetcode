/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;        
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        int len = 0;
        vector<vector<int>> dp(rows+1, vector<int>(cols+1));

        for(int i = 1; i <= rows; ++i)
        {
            for(int j = 1; j <= cols; ++j)
            {
                if(matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    len = max(len, dp[i][j]);
                }
            }
        }
        return len * len;
    }
};

