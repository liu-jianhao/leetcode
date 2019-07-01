/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;

        int res = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                res = max(dfs(grid, i, j), res);
            }
        } 
        return res;
    }

    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
        int res = 1;
        grid[i][j] = 0;        
        res += dfs(grid, i+1, j)
            + dfs(grid, i, j+1)
            + dfs(grid, i-1, j)
            + dfs(grid, i, j-1);
        return res;
    }
};

