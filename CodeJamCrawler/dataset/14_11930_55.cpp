package main

import (
    //"io"
    "os"
    "bufio"
    "fmt"
    "strconv"
    "strings"
)

func solve(C, F, X float64) float64 {
    curRate := 2.0
    curTime := 0.0

    for true {
        timeToFinish := X/curRate
        farmTimeToFinish := (X/(curRate+F)) + (C/curRate)

        if farmTimeToFinish < timeToFinish {
            curTime += C/curRate
            curRate += F
        } else {
            return curTime + X/curRate
        }
    }
    return 0
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
    
    numLines, _ := strconv.Atoi(scanner.Text())

    for i := 1; i <= numLines; i++ {
        scanner.Scan()
        line := scanner.Text()
        splitLine := strings.Split(line, " ")
        
        C, _ := strconv.ParseFloat(splitLine[0], 64)
        F, _ := strconv.ParseFloat(splitLine[1], 64)
        X, _ := strconv.ParseFloat(splitLine[2], 64)

        fmt.Printf("Case #%d: %f\n", i, solve(C, F, X))
}
}