#
# @lc app=leetcode.cn id=1004 lang=python
#
# [1004] 最大连续1的个数 III
#
class Solution(object):
    def longestOnes(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        res = 0
        count = l = 0
        for r in range(len(A)):
            if A[r] == 1:
                count += 1
            while r - l + 1 - count > K:
                if A[l] == 1:
                    count -= 1
                l += 1
            res = max(res, r - l + 1)
        return res
        

