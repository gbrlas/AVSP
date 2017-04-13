//
//

package main

import (
	"io/ioutil"
	"strconv"
	"fmt"
	"bufio"
	"os"
	"strings"
)

var out = "Case #%d:\n%s"
var pic [][]byte

func main() {
	file, _ := os.Open("input.in")
	input := bufio.NewReader(file)
	str, _, _ := input.ReadLine()
	c, _ := strconv.Atoi(string(str))
	ans := make([]string, c)
	i := 0
	for str, _, err := input.ReadLine(); err == nil; {
		tmp := strings.Fields(string(str))
		no, _ := strconv.Atoi(tmp[0])
		pic = make([][]byte, no)
		for j := 0; j < no; j++ {
			str, _, _ = input.ReadLine()
			pic[j] = str;
		}
		ans[i] = process()
		i++
		str, _, err = input.ReadLine()
	}
	output(ans)
}

func process() string {
	rips := ""
	for i:= 0; i < len(pic) ; i++ {
		for j := 0; j < len(pic[i]); j++ {
			if pic[i][j] == '#' {
				pic[i][j] = '/'
				x,y := j + 1, i + 1
				if len(pic) <= y || len(pic[i]) <= x {
					return "Impossible\n"
				}
				if pic[i][x] != '#' || pic[y][j]  != '#' || pic[y][x] != '#' {
					return "Impossible\n"
				}
				pic[i][x] = '\\' 
				pic[y][j] = '\\'
				pic[y][x] = '/'
			}
		}
	}
	for _, s := range pic {
		rips += fmt.Sprintf("%s\n", s)
	}
	return rips
}


func output(ans []string) {
	str := ""
	for i, v := range ans {
		str += fmt.Sprintf(out, i+1, v)
	}
	ioutil.WriteFile("output.out", []byte(str), 0666)
}
