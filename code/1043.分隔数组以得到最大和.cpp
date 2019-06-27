/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 *
 * [1043] 分隔数组以得到最大和
 */
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size()+1, 0);

        for(int i = 1; i <= A.size(); ++i)
        {
            int m = INT_MIN;
            for(int k = 1; k <= min(i, K); ++k)
            {
                m = max(m, A[i-k]);
                dp[i] = max(dp[i], dp[i-k] + m * k);
            }
        }
        return dp[A.size()];
    }
};

