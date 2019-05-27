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
        vector<int> lis;

        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = std::lower_bound(lis.begin(), lis.end(), nums[i]);
            if(it == lis.end())
                lis.push_back(nums[i]);
            else
                *it = nums[i];
        }

        return lis.size();
    }
};

