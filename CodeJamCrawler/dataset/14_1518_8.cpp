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
		str := strings.Fields(line)
		a, _ := strconv.Atoi(str[0])
		b, _ := strconv.Atoi(str[1])
		x, _ := strconv.Atoi(str[2])
		count := 0
		for j := 0; j < a; j++ {
			for k := 0; k < b; k++ {
				if j&k < x {
					count++
				}
			}
		}
		ans = append(ans, fmt.Sprint(count))
	}
	output(ans)
}

func output(ans []string) {
	str := ""
	for i, v := range ans {
		str += fmt.Sprintf(out, i+1, v)
	}
	ioutil.WriteFile("output.out", []byte(str), 0666)
}
