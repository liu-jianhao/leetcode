/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿的个数
 */
// 这道题和547朋友圈更好的方法是使用并查集
class Solution {
    int ni[4] = {1, -1, 0, 0};
    int nj[4] = {0, 0, -1, 1};
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == '1')
        {
            grid[i][j] = '0';
            for(int k = 0; k < 4; ++k)
            {
                dfs(grid, i + ni[k], j + nj[k]);
            }
        }
    }
};

