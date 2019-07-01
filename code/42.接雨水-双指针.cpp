/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size() - 1;        
        int lmax = 0;
        int rmax = 0;
        while(l < r)
        {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if(lmax < rmax)
            {
                res += lmax - height[l];
                ++l;
            }
            else
            {
                res += rmax - height[r];
                --r;
            }
        }
        return res;
    }
};

