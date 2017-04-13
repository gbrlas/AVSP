package main

import (
	"fmt"
)

func cons(r rune) bool {
	return r != 'a' && r != 'e' && r != 'i' && r != 'o' && r != 'u'
}

func solve() (ans int64) {
	var name string
	var n int
	fmt.Scan(&name, &n)
	seq, lastSeq := 0, -1
	for i, c := range name {
		if cons(c) {
			seq++
			if seq >= n {
				lastSeq = i - n + 1
			}
		} else {
			seq = 0
		}
		ans += int64(lastSeq + 1)
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
