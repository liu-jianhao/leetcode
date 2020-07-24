/*
 * @lc app=leetcode.cn id=35 lang=golang
 *
 * [35] 搜索插入位置
 */

// @lc code=start
func searchInsert(nums []int, target int) int {
	left, right := 0, len(nums)-1
	res := len(nums)
	for left <= right {
		mid := left + (right - left) / 2 
		if nums[mid] >= target {
			res = mid
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return res
}
// @lc code=end

