/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.empty())
            nums1 = nums2;
        if(nums2.empty())
            return;
        
        int cur1 = m - 1;
        int cur2 = n - 1;
        int end = m + n - 1;

        while(cur2 >= 0)
        {
            if(cur1 >= 0 && nums2[cur2] < nums1[cur1])
                nums1[end--] = nums1[cur1--];
            else
                nums1[end--] = nums2[cur2--];
        }
    }
};

