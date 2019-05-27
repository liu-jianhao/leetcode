/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty() || nums.size() < 2)
            return;

        int k = -1, l;

        // 找出最大的k，使 nums[k] < nums[k+1]
        for(int i = 0; i < nums.size()-1; ++i)
        {
            if(nums[i] < nums[i+1])
                k = i;
        }

        // 没找到说明已经是最大的，下一个就是最小的
        if(k == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 找到最大的l，使 nums[l] > nums[k]
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > nums[k])
                l = i;
        }

        swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());
    }
};

