package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

var out = "Case #%d: %s\n"

func main() {
	var ans []string
	f, _ := os.Open("input.in")
	input := bufio.NewScanner(f)
	input.Scan()
	l := input.Text()
	n, _ := strconv.Atoi(strings.TrimSpace(l))
	for i := 0; i < n; i++ {
		input.Scan()
		line := input.Text()
		strs := strings.Fields(line)
		farmCost, _ := strconv.ParseFloat(strs[0], 64)
		extraRate, _ := strconv.ParseFloat(strs[1], 64)
		target, _ := strconv.ParseFloat(strs[2], 64)
		rate := float64(2)
		duration := float64(0)
		for howLong(rate, target) > farmCost/rate+howLong(rate+extraRate, target) {
			duration += farmCost / rate
			rate += extraRate
		}
		duration += howLong(rate, target)
		ans = append(ans, fmt.Sprintf("%.7f", duration))
	}
	output(ans)
}

func howLong(rate, target float64) float64 {
	return target / rate
}

func output(ans []string) {
	str := ""
	for i, v := range ans {
		str += fmt.Sprintf(out, i+1, v)
	}
	ioutil.WriteFile("output.out", []byte(str), 0666)
}
