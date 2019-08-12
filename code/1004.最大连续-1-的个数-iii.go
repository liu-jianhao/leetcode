/*
 * @lc app=leetcode.cn id=1004 lang=golang
 *
 * [1004] 最大连续1的个数 III
 */
func longestOnes(A []int, K int) int {
	res := 0
	count, l := 0, 0
	for r := 0; r < len(A); r++ {
		if A[r] == 1 {
			count++
		}
		for r-l+1-count > K {
			if A[l] == 1 {
				count--
			}
			l++
		}
		if res < r-l+1 {
			res = r - l + 1
		}
	}
	return res
}

