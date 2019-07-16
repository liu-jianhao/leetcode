/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty())
            return 0;

        int res = 0, cur = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for(int n : nums)
        {
            cur += n;     
            res += map.find(cur-k) == map.end() ? 0 : map[cur - k];
            ++map[cur];
        }
        return res;
    }
};

