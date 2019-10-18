/*
 * @lc app=leetcode.cn id=771 lang=golang
 *
 * [771] 宝石与石头
 */

// @lc code=start
func numJewelsInStones(J string, S string) int {
	m := make(map[rune]int)
	for _, c := range J {
		m[c]++
	}

	count := 0
	for _, c := range S {
		if _, ok := m[c]; ok {
			count++
		}
	}
	return count
}

// @lc code=end

