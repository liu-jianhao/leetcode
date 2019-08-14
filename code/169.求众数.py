#
# @lc app=leetcode.cn id=169 lang=python3
#
# [169] 求众数
#
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        maj = nums[0]
        for n in nums:
            if n == maj:
                count += 1
            else:
                count -= 1
                if count == 0:
                    maj = n
                    count = 1
        return maj

