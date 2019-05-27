/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;

        int maxi = nums.size();
        vector<int> dp(maxi, 1);
        int res = 1;
        for(int i = 1; i < maxi; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(dp[i], res);
        }

        return res;
    }
};

