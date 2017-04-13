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

func cookieclickeralpha(inputfile string, outputfile string) {
	var fh_out *os.File
	var fh_original *os.File
	var fh_in *bufio.Reader
	var err error
	var in_line string
	var test_cases uint64
	var test_number uint64
	var result string
	var cfx_str []string
	var c_cookies_buy_farm float64
	var f_per_second float64
	var x_win float64
	var current_time float64
	var current_rate float64
	var fastest_from_now float64
	var min_fastest float64
	var breakloopcount uint64
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
	for test_number = 1; test_number <= test_cases; test_number++ {
		in_line, err = Readln(fh_in)
		if err != nil {
			fmt.Println(err)
			return
		}
		cfx_str = strings.Split(in_line, " ")
		c_cookies_buy_farm, err = strconv.ParseFloat(cfx_str[0], 64)
		if err != nil {
			fmt.Println(err)
			return
		}
		f_per_second, err = strconv.ParseFloat(cfx_str[1], 64)
		if err != nil {
			fmt.Println(err)
			return
		}
		x_win, err = strconv.ParseFloat(cfx_str[2], 64)
		if err != nil {
			fmt.Println(err)
			return
		}
		current_time = 0.0
		current_rate = 2.0
		fastest_from_now = (x_win / current_rate) + current_time
		min_fastest = fastest_from_now
		current_time = current_time + (c_cookies_buy_farm / current_rate)
		breakloopcount = 0
		for current_time < x_win {
			current_rate = current_rate + f_per_second
			fastest_from_now = (x_win / current_rate) + current_time
			if fastest_from_now < min_fastest {
				min_fastest = fastest_from_now
			} else {
				breakloopcount++
				if breakloopcount == 3 {
					x_win = 0 // force loop break
				}
			}
			current_time = current_time + (c_cookies_buy_farm / current_rate)
		}
		result = strconv.FormatFloat(min_fastest, 'f', -1, 64)
		_, err = fmt.Fprintf(fh_out, "Case #%d: %s\n", test_number, result)
		if err != nil {
			fmt.Println("Error on output")
		}
	}
}

func main() {
	var file_base string
	var inputfile string
	var outputfile string

	file_base = "B-large"
	inputfile = file_base + ".in"
	outputfile = file_base + ".out"
	cookieclickeralpha(inputfile, outputfile)
}
