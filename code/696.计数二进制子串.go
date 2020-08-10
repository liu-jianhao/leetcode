/*
 * @lc app=leetcode.cn id=696 lang=golang
 *
 * [696] 计数二进制子串
 */

// @lc code=start
func countBinarySubstrings(s string) int {
	array := make([]int, 0)
	p := 0
	n := len(s)
	for p < n {
		count := 0
		c := s[p]
		for p < n && c == s[p] {
			count++
			p++
		}
		array = append(array, count)
	}

	res := 0
	for i := 0; i < len(array)-1 ;i++ {
		res += min(array[i], array[i+1])
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
// @lc code=end

