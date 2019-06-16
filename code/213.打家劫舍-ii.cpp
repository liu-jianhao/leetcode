/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        else if(nums.size() == 2)
            return max(nums[0], nums[1]);
        
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        // 不抢劫最后一个
        for(int i = 2; i < nums.size()-1; ++i)
        {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        int dp1 = dp[nums.size()-2];

        dp[0] = 0;
        dp[1] = nums[1];
        // 不抢劫第一个
        for(int i = 2; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        return max(dp1, dp[nums.size()-1]);
    }
};

