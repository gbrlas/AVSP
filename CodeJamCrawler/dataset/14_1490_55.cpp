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
		var guess1, guess2 int
		input.Scan()
		guess1, _ = strconv.Atoi(input.Text())
		for j := 0; j < guess1-1; j++ {
			input.Scan()
			input.Text()
		}
		input.Scan()
		line := input.Text()
		strs := strings.Fields(line)
		for j := guess1; j < 4; j++ {
			input.Scan()
			input.Text()
		}
		input.Scan()
		guess2, _ = strconv.Atoi(input.Text())
		for j := 0; j < guess2-1; j++ {
			input.Scan()
			input.Text()
		}
		input.Scan()
		line = input.Text()
		line = " " + line + " "
		for j := guess2; j < 4; j++ {
			input.Scan()
			input.Text()
		}
		count := 0
		single := ""
		for _, s := range strs {
			if strings.Contains(line, " "+s+" ") {
				count++
				single = s
			}
		}
		switch count {
		case 0:
			ans = append(ans, "Volunteer cheated!")
			break
		case 1:
			ans = append(ans, fmt.Sprint(single))
			break
		default:
			ans = append(ans, "Bad magician!")
		}
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
