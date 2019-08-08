
/*
 * @lc app=leetcode.cn id=124 lang=golang
 *
 * [124] 二叉树中的最大路径和
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import "math"

var res int

func maxPathSum(root *TreeNode) int {
	res = math.MinInt32
	getMax(root)
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func getMax(root *TreeNode) int {
	if root == nil {
		return 0
	}

	left := max(0, getMax(root.Left))
	right := max(0, getMax(root.Right))
	res = max(res, root.Val+left+right)
	return max(left, right) + root.Val
}

