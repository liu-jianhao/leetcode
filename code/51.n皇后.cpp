/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> subres;
        vector<int> col(n, 0), pie(2*n, 0), na(2*n, 0);
        helper(res, col, pie, na, subres, 0);
        return res;
    }

    void helper(vector<vector<string>>& res, vector<int> col, vector<int> pie, vector<int> na, vector<string> subres, int row)
    {
        int n = col.size();
        if(row == n)
            res.push_back(subres);
        else
        {
            for(int j = 0; j < n; ++j)
            {
                int sum = row + j;
                int dif = row - j + n;
                if(col[j] == 0 && pie[sum] == 0 && na[dif] == 0)
                {
                    string s(n, '.');
                    s[j] = 'Q';
                    subres.push_back(s);
                    col[j] = 1;
                    pie[sum] = 1;
                    na[dif] = 1;
                    helper(res, col, pie, na, subres, row + 1);
                    col[j] = 0;
                    pie[sum] = 0;
                    na[dif] = 0;
                    subres.pop_back();
                }
            }
        }
    }
};
