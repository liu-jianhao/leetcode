/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0;
        for(int count = 0, l = 0, r = 0; r < A.size(); ++r)
        {
            if(A[r] == 1)
                ++count;
            while(r - l + 1 - count > K)
                if(A[l++])
                    --count;
            res = max(res, r-l+1);
        }
        return res;
    }
};

