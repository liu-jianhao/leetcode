/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> col(n, 0), pie(2*n, 0), na(2*n, 0);
        helper(res, col, pie, na, 0);
        return res;
    }

    void helper(int& res, vector<bool> col, vector<bool> pie, vector<bool> na, int row)
    {
        int n = col.size();
        if(row == n)
            ++res;
        else
        {
            for(int j = 0; j < n; ++j)
            {
                int sum = row + j;
                int dif = row - j + n;
                if(col[j] == 0 && pie[sum] == 0 && na[dif] == 0)
                {
                    col[j] = 1;
                    pie[sum] = 1;
                    na[dif] = 1;
                    helper(res, col, pie, na, row + 1);
                    col[j] = 0;
                    pie[sum] = 0;
                    na[dif] = 0;
                }
            }
        }
    }
};

