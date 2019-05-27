/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3)
            return 0;
        for(int i = nums.size()-1; i >= 2; --i)
        {
            int left = 0, right = i-1;
            while(left < right)
            {
                if(nums[left] + nums[right] > nums[i])
                {
                    res += (right - left);
                    --right;
                }
                else
                {
                    ++left;
                }
            }
        }
        return res;
    }
};

