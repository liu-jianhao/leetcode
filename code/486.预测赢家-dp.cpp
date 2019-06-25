/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<int> dp(nums.size() * nums.size(), 0);
        return getScore(nums, 0, nums.size()-1, dp) >= 0;
    }

    int getScore(vector<int>& nums, int l, int r, vector<int>& dp)
    {
        if(l == r)
            return nums[l];
        int k = l * nums.size() + r;

        if(dp[k] > 0)
            return dp[k];
        
        dp[k] = max(nums[l] - getScore(nums, l+1, r, dp), nums[r] - getScore(nums, l, r-1, dp));

        return dp[k];
    }
};

