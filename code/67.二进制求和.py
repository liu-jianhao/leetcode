#
# @lc app=leetcode.cn id=67 lang=python3
#
# [67] 二进制求和
#

# @lc code=start
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i, j = len(a)-1, len(b)-1
        res = ""
        flag = 0
        while i >= 0 or j >= 0:
            intA, intB = 0, 0
            if i >= 0:
                intA = int(a[i]) - 0
            if j >= 0:
                intB = int(b[j]) - 0
            s = intA + intB + flag
            res = str(s % 2) + res
            flag = s // 2
            i -= 1
            j -= 1
        if flag == 1:
            res = '1' + res
        return res
        
# @lc code=end

