package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func Readln(r *bufio.Reader) (string, error) {
	var (
		isPrefix bool  = true
		err      error = nil
		line, ln []byte
	)
	for isPrefix && err == nil {
		line, isPrefix, err = r.ReadLine()
		ln = append(ln, line...)
	}
	return string(ln), err
}

func to_uinteger(numstr string) uint64 {
	var numbr uint64
	var err error
	numbr, err = strconv.ParseUint(numstr, 10, 64)
	if err != nil {
		fmt.Println("could not convert to integer")
		fmt.Println(err)
		os.Exit(1)
	}
	return numbr
}

func magictrick(inputfile string, outputfile string) {
	var fh_out *os.File
	var fh_original *os.File
	var fh_in *bufio.Reader
	var err error
	var in_line string
	var test_cases uint64
	var number uint64
	var board uint64
	var i uint64
	var j uint64
	var answers [2]uint64
	var cards []string
	var arrangement [32]uint64
	var matchcount uint64
	var matchvalue uint64
	var lookingfor uint64
	var result string
	fh_out, err = os.Create(outputfile)
	if err != nil {
		fmt.Printf("Could not open outputfile: %s", outputfile)
		return
	}
	defer fh_out.Close()
	fh_original, err = os.Open(inputfile)
	if err != nil {
		fmt.Printf("Not found: %s", inputfile)
		return
	}
	defer fh_original.Close()
	fh_in = bufio.NewReader(fh_original)
	in_line, err = Readln(fh_in)
	if err != nil {
		fmt.Println(err)
		return
	}
	test_cases = to_uinteger(in_line)
	for number = 1; number <= test_cases; number++ {
		for board = 0; board < 2; board++ {
			in_line, err = Readln(fh_in)
			if err != nil {
				fmt.Println(err)
				return
			}
			answers[board] = to_uinteger(in_line)
			for i = 0; i < 4; i++ {
				in_line, err = Readln(fh_in)
				cards = strings.Split(in_line, " ")
				for j = 0; j < 4; j++ {
					arrangement[(board * 16) + (i * 4) + j] = to_uinteger(cards[j])
				}
			}
		}
		matchcount = 0
		for i = 0; i < 4; i++ {
			lookingfor = arrangement[((answers[0] - 1)*4) + i]
			for j = 0; j < 4; j++ {
				if arrangement[((answers[1] - 1)*4) + j + 16] == lookingfor {
					matchcount++
					matchvalue = lookingfor
				}
			}
		}
		result = "Volunteer cheated!"
		if matchcount == 1 {
			result = strconv.FormatUint(matchvalue, 10)
		}
		if matchcount > 1 {
			result = "Bad magician!"
		}
		_, err = fmt.Fprintf(fh_out, "Case #%d: %s\n", number, result)
		if err != nil {
			fmt.Println("Error on output")
		}
	}
}

func main() {
	var file_base string
	var inputfile string
	var outputfile string

	file_base = "A-small-attempt0"
	inputfile = file_base + ".in"
	outputfile = file_base + ".out"
	magictrick(inputfile, outputfile)
}
