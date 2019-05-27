/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
// 暴力递归，超时
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return rec(nums, 0, nullptr);
    }

    int rec(vector<int> nums, int i, int* lastNum)
    {
        if(i == nums.size())
            return 0;

        if (lastNum != nullptr)
            if (nums[i] > *lastNum)
            {
                return max(1 + rec(nums, i + 1, &nums[i]), rec(nums, i + 1, lastNum));
            }
            else
            {
                return rec(nums, i + 1, lastNum);
            }
        return max(1 + rec(nums, i + 1, &nums[i]), rec(nums, i + 1, lastNum));
    }
};
