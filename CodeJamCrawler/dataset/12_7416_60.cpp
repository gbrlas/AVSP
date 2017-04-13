package main

import (
	"fmt"
)

func main() {
	var cases int
	fmt.Scan(&cases)
	for c := 0; c < cases; c++ {
		var googlers, surprising, score int
		fmt.Scan(&googlers, &surprising, &score)
		scores := make([]int, googlers)
		for g := 0; g < googlers; g++ {
			fmt.Scan(&scores[g])
		}
		ans := numOfHighScores(surprising, score, scores)
		fmt.Printf("Case #%v: %v\n", c+1, ans)
	}
}

func numOfHighScores(surprising, score int, scores []int) (ans int) {
	for _, v := range scores {
		mid := v / 3
		rem := v % 3
		if mid == 0 && rem == 0 && score > 0 {
			continue
		}
		if mid >= score {
			ans++
		} else if mid == 0 && rem > 0 && mid + 1 >= score {
			ans++
		} else if mid == 0 && rem == 2 && mid + 2 >= score  && surprising > 0 {
			ans++
			surprising--
		} else if rem == 1 && mid + 1 >= score {
			ans++
		} else if rem == 2 && mid + 1 >= score {
			ans++
		} else if rem == 2 && mid + 2 >= score  && surprising > 0 {
			ans++
			surprising--
		} else if rem == 0 && mid + 1 >= score  && surprising > 0 {
			ans++
			surprising--
		}
	}
	return
}
