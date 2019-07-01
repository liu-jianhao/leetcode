/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
class Solution {
    int partition(vector<int>& nums, int low, int high)
    {
        int left = low++;
        swap(nums[left], nums[left+(high-left)/2]);
        while(low <= high)
        {
            while(low < high && nums[low] >= nums[left])
                ++low;
            while(nums[high] < nums[left])
                --high;
            if(low < high)
                swap(nums[low++], nums[high--]);
            else
                break;
        }
        swap(nums[left], nums[high]);
        return high;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low = 0, high = nums.size() - 1;
        while(low < high)
        {
            int mid = partition(nums, low, high);
            if(mid == (k-1))
                return nums[k-1];
            else if(mid < (k-1) )
                low = mid + 1;
            else
                high = mid - 1;
        }
        return nums[k-1];
    }
};

