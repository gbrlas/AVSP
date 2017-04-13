package main

import (
    //"io"
    "os"
    "bufio"
    "fmt"
    "strconv"
    "strings"
    "sort"
)

func solve_d(naomi, ken []float64) int {
    found := 0

    for naomiIndex := 0; naomiIndex < len(naomi); naomiIndex++ {
        for kenIndex := 0; kenIndex < len(ken); kenIndex++ {
            if (naomi[naomiIndex] > ken[kenIndex]) {
                if (ken[kenIndex] != -1.0) {
                    found += 1
                    ken[kenIndex] = -1.0
                    break
                }
            } else {
                break
            }
        }
    }

    return found
}

func solve_h(naomi, ken []float64) int {
    found := 0
    
    for n := 0; n < len(naomi); n++ {
        index := len(naomi) - 1 - n
        if naomi[index] > ken[index] {
            found += 1
        } else {
            break
        }
    }

    return found
}

func main() {
    fi, err := os.Open(os.Args[1])
    if err != nil { panic(err) }
    
    defer func() {
        if err := fi.Close(); err != nil {
            panic(err)
        }
    }()

    scanner := bufio.NewScanner(fi)
    scanner.Scan()
    
    numTests, _ := strconv.Atoi(scanner.Text())

    for i := 1; i <= numTests; i++ {
        scanner.Scan()
        numBlocks, _ := strconv.Atoi(scanner.Text())

        scanner.Scan()
        naomiLine := strings.Split(scanner.Text(), " ")

        scanner.Scan()
        kenLine := strings.Split(scanner.Text(), " ")

        naomi := make([]float64, numBlocks)
        ken := make([]float64, numBlocks)

        for index, section := range naomiLine {
            res, _ := strconv.ParseFloat(section, 64)
            naomi[index] = res
        }

        for index, section := range kenLine {
            res, _ := strconv.ParseFloat(section, 64)
            ken[index] = res
        }

        sort.Float64s(naomi)
        sort.Float64s(ken)

        naomi_d := make([]float64, numBlocks)
        ken_d := make([]float64, numBlocks)

        naomi_h := make([]float64, numBlocks)
        ken_h := make([]float64, numBlocks)

        copy(naomi_d, naomi)
        copy(naomi_h, naomi)
        copy(ken_d, ken)
        copy(ken_h, ken)

        fmt.Printf("Case #%d: %d %d\n", i, solve_d(naomi_d, ken_d), len(naomi) - solve_d(ken_h, naomi_h))
    }
}