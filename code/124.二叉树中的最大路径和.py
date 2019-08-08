#
# @lc app=leetcode.cn id=124 lang=python
#
# [124] 二叉树中的最大路径和
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import sys

class Solution(object):
    res = -sys.maxsize - 1
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.getMax(root)
        return self.res
    
    def getMax(self, root):
        if root == None:
            return 0
        
        left = max(0, self.getMax(root.left))
        right = max(0, self.getMax(root.right))

        self.res = max(self.res, root.val + left + right)
        return max(left, right) + root.val
        

