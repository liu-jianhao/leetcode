/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        s.push(-1);
        int i = 0;
        int res = 0;
        while(i < n)
        {
            while(s.top() != -1 && heights[s.top()] >= heights[i])
            {
                int h = s.top();
                s.pop();
                res = max(res, heights[h] * (i - s.top() - 1));
            }
            s.push(i++);
        }

        while(s.top() != -1)
        {
            int h = s.top();
            s.pop();
            res = max(res, heights[h] * (n - s.top() - 1));
        }

        return res;
    }
};

