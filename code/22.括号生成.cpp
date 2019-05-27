/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, n);
        return res;
    }

    void helper(vector<string>& res, string sub, int left, int right)
    {
        if(left == 0 && right == 0)
        {
            res.push_back(sub);
            return;
        }

        if(left > 0)
            helper(res, sub+"(", left-1, right);
            
        if(right > left)
            helper(res, sub+")", left, right-1);
    }
};

