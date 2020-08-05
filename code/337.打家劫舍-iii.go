/*
 * @lc app=leetcode.cn id=337 lang=golang
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rob(root *TreeNode) int {
	g, f := make(map[*TreeNode]int), make(map[*TreeNode]int)
	dfs(root, g, f)
	return max(g[root], f[root])
}

func dfs(node *TreeNode, g, f map[*TreeNode]int) {
	if node == nil {
		return
	}
	dfs(node.Left, g, f)
	dfs(node.Right, g, f)
	f[node] = node.Val + g[node.Left] + g[node.Right]
	g[node] = max(f[node.Left], g[node.Left]) + max(f[node.Right], g[node.Right])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
// @lc code=end

