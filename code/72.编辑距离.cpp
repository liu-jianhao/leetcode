/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        // [i][j]表示word1前i个字符和word2前j个字符的最小编辑距离
        vector<vector<int>> dp(len1+1, vector<int>(len2+1));

        for(int i = 0; i <= len1; ++i)
            dp[i][0] = i;
        for(int j = 0; j <= len2; ++j)
            dp[0][j] = j;

        for(int i = 1; i <= len1; ++i)
        {
            for(int j = 1; j <= len2; ++j)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }

        return dp[len1][len2];
    }
};

