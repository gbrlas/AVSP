package main

import (
	"bufio"
	"fmt"
	"math"
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
	numbr, err := strconv.ParseUint(numstr, 10, 64)
	if err != nil {
		fmt.Println("could not convert to integer")
		fmt.Println(err)
		os.Exit(1)
	}
	return numbr
}

func integersquareroot(number uint64) uint64 {
	floatver := float64(number)
	floatsq := math.Sqrt(floatver)
	intresult := uint64(floatsq)
	return intresult
}

func is_palindrome(square uint64) bool {
	strform := strconv.FormatUint(square, 10)
	lx := len(strform)
	i := 0
	j := lx - 1
	for j > 0 {
		if strform[i] != strform[j] {
			return false
		}
		i++
		j--
		if j < i {
			return true
		}
	}
	return true
}

func fairsquare(inputfile string, outputfile string) {
	var number uint64
	var count uint64
	var square uint64
	var difference uint64
	var root uint64
	fh_out, err := os.Create(outputfile)
	if err != nil {
		fmt.Printf("Could not open outputfile: %s\n", outputfile)
		return
	}
	fh_original, err := os.Open(inputfile)
	if err != nil {
		fmt.Printf("Not found: %s\n", inputfile)
		fh_out.Close()
		return
	}
	fh_in := bufio.NewReader(fh_original)
	in_line, err := Readln(fh_in)
	if err != nil {
		fmt.Println(err)
		fh_original.Close()
		fh_out.Close()
		return
	}
	test_cases := to_uinteger(in_line)
	for number = 1; number <= test_cases; number++ {
		in_line, err = Readln(fh_in)
		bounds := strings.Split(in_line, " ")
		low_bound_str := bounds[0]
		high_bound_str := bounds[1]
		lowbound := to_uinteger(low_bound_str)
		highbound := to_uinteger(high_bound_str)
		lowsqrt := integersquareroot(lowbound)
		lowsqrt = lowsqrt - 1
		highsqrt := integersquareroot(highbound)
		highsqrt = highsqrt + 2
		count = 0
		square = lowsqrt * lowsqrt
		difference = (2 * lowsqrt) + 1
		root = lowsqrt
		for square < lowbound {
			root++
			square = square + difference
			difference = difference + 2
		}
		for square <= highbound {
			if is_palindrome(root) {
				if is_palindrome(square) {
					count++
				}
			}
			root++
			square = square + difference
			difference = difference + 2
		}
		result := fmt.Sprintf("%d", count)
		_, err = fmt.Fprintf(fh_out, "Case #%d: %s\n", number, result)
		if err != nil {
			fmt.Println("Error on output")
		}

	}
	fh_original.Close()
	fh_out.Close()
}

func main() {
	file_base := "C-small-attempt0"
	inputfile := file_base + ".in"
	outputfile := file_base + ".out"
	fairsquare(inputfile, outputfile)
}
