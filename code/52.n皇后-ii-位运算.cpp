/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */
class Solution {
    int count = 0;
public:
    int totalNQueens(int n) {
        if(n < 1)
            return 0;
        dfs(n, 0, 0, 0, 0);
        return count;
    }

    void dfs(int n, int row, int cols, int pie, int na)
    {
        if(row >= n)
        {
            ++count;
            return;
        }
        // 得到当前所有空位
        int bits = (~(cols | pie | na)) & ((1 << n)-1);
        while(bits > 0)
        {
            // 取得最低位的1
            int p = bits & -bits;
            dfs(n, row+1, cols|p, (pie|p)<<1, (na|p)>>1);
            // 去掉最低位的1
            bits = bits & (bits-1);
        }
    }
};

