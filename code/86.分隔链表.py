#
# @lc app=leetcode.cn id=86 lang=python
#
# [86] 分隔链表
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        while(pre.next != None and pre.next.val < x):
            pre = pre.next

        cur = pre
        while(cur.next != None):
            if(cur.next.val < x):
                next = cur.next
                cur.next = next.next
                next.next = pre.next
                pre.next = next
                pre = next
            else:
                cur = cur.next
        
        return dummy.next
        

