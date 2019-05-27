/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v;
        int l = 0, r = nums.size() - 1;
        int ansL = -1, ansR = -1;
        while (l <= r)
        {
            int mid = (r + l) >> 1;
            if ((nums[mid] == target && mid == 0) || (nums[mid] == target && nums[mid - 1] != target))
            {
                ansL = mid;
                break;
            }
            if (nums[mid] > target || (nums[mid] == target && nums[mid - 1] == target))
            {
                r = mid - 1;
            }
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
        }
        l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (r + l) >> 1;
            if ((nums[mid] == target && mid == nums.size() - 1) || (nums[mid] == target && nums[mid + 1] != target))
            {
                ansR = mid;
                break;
            }
            if (nums[mid] > target)
            {
                r = mid - 1;
            }
            if (nums[mid] < target || (nums[mid] == target && nums[mid + 1] == target))
            {
                l = mid + 1;
            }
        }
        v.push_back(ansL);
        v.push_back(ansR);
        return v;
    }
};
