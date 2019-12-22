/*
 * @lc app=leetcode.cn id=13 lang=golang
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
func romanToInt(s string) int {
	m := make(map[byte]int)
	m['I'] = 1
	m['V'] = 5
	m['X'] = 10
	m['L'] = 50
	m['C'] = 100
	m['D'] = 500
	m['M'] = 1000

	tmp := 0
	res := 0
	for i := 0; i < len(s); i++ {
		if i+1 < len(s) && m[s[i]] < m[s[i+1]] {
			tmp = m[s[i+1]] - m[s[i]]
			i++
		} else {
			tmp = m[s[i]]
		}
		res += tmp
	}
	return res
}

// @lc code=end

