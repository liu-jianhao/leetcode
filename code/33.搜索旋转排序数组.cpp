/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;

        int start = 0, end = nums.size() - 1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] < nums[end])
            {
                if(nums[end] >= target && nums[mid] < target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else
            {
                if(nums[start] <= target && nums[mid] > target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return -1;
    }
};

