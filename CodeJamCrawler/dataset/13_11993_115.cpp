package main

import "fmt"

func solve() string {
	var N, M int
	fmt.Scan(&N, &M)
	board := make([][]int, N)
	result := make([][]bool, N)
	for i := range board {
		board[i] = make([]int, M)
		result[i] = make([]bool, M)
		for j := range board[i] {
			fmt.Scan(&board[i][j])
		}
	}
	for i := range board {
		max := 0
		for _, k := range board[i] {
			if k > max {
				max = k
			}
		}
		for j, k := range board[i] {
			if k == max {
				result[i][j] = true
			}
		}
	}
	for j := range board[0] {
		max := 0
		for i := range board {
			if k := board[i][j]; k > max {
				max = k
			}
		}
		for i := range board {
			if k := board[i][j]; k == max {
				result[i][j] = true
			}
		}
	}
	for i := range result {
		for _, k := range result[i] {
			if !k {
				return "NO"
			}
		}
	}
	return "YES"
}

func main() {
	var T int
	fmt.Scan(&T)
	for i := 1; i <= T; i++ {
		fmt.Printf("Case #%d: %s\n", i, solve())
	}
}
