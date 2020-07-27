/*
 * @lc app=leetcode.cn id=392 lang=golang
 *
 * [392] 判断子序列
 */

// @lc code=start
func isSubsequence(s string, t string) bool {
    sLen, tLen := len(s), len(t)
    ps, pt := 0, 0
    for ps < sLen && pt < tLen {
        if s[ps] == t[pt] {
            ps++
        }
        pt++
    }
    return ps == sLen
}
// @lc code=end

