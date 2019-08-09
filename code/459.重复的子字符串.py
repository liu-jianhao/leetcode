#
# @lc app=leetcode.cn id=459 lang=python
#
# [459] 重复的子字符串
#
class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = len(s)
        for t in range(1, l/2+1):
            if l % t != 0:
                continue
            for i in range(t, l):
                if s[i] == s[i%t]:
                    i += 1
                else:
                    break
            if i == l:
                return True
        return False
        

