package main

import (
	"fmt"
	"sort"
)

const MAX = 100000000000000

var list []int64

func gen() {
	for i := int64(1); i*i <= MAX; i++ {
		if palindrome(i) && palindrome(i*i) {
			list = append(list, i*i)
		}
	}
}

func palindrome(x int64) bool {
	str := fmt.Sprint(x)
	l := len(str)
	for i := 0; i < l-i-1; i++ {
		if str[i] != str[l-i-1] {
			return false
		}
	}
	return true
}

func solve() int {
	var A, B int64
	fmt.Scan(&A, &B)
	return sort.Search(len(list), func(i int) bool {
		return list[i] > B
	}) - sort.Search(len(list), func(i int) bool {
		return list[i] >= A
	})
}

func main() {
	var T int
	fmt.Scan(&T)
	gen()
	for i := 1; i <= T; i++ {
		fmt.Printf("Case #%d: %d\n", i, solve())
	}
}
