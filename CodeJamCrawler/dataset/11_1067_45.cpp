//
//

package main

import (
	"io/ioutil"
	"strconv"
	"strings"
	"fmt"
	"bufio"
	"os"
)

var out = "Case #%d: %d\n"

type R struct {
	pos  int
	name string
}

var O, B = &R{1, "O"}, &R{1, "B"}

func main() {
	file, _ := os.Open("input.in")
	input := bufio.NewReader(file)
	str, _, _ := input.ReadLine()
	c, _ := strconv.Atoi(string(str))
	ans := make([]int, c)
	i := 0
	for str, _, err := input.ReadLine(); err == nil; {
		d := strings.Fields(string(str))
		cases, _ := strconv.Atoi(d[0])
		d = d[1:]
		ans[i] = process(cases, d)
		i++
		str, _, err = input.ReadLine()
		O.pos, B.pos = 1, 1
	}
	output(ans)
}

func process(n int, moves []string) int {
	num := 0
	for i := 0; i < n; i++ {
		next := moves[i*2]
		pos, _ := strconv.Atoi(moves[i*2+1])
		var n *R
		var w *R
		peek := 0
		if next == "O" {
			n = O
			w = B
			peek = peekNext(moves, i*2, "B")
		} else {
			n = B
			w = O
			peek = peekNext(moves, i*2, "O")
		}
		other := func() {
			if w.pos != peek && peek != 0 {
				tm := peek - w.pos
				relm := 1
				if tm < 0 {
					tm = 0 - tm
					relm = -1
				}
				w.pos += relm
			}
		}
		if n.pos != pos {
			t := pos - n.pos
			rel := 1
			if t < 0 {
				t = 0 - t
				rel = -1
			}
			for j := 0; j <= t; j++ {
				if j < t {
					n.pos += rel
				}
				num++
				other()
			}
		} else {
			num++
			other()
		}
	}
	return num
}

func peekNext(moves []string, index int, robot string) int {
	for i := index; i < len(moves); i += 2 {
		if moves[i] == robot {
			n, _ := strconv.Atoi(moves[i+1])
			return n
		}
	}
	return 0
}

func output(ans []int) {
	str := ""
	for i, v := range ans {
		str += fmt.Sprintf(out, i+1, v)
	}
	ioutil.WriteFile("output.out", []byte(str), 0666)
}

