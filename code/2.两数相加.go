/*
 * @lc app=leetcode.cn id=2 lang=golang
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{
		Val: 0,
	}

	cur := dummy

	carry := 0
	for l1 != nil || l2 != nil {
		sum := carry
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}

		carry = sum / 10
		cur.Next = &ListNode{
			Val: sum % 10,
		}
		cur = cur.Next
	}

	if carry > 0 {
		cur.Next = &ListNode{
			Val: 1,
		}
	}

	return dummy.Next
}

// @lc code=end

