/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix.size() == 0 || matrix[0].size() == 0)
            return res;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int count = 0;
        while(rows > count*2 && cols > count*2)
        {
            helper(matrix, res, count, rows, cols);
            ++count;
        }

        return res;
    }

    void helper(const vector<vector<int>>& matrix, vector<int>& res, int count, int rows, int cols)
    {
        int endX = cols - count - 1;
        int endY = rows - count - 1;

        for(int i = count; i <= endX; ++i)
            res.push_back(matrix[count][i]);

        if(count < endY)
            for(int i = count+1; i <= endY; ++i)
                res.push_back(matrix[i][endX]);

        if(count < endX && count < endY)
            for(int i = endX-1; i >= count; --i)
                res.push_back(matrix[endY][i]);

        if(count < endX && count < endY-1)
            for(int i = endY-1; i >= count+1; --i)
                res.push_back(matrix[i][count]);
    }
};

