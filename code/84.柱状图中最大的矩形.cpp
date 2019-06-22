/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        stack<int> stk;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (!stk.empty() && heights[i] < heights[stk.top()])
            {
                int top = stk.top();
                stk.pop();
                maxArea = max(maxArea, heights[top] * (stk.empty() ? i : (i - stk.top() - 1)));
            }
            stk.push(i);
        }
        return maxArea;
    }
};
