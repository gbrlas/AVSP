package main

import (
	"fmt"
	"sort"
)

const MAX = 9223372036854775807

func solve() int {
	var r, t int64
	fmt.Scan(&r, &t)
	return sort.Search(800000000, func(i int) bool {
		x := int64(i)
		return 2 * x > (t + r - 1) / r || 2 * r * x + (2 * x - 1) * x > t
	}) - 1
}

func main() {
	var T int
	fmt.Scan(&T)
	for i := 1; i <= T; i++ {
		fmt.Printf("Case #%d: %d\n", i, solve())
	}
}
