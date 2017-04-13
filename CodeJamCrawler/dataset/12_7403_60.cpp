package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var cases int
	fmt.Scan(&cases)
	r := bufio.NewReaderSize(os.Stdin, 1000)
	for c := 0; c < cases; c++ {
		line,_,_ := r.ReadLine()
		ans := translate(line)
		fmt.Printf("Case #%v: %v\n", c+1, ans)
	}
}

func translate(line []byte) (s string) {
	for _, v := range line {
		switch v {
		case 'a', 'A':
			s += "y"
		case 'b', 'B':
			s += "h"
		case 'c', 'C':
			s += "e"
		case 'd', 'D':
			s += "s"
		case 'e', 'E':
			s += "o"
		case 'f', 'F':
			s += "c"
		case 'g', 'G':
			s += "v"
		case 'h', 'H':
			s += "x"
		case 'i', 'I':
			s += "d"
		case 'j', 'J':
			s += "u"
		case 'k', 'K':
			s += "i"
		case 'l', 'L':
			s += "g"
		case 'm', 'M':
			s += "l"
		case 'n', 'N':
			s += "b"
		case 'o', 'O':
			s += "k"
		case 'p', 'P':
			s += "r"
		case 'q', 'Q':
			s += "z"
		case 'r', 'R':
			s += "t"
		case 's', 'S':
			s += "n"
		case 't', 'T':
			s += "w"
		case 'u', 'U':
			s += "j"
		case 'v', 'V':
			s += "p"
		case 'w', 'W':
			s += "f"
		case 'x', 'X':
			s += "m"
		case 'y', 'Y':
			s += "a"
		case 'z', 'Z':
			s += "q"
		default:
			s += " "
		}
	}
	return
}
