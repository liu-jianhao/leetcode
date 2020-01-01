import "sort"

/*
 * @lc app=leetcode.cn id=1122 lang=golang
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
func relativeSortArray(arr1 []int, arr2 []int) []int {
	arr2Map := make(map[int]int)
	notIn := make([]int, 0)

	for _, a := range arr2 {
		arr2Map[a] = 0
	}

	for _, a := range arr1 {
		if _, ok := arr2Map[a]; ok {
			arr2Map[a]++
		} else {
			notIn = append(notIn, a)
		}
	}
	sort.Ints(notIn)

	res := make([]int, 0)
	for _, a := range arr2 {
		for i := 0; i < arr2Map[a]; i++ {
			res = append(res, a)
		}
	}

	for _, n := range notIn {
		res = append(res, n)
	}

	return res
}

// @lc code=end

