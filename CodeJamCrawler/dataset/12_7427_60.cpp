package main

import (
	"fmt"
	"strconv"
)

type recycledPair struct {
	n, m int
}

func main() {
	var cases int
	fmt.Scan(&cases)
	for c := 0; c < cases; c++ {
		var lower, upper int
		fmt.Scan(&lower, &upper)
		ans := recycledNums(lower, upper)
		fmt.Printf("Case #%v: %v\n", c+1, ans)
	}
}

func recycledNums(lower, upper int) (ans int) {
	for i := lower; i < upper; i++ {
		n := strconv.Itoa(i)
		var dict = make(map[recycledPair]bool)
		for j := 1; j < len(n); j++ {
			m := n[j:len(n)] + n[0:j]
			em, err := strconv.Atoi(m)
			if err != nil {
				continue
			}
			if em <= upper && em > i {
				if !dict[recycledPair{i, em}] {
					dict[recycledPair{i, em}] = true
					ans++
				}
			}
		}
	}
	return
}
