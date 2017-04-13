package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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

func readline(r *bufio.Reader) string {
	var (
		isPrefix bool  = true
		err      error = nil
		line, ln []byte
	)
	for isPrefix && err == nil {
		line, isPrefix, err = r.ReadLine()
		ln = append(ln, line...)
	}
	if err != nil {
		fmt.Println("could not read line.")
		fmt.Println(err)
		os.Exit(1)
	}
	return string(ln)
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

func to_double(numstr string) float64 {
	var rv float64
	var err error

	rv, err = strconv.ParseFloat(numstr, 64)
	if err != nil {
		fmt.Println("could not convert to float64")
		fmt.Println(err)
		os.Exit(1)
	}
	return rv
}

func playdwar(number_of_blocks uint64, naomi_blocks []float64, ken_blocks []float64, use_deceit bool) uint64 {
	var naomi_score uint64
	var i uint64
	var lowest_losing uint64
	var losing_found bool

	naomi_score = 0
	if use_deceit {
		losing_found = true // force first run
		for losing_found {
			// naomi plays lowest "losing" block but fakes out ken with highest block
			lowest_losing = number_of_blocks
			losing_found = false
			for i = 0; i < number_of_blocks; i++ {
				if naomi_blocks[i] < ken_blocks[i] {

					if i < lowest_losing {
						lowest_losing = i
						losing_found = true
					}
				}
			}
			if losing_found {
				for i = lowest_losing; i < number_of_blocks-1; i++ {
					naomi_blocks[i] = naomi_blocks[i+1]
				}
				// ken plays highest block
				number_of_blocks--
			}
		}
		// naomi will win all remaining blocks because no lowest losing was found
		naomi_score = number_of_blocks
	} else {

		for number_of_blocks > 0 {
			// naomi always plays highest block
			if naomi_blocks[number_of_blocks-1] > ken_blocks[number_of_blocks-1] {
				naomi_score++
				// ken plays lowest block
				for i = 0; i < number_of_blocks-1; i++ {
					ken_blocks[i] = ken_blocks[i+1]
				}
				number_of_blocks--
			} else {
				// ken plays highest block
				number_of_blocks--
			}
		}

	}
	return naomi_score
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
	var number_of_blocks uint64
	var i uint64
	var naomi_str []string
	var naomi_vals []float64
	var ken_str []string
	var ken_vals []float64
	var copy_of_num_blocks uint64
	var copy_of_naomi_vals []float64
	var copy_of_ken_vals []float64
	var war_naomi_score uint64
	var deceitful_naomi_score uint64

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
	in_line = readline(fh_in)
	test_cases = to_uinteger(in_line)
	for test_number = 1; test_number <= test_cases; test_number++ {
		in_line = readline(fh_in)
		number_of_blocks = to_uinteger(in_line)
		in_line = readline(fh_in)
		naomi_str = strings.Split(in_line, " ")
		naomi_vals = make([]float64, number_of_blocks)
		for i = 0; i < number_of_blocks; i++ {
			naomi_vals[i] = to_double(naomi_str[i])
		}
		in_line = readline(fh_in)
		ken_str = strings.Split(in_line, " ")
		ken_vals = make([]float64, number_of_blocks)
		for i = 0; i < number_of_blocks; i++ {
			ken_vals[i] = to_double(ken_str[i])
		}
		sort.Sort(sort.Float64Slice(naomi_vals))
		sort.Sort(sort.Float64Slice(ken_vals))
		copy_of_num_blocks = number_of_blocks
		copy_of_naomi_vals = make([]float64, number_of_blocks)
		for i = 0; i < number_of_blocks; i++ {
			copy_of_naomi_vals[i] = naomi_vals[i]
		}
		copy_of_ken_vals = make([]float64, number_of_blocks)
		for i = 0; i < number_of_blocks; i++ {
			copy_of_ken_vals[i] = ken_vals[i]
		}
		war_naomi_score = playdwar(copy_of_num_blocks, copy_of_naomi_vals, copy_of_ken_vals, false)
		copy_of_naomi_vals = make([]float64, number_of_blocks)
		for i = 0; i < number_of_blocks; i++ {
			copy_of_naomi_vals[i] = naomi_vals[i]
		}
		copy_of_ken_vals = make([]float64, number_of_blocks)
		for i = 0; i < number_of_blocks; i++ {
			copy_of_ken_vals[i] = ken_vals[i]
		}
		deceitful_naomi_score = playdwar(copy_of_num_blocks, copy_of_naomi_vals, copy_of_ken_vals, true)
		result = strconv.FormatUint(deceitful_naomi_score, 10) + " " + strconv.FormatUint(war_naomi_score, 10)
		_, err = fmt.Fprintf(fh_out, "Case #%d: %s\n", test_number, result)
		if err != nil {
			fmt.Println("Error on output")
		}
	}
	fmt.Println("Done")
}

func main() {
	var file_base string
	var inputfile string
	var outputfile string

	file_base = "D-large"
	inputfile = file_base + ".in"
	outputfile = file_base + ".out"
	cookieclickeralpha(inputfile, outputfile)
}
