/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for(int i = 1; i <= numRows; ++i)
        {
            vector<int> v(i);
            v[0] = 1;
            v[v.size()-1] = 1;
            for(int j = 1; j < v.size()-1; ++j)
            {
                v[j] = res[i-2][j-1] + res[i-2][j];
            }
            res.push_back(v);
        }

        return res;
    }
};

