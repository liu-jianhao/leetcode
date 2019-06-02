/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] ????
 */
// ???????????O(1)??????
// [, i): 0 
// [i, j]: 1
// (k, ...]: 2
// Once j meets k, the sorting is complete
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = i, k = nums.size()-1;

        while(j <= k)
        {
            if(nums[j] == 0)
                swap(nums[i++], nums[j++]);
            else if(nums[j] == 1)
                j++;
            else
                swap(nums[j], nums[k--]);
        }
    }
};

