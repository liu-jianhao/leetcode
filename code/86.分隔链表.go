/*
 * @lc app=leetcode.cn id=86 lang=golang
 *
 * [86] 分隔链表
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
	dummy := ListNode{
		Val:  0,
		Next: head,
	}

	pre := &dummy
	for pre.Next != nil && pre.Next.Val < x {
		pre = pre.Next
	}

	cur := pre
	for cur.Next != nil {
		if cur.Next.Val < x {
			next := cur.Next
			cur.Next = next.Next
			next.Next = pre.Next
			pre.Next = next
			pre = next
		} else {
			cur = cur.Next
		}
	}

	return dummy.Next
}

