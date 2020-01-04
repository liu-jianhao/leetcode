#
# @lc app=leetcode.cn id=279 lang=python
#
# [279] 完全平方数
#

# @lc code=start
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        max_num = int(math.floor(n ** 0.5))
        # 列出符合条件的完全平方数
        nums = [i*i for i in range(1, max_num + 1)]
        
        dp = dict()
        dp[0] = 0
        dp[1] = 1
        
        for i in range(1, n + 1):
            dp[i] = n
            for num in nums:
                if i >= num:
                    dp[i] = min(dp[i], dp[i - num] + 1)
                else:
                    break
        return dp[n]
        
# @lc code=end

