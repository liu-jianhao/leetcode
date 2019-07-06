/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int res = nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(dp[i-1] < nums[i] && dp[i-1] < 0)
                dp[i] = nums[i];
            else
            {
                dp[i] = nums[i] + dp[i-1];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

