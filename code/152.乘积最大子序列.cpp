/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;

        vector<int> dpMax(2);
        vector<int> dpMin(2);
        dpMin[0] = dpMax[0] = nums[0];
        int res = nums[0], x, y;
        for(int i = 1; i < nums.size(); ++i)
        {
            // 滚动数组，只需要两个数的空间
            x = i % 2;
            y = (i-1) % 2;
            dpMax[x] = max(dpMax[y]*nums[i], max(dpMin[y]*nums[i], nums[i]));
            dpMin[x] = min(dpMax[y]*nums[i], min(dpMin[y]*nums[i], nums[i]));

            res = max(res, dpMax[x]);
        }
        return res;
    }
};

