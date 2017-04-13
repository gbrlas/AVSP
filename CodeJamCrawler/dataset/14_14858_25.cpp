package main

import "fmt"

func main() {
	var N int
	fmt.Scanf("%d", &N)
	for i := 1; i <= N; i++ {
		var C, F, X float64
		fmt.Scanf("%f %f %f", &C, &F, &X)

		timePassed := float64(0)
		cookiesPerSecond := float64(2)

		for {
			timeToGoal := X / cookiesPerSecond
			timeToGoalWithFarm := (C / cookiesPerSecond) + (X / (cookiesPerSecond + F))
			if timeToGoal < timeToGoalWithFarm {
				timePassed += timeToGoal
				break
			}

			timePassed += (C / cookiesPerSecond)
			cookiesPerSecond += F
		}

		fmt.Printf("Case #%d: %.7f\n", i, timePassed)
	}
}
