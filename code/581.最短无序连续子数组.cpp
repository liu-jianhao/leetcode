/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int n = nums[0], m = nums[len-1];
        int left =  -1, right = -2;
        for(int i = 1; i < len; ++i)
        {
            // n为从左到右的最大值
            n = max(n, nums[i]);
            // m为从右到左的最小值
            m = min(m, nums[len-1-i]);
            // 如果当前的值nums[i]比n小，说明这个位置的值是逆序的
            if(n != nums[i])
                right = i;
            // 如果当前的值nums[len-1-i]比n大，说明这个位置的值是逆序的
            if(m != nums[len-1-i])
                left = len-1-i;
        }

        return right-left+1;
    }
};

