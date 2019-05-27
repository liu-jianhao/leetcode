/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty())
            return res;

        deque<int> dq;
        for(int i = 0; i < nums.size(); ++i)
        {
            // 弹出比当前值小的
            while(!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            // 处理过期最大值
            if(!dq.empty() && dq.front() < i-k+1)
            {
                dq.pop_front();
            }

            // 记录下标
            dq.push_back(i);

            if(i >= (k-1))
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

