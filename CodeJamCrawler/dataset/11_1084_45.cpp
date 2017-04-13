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
	"sort"
)

var out = "Case #%d: [%s]\n"

type comb []string

func (me *comb) combine(s1, s2 string) string {
	tmp := []string{s1, s2}
	tm := make([]string, 2)
	sort.SortStrings(tmp)
	for _, v := range *me {
		tm = strings.Split(v, "", -1)[0:2]
		sort.SortStrings(tm)
		if strings.Join(tmp, "") == strings.Join(tm, "") {
			//fmt.Println(tm, tmp)
			return strings.Split(v, "", -1)[2]
		}
	}
	return ""
}

func perm(str string) []string {
	n := 0
	for i := len(str) - 1; i > 0; i-- {
		n += i
	}
	p := make([]string, n)
	for i, k := 0, 0; k < n && i < len(str)-1; i++ {
		for j := i + 1; j < len(str); j++ {
			p[k] = str[i:i+1] + str[j:j+1]
			k++
		}
	}
	return p
}

type opp []string

func (me *opp) opposed(str string) bool {
	tmp := strings.Split(str, "", -1)
	tm := make([]string, 2)
	sort.SortStrings(tmp)
	for _, v := range *me {
		tm = strings.Split(v, "", -1)
		sort.SortStrings(tm)
		if strings.Join(tmp, "") == strings.Join(tm, "") {
			return true
		}
	}
	return false
}

var opposed = &opp{}
var combinatns = &comb{}


func main() {
	file, _ := os.Open("input.in")
	input := bufio.NewReader(file)
	str, _, _ := input.ReadLine()
	cases, _ := strconv.Atoi(string(str))
	ans := make([]string, cases)
	i := 0
	for str, _, err := input.ReadLine(); err == nil; {
		line := strings.Fields(string(str))
		c, _ := strconv.Atoi(line[0])
		*combinatns = line[1 : c+1]
		d, _ := strconv.Atoi(line[c+1])
		*opposed = line[c+2 : c+2+d]
		//n := line[c+2+d]
		base := line[c+3+d]
		ans[i] = process(base)
		i++
		str, _, err = input.ReadLine()
	}
	output(ans)
}

func process(base string) string {
	set := ""
	add := func(s string) {
		set += s
	}
	clear := func() {
		set = ""
	}
	combine := func() bool {
		s1 := set[len(set)-2 : len(set)-1]
		s2 := set[len(set)-1 : len(set)]
		c := combinatns.combine(s1, s2)
		if c != "" {
			set = set[:len(set)-2]
			add(c)
			return true
		}
		return false
	}
	for i := 0; i < len(base); i++ {
		add(base[i : i+1])
		if len(set) < 2 {
			continue
		}
		if combine() {
			continue
		}
		for _, v := range perm(set) {
			if opposed.opposed(v) {
				clear()
				break
			}
		}
	}
	return strings.Join(strings.Split(set, "", -1), ", ")
}

func output(ans []string) {
	str := ""
	for i, v := range ans {
		str += fmt.Sprintf(out, i+1, v)
	}
	ioutil.WriteFile("output.out", []byte(str), 0666)
}

