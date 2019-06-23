/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return image;
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor)
    {
        if(sr < image.size() && sr >= 0 && sc < image[0].size() && sc >= 0 
            && image[sr][sc] == oldColor)
        {
            image[sr][sc] = newColor;
            dfs(image, sr-1, sc, newColor, oldColor);
            dfs(image, sr, sc-1, newColor, oldColor);
            dfs(image, sr+1, sc, newColor, oldColor);
            dfs(image, sr, sc+1, newColor, oldColor);
        }
    }
};

