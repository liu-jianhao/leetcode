/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;    
        int start = 0;
        int end = height.size()-1;
        while(start < end)
        {
            int cur = min(height[start], height[end]) * (end - start);
            res = max(cur, res);
            // 高的一边不动
            if(height[start] < height[end])
                start++;
            else 
                end--;
        }

        return res;
    }
};

