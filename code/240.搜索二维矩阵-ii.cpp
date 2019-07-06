/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        
        int row = 0;
        int col = matrix[0].size()-1;
        while(row <= matrix.size()-1 && col >= 0)
        {
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col] < target)
                row++;
            else if(matrix[row][col] > target)
                col--;
                
        }
        return false;
    }
};

