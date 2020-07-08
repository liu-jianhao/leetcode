/*
你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。

返回的长度需要从小到大排列。

示例：
输入：
shorter = 1
longer = 2
k = 3
输出： {3,4,5,6}

提示：
0 < shorter <= longer
0 <= k <= 100000
*/

/* 解法一：暴力法
type IntSlice []int
func (s IntSlice) Len() int { return len(s) }
func (s IntSlice) Swap(i, j int){ s[i], s[j] = s[j], s[i] }
func (s IntSlice) Less(i, j int) bool { return s[i] < s[j] }

func divingBoard(shorter int, longer int, k int) []int {
    m := make(map[int]int) // 用map去重
    res := make([]int, 0)

    for i := 0; i <= k; i++ {
        j := k-i
        length := shorter * i + longer * j
        if length <= 0 {
            continue
        }
        m[length] = 1
    } 

    for k, _ := range m {
        res = append(res, k)
    }
    sort.Sort(IntSlice(res))
    return res
}
*/

func divingBoard(shorter int, longer int, k int) []int {
    res := make([]int, 0)
    if k == 0 {
        return res
    }
    if shorter == longer {
        return []int{shorter*k}
    }
    for i := 0; i <= k; i++ {
        res = append(res, shorter*(k-i)+longer*i)
    }
    return res
}