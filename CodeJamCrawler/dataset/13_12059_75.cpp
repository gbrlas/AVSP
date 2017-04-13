package main

import (
	"fmt"
)

func cons(r rune) bool {
	return r != 'a' && r != 'e' && r != 'i' && r != 'o' && r != 'u'
}

func solve() {
	var x, y int
	fmt.Scan(&x, &y)
	var a, b rune
	if x > 0 {
		a, b = 'E', 'W'
	} else if x < 0 {
		a, b = 'W', 'E'
	}
	if x != 0 {
		if x < 0 {
			x *= -1
		}
		for i := 1; i < x; i++ {
			fmt.Printf("%c%c", a, b)
		}
		fmt.Printf("%c", a)
	}
	if y != 0 {
		if y < 0 {
			a, b = 'N', 'S'
			y *= -1
		} else {
			a, b = 'S', 'N'
		}
		for i := 0; i < y; i++ {
			fmt.Printf("%c%c", a, b)
		}
	}
	fmt.Println()
}

func main() {
	var T int
	fmt.Scan(&T)
	for i := 1; i <= T; i++ {
		fmt.Printf("Case #%d: ", i)
		solve()
	}
}
