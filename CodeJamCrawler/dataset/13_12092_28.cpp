package main

import (
	"fmt"
)

var N, P, lim int64

func search(n int64, f func(int64) bool) int64 {
	i, j := int64(0), int64(n)
	for i < j {
		h := i + (j-i)/2
		if !f(h) {
			i = h + 1
		} else {
			j = h
		}
	}
	return i
}

func good(me int64) (rank int64) {
	var sub int64
	for r := int64(2); r <= lim; r *= 2 {
		if me >= lim-r+1+sub {
			sub += r / 2
			rank += lim / r
		}
	}
	return
}

func bad(me int64) (rank int64) {
	var sub int64
	for r := int64(2); r <= lim; r *= 2 {
		if me < r - 1 - sub {
			sub += r / 2
		} else {
			rank += lim / r
		}
	}
	return
}

func solveY() (ans int64) {
	return search(lim, func(i int64) bool {
		return bad(i) >= P
	}) - 1
}

func solveZ() (ans int64) {
	return search(lim, func(i int64) bool {
		return good(i) >= P
	}) - 1
}

func main() {
	var T int
	fmt.Scan(&T)
	for i := 1; i <= T; i++ {
		fmt.Scan(&N, &P)
		lim = int64(1) << uint(N)
		fmt.Printf("Case #%d: %d %d\n", i, solveY(), solveZ())
	}
}
