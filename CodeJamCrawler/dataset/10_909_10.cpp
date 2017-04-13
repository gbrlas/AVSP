package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"strings"
	"container/vector"
)

func main() {
	process("coaster.in")
}

var group struct {
	val []int
}

func process(filename string) {
	file, _ := os.Open(filename, os.O_RDONLY, 0666)
	buffer := bufio.NewReader(file)
	numberOfCase, _ := strconv.Atoi(readLine(buffer))
	results := make([]string, numberOfCase)
	for i := 0; i < numberOfCase; i++ {
		details := strings.Fields(readLine(buffer))
		times, _ := strconv.Atoi(details[0])
		size, _ := strconv.Atoi(details[1])
		groups, _ := strconv.Atoi(details[2])
		results[i] = price(times, size, groups, readLine(buffer))
	}
	output(results, "coaster.out")
}

func price(rides, size, groups int, pple string) string {
	group.val = make([]int, groups)
	for i, s := range strings.Fields(pple) {
		group.val[i], _ = strconv.Atoi(s)
	}
	price := 0
	for rides > 0 {
		p := next(size, rides)
		price += p
		rides -= 1
	}
	return fmt.Sprint(price)
}

func next(size, remaining int) (price int) {
	for i := 0; i < len(group.val); i++ {
		tmp := size - price
		if tmp < group.val[i] {
			part1 := group.val[0:i]
			part2 := group.val[i:len(group.val)]
			regroup := new(vector.IntVector)
			for _, j := range part2 {
				regroup.Push(j)
			}
			for _, j := range part1 {
				regroup.Push(j)
			}
			group.val = regroup.Data()
			return
		}
		price += group.val[i]
	}
	return
}

func readLine(reader *bufio.Reader) (str string) {
	str, _ = reader.ReadString(byte('\n'))
	str = strings.TrimSpace(str)
	return
}

func output(lines []string, filename string) {
	file, _ := os.Open(filename, os.O_CREATE|os.O_RDWR, 0666)
	out := bufio.NewWriter(file)
	for i, line := range lines {
		out.WriteString(fmt.Sprintf("Case #%d: %s\n", i+1, line))
	}
	out.Flush()
	file.Close()
}
