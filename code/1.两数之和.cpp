/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] ????
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.empty())
            return res;

        unordered_multimap<int, int> hash;
        for(int i = 0; i < nums.size(); ++i)
            hash.insert(make_pair(nums[i], i));

        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = hash.find(target - nums[i]);
            if(it != hash.end() && it->second != i)
            {
                res.push_back(i);
                res.push_back(it->second);
                break;
            }
        }

        return res;
    }
};

