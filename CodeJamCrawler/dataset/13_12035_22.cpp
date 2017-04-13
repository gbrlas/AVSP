package main

import (
	"fmt"
	"sort"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func solve() (ans int) {
	var A, N int
	fmt.Scan(&A, &N)
	motes := make([]int, N)
	ans = N
	for i := 0; i < N; i++ {
		fmt.Scan(&motes[i])
	}
	if A == 1 {
		return
	}
	sort.Ints(motes)
	created := 0
	for i := 0; i < N; i++ {
		if motes[i] < A {
			A += motes[i]
		} else {
			ans = min(ans, created + N - i)
			for motes[i] >= A {
				created++
				A += A - 1
			}
			A += motes[i]
		}
	}
	ans = min(ans, created)
	return
}

func main() {
	var T int
	fmt.Scan(&T)
	for i := 1; i <= T; i++ {
		fmt.Printf("Case #%d: %d\n", i, solve())
	}
}
