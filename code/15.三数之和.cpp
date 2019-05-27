/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3)
            return res;
        
        sort(nums.begin(), nums.end());
        
        vector<int> subRes(3);
        for(int a = 0; a < nums.size(); ++a)
        {
            int b = a + 1;
            int c = nums.size()-1;
            while(b < c)
            {
                int sum = nums[a] + nums[b] + nums[c];
                if(sum < 0)
                    ++b;
                else if(sum > 0)
                    --c;
                else
                {
                    subRes[0] = nums[a];
                    subRes[1] = nums[b];
                    subRes[2] = nums[c];
                    res.push_back(subRes);
                    
                    while(b < c && nums[b] == nums[b+1])
                        ++b;
                    while(b < c && nums[c] == nums[c-1])
                        --c;
                    
                    ++b;
                    --c;
                }
            }
            while(a < nums.size()-1 && nums[a] == nums[a+1])
                ++a;
        }
        return res;
    }
};

