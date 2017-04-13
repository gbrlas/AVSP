package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func contains(arr []int, num int) bool {
	for _, v := range arr {
		if v == num {
			return true
		}
	}
	return false
}

func solve(matrix1 [][]int, answer1 int, matrix2 [][]int, answer2 int) string {
	candidates := matrix1[answer1-1]
	res := make([]int, 0)
	for _, i := range candidates {
		if contains(matrix2[answer2-1], i) {
			res = append(res, i)
		}
	}

	switch len(res) {
	case 0:
		return "Volunteer cheated!"
	case 1:
		return strconv.FormatInt(int64(res[0]), 10)
	default:
		return "Bad magician!"
	}
}

func parse_matrix(lines []string) [][]int {
	var mat [][]int
	for j := 0; j < 4; j++ {
		var submat []int
		line := strings.Split(lines[j], " ")
		for _, n := range line {
			num, _ := strconv.Atoi(n)
			submat = append(submat, num)
		}
		mat = append(mat, submat)
	}
	return mat
}

func solve_next(scanner *bufio.Scanner) string {
	scanner.Scan()
	answer1, _ := strconv.Atoi(scanner.Text())
	var lines []string
	for i := 0; i < 4; i++ {
		scanner.Scan()
		lines = append(lines, scanner.Text())
	}
	mat1 := parse_matrix(lines)
	scanner.Scan()
	answer2, _ := strconv.Atoi(scanner.Text())

	var lines2 []string
	for i := 0; i < 4; i++ {
		scanner.Scan()
		lines2 = append(lines2, scanner.Text())
	}
	mat2 := parse_matrix(lines2)

	return solve(mat1, answer1, mat2, answer2)
}

func main() {
	file, _ := os.Open("testinput.txt")
	defer file.Close()

	scanner := bufio.NewScanner(file)
	scanner.Scan()
	num_probs, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < num_probs; i++ {
		fmt.Printf("Case #%d: %s\n", i+1, solve_next(scanner))
	}
}
