package main

import (
	"fmt"
)

func solve() (ans int) {
	var E, R, N int
	fmt.Scan(&E, &R, &N)
	gain := make([]int, E + 1)
	for ; N > 0; N-- {
		var v int
		fmt.Scan(&v)
		if R >= E {
			ans += v * E
			continue
		}
		prev := make([]int, E + 1)
		copy(prev, gain)
		for i := R; i <= E; i++ {
			gain[i] = prev[i - R]
			for j := i - R + 1; j <= E; j++ {
				if next := prev[j] + (j - (i - R)) * v; next > gain[i] {
					gain[i] = next
				}
			}
		}
	}
	for _, i := range gain {
		if i > ans {
			ans = i
		}
	}
	return
}

func main() {
	var T int
	fmt.Scan(&T)
	for i := 1; i <= T; i++ {
		fmt.Printf("Case #%d: %d\n", i, solve())
	}
}
