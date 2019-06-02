/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
// 转换成二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();

        int left = 0, right = m * n - 1;
        int pivotIdx, pivotEle;
        while(left <= right)
        {
            pivotIdx = left + (right - left) / 2;
            pivotEle = matrix[pivotIdx / n][pivotIdx % n];
            if(pivotEle == target)
                return true;
            else if(pivotEle < target)
                left = pivotIdx + 1;
            else
                right = pivotIdx - 1;
        }

        return false;
    }
};

