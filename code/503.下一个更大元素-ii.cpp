/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);

        stack<int> st;
        for(int i = 0; i < 2*nums.size(); ++i)
        {
            int n = nums[i%nums.size()];
            while(!st.empty() && n > nums[st.top()])
            {
                res[st.top()] = n;
                st.pop();
            }
            if(i < nums.size())
                st.push(i);
        }

        return res;
    }
};

