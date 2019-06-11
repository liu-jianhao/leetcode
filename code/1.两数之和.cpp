/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] ????
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);

        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = hash.find(target - nums[i]);
            if(it != hash.end() && it->second != i)
            {
                res[0] = it->second;
                res[1] = i;
                break;
            }
            hash.insert(make_pair(nums[i], i));
        }

        return res;
    }
};

