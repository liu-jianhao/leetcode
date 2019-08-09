/*
 * @lc app=leetcode.cn id=459 lang=golang
 *
 * [459] 重复的子字符串
 */
func repeatedSubstringPattern(s string) bool {
	len := len(s)
	for t := 1; t <= len/2; t++ {
		if len%t != 0 {
			continue
		}
		var i int
		for i = t; i < len && s[i] == s[i%t]; i++ {
		}
		if i == len {
			return true
		}
	}
	return false
}

