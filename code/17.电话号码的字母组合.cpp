/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty())
            return res;
        vector<string> table {"","","abc" , "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        int len = digits.size();
        vector<string> v;
        for(int i = 0; i < len; ++i)
        {
            string str = table[digits[i] - '0'];
            v.push_back(str);
        }

        rec(res, "", v);

        return res;
    }

    void rec(vector<string>& res, string subRes, vector<string> v)
    {
        if(subRes.size() == v.size())
        {
            res.push_back(subRes);
            return;
        }

        string cur = v[subRes.size()];
        for(int i = 0; i < cur.size(); ++i)
        {
            rec(res, subRes+cur[i], v);
        }
    }
};

