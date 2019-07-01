/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> s;
        int res = 0;
        int curIndex = 0;
        while(curIndex < n)
        {
            while(!s.empty() && height[curIndex] > height[s.top()])
            {
                int top = s.top();
                s.pop();
                if(s.empty())
                {
                    break;
                }
                int h = min(height[curIndex], height[s.top()]) - height[top];
                int dist = curIndex - s.top() - 1;
                res += dist * h;
            }

            s.push(curIndex++);
        }
        return res;
    }
};

