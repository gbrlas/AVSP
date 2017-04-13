package main

import "fmt"

func solve(n int) {
	r := make([]int, 4)
	possible := []int{}

	var first int
	fmt.Scanf("%d", &first)
	for i := 1; i <= 4; i++ {
		fmt.Scanf("%d %d %d %d", &r[0], &r[1], &r[2], &r[3])
		if i == first {
			possible = append(possible, r...)
		}
	}

	found := false
	y := -1
	bad_magician := false

	var second int
	fmt.Scanf("%d", &second)
	for i := 1; i <= 4; i++ {
		fmt.Scanf("%d %d %d %d", &r[0], &r[1], &r[2], &r[3])
		if i == second {
			for _, h := range r {
				for _, g := range possible {
					if h == g {
						if found {
							bad_magician = true
							break
						}

						found = true
						y = g
						break
					}
				}
			}
		}
	}

	if bad_magician {
		fmt.Printf("Case #%d: Bad magician!\n", n)
	} else if found {
		fmt.Printf("Case #%d: %d\n", n, y)
	} else {
		fmt.Printf("Case #%d: Volunteer cheated!\n", n)
	}
}

func main() {
	var N int
	fmt.Scanf("%d", &N)
	for i := 1; i <= N; i++ {
		solve(i)
	}
}
