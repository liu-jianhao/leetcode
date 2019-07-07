/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int index = INT_MAX;
        while(index >= 40)
            index = 7 * (rand7() - 1) + (rand7() - 1);
        return index % 10 + 1;
    }
};

