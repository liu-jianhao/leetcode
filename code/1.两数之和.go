/*
 * @lc app=leetcode.cn id=1 lang=golang
 *
 * [1] 两数之和
 */

// @lc code=start
func twoSum(nums []int, target int) []int {
	ret := make([]int, 2)
	m := make(map[int]int)
	for i, n := range nums {
		if v, ok := m[target - n]; ok {
			ret[0] = v
			ret[1] = i
			break
		}
		m[n] = i
	}	
	return ret
}
// @lc code=end

