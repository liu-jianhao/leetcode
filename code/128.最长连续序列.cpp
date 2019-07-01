/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int res = 0;
        for(int n : nums)
        {
            // 从左边界开始
            if(n != INT_MIN && !hash.count(n-1))
            {
                int l = 0;
                while(n != INT_MAX && hash.count(n))
                {
                    ++l;
                    ++n;
                }
                res = max(res, l);
            }
        }
        return res;
    }
};

