/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 > len2)
            return findMedianSortedArrays(nums2, nums1);

        int k = (len1 + len2 + 1) / 2;
        int left = 0;
        int right = len1;
        int m1, m2;
        while(left < right)
        {
            m1 = left + (right - left) / 2;
            m2 = k - m1;
            if(nums1[m1] < nums2[m2-1])
                left = m1 + 1;
            else
                right = m1;
        }

        m1 = left;
        m2 = k - m1;
        int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1-1], m2 <= 0 ? INT_MIN : nums2[m2-1]);
        if((len1 + len2) & 1 == 1)
        {
            return c1;
        }
        int c2 = min(m1 >= len1 ? INT_MAX : nums1[m1], m2 >= len2 ? INT_MAX : nums2[m2]);
        return (c1 + c2) * 0.5;
    }
};

