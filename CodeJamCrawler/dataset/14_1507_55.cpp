package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"os"
	"sort"
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
		l, _ := strconv.Atoi(line)
		naomi := make([]float64, l)
		input.Scan()
		line = input.Text()
		strs := strings.Fields(line)
		for i, s := range strs {
			naomi[i], _ = strconv.ParseFloat(s, 64)
		}
		ken := make([]float64, l)
		input.Scan()
		line = input.Text()
		strs = strings.Fields(line)
		for i, s := range strs {
			ken[i], _ = strconv.ParseFloat(s, 64)
		}
		normalPlay, ken := playKen(ken, naomi)
		cheatPlay := playNaomi(ken, naomi)
		ans = append(ans, fmt.Sprintf("%d %d", cheatPlay, normalPlay))
	}
	output(ans)
}

func findLarger(list []float64, val float64) int {
	for i, v := range list {
		if v > val {
			return i
		}
	}
	return -1
}

//pass copy
func playKen(ken []float64, naomi []float64) (int, []float64) {
	sort.Float64s(ken)
	count := 0
	newKen := make([]float64, len(naomi))
	for i, v := range naomi {
		l := len(ken)
		if ken[l-1] < v {
			newKen[i] = ken[0]
			ken = del(ken, 0)
		} else {
			pos := findLarger(ken, v)
			newKen[i] = ken[pos]
			ken = del(ken, pos)
			count++
		}
	}
	return len(naomi) - count, newKen
}

func playNaomi(ken []float64, naomi []float64) int {
	// n := naomi
	sort.Float64s(naomi)
	count := 0
	for _, v := range ken {
		l := len(naomi)
		// if n[i] < v {
		if naomi[l-1] < v {
			naomi = del(naomi, 0)
		} else {
			naomi = del(naomi, findLarger(naomi, v))
			count++
		}
	}
	return count
}

func del(list []float64, index int) []float64 {
	if len(list) == 1 {
		return []float64{}
	}
	l := make([]float64, len(list)-1)
	copy(l[:], list[:index])
	if index < len(list)-1 {
		copy(l[index:], list[index+1:])
	}
	return l
}

func output(ans []string) {
	str := ""
	for i, v := range ans {
		str += fmt.Sprintf(out, i+1, v)
	}
	ioutil.WriteFile("output.out", []byte(str), 0666)
}
