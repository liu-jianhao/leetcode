/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxStep = 0;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            maxStep = max(maxStep, nums[i]);
            if(maxStep == 0)
                return false;
            --maxStep;
        }
        return true;
    }
};
