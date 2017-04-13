package main

import (
	"os"
	"fmt"
)

type Attract struct {
	bases []byte
	result byte
}

type Oppose []byte


type Case struct {
	attract []Attract // Elements which attract and combine
	oppose []Oppose // Elements which are opposed
	cast []byte // Base elements to invoke
}

func readInput() (cases []Case, err os.Error) {
	cases = make([]Case, 0, 10)
	// Read the number of cases
	var numCases int
	if _, err = fmt.Scan(&numCases); err != nil {
		return
	}

	for i := 0; i < numCases; i++ {
		var thisCase Case
		if thisCase.attract, err = readAttract(); err != nil {
			return
		}

		if thisCase.oppose, err = readOppose(); err != nil {
			return
		}

		if thisCase.cast, err = readCast(); err != nil {
			return
		}
		cases = append(cases, thisCase)
	}

	return
}

func readAttract() (attracts []Attract, err os.Error) {
	attracts = make([]Attract, 0, 10)
	// Read attracting elements
	var numAttract int
	if _, err = fmt.Scan(&numAttract); err != nil || numAttract == 0 {
		return
	}

	var attractStr string
	if _, err = fmt.Scan(&attractStr); err != nil {
		return
	}

	for i := 0; i*3 < numAttract; i+=3 {
		var attract Attract
		attract.bases = []byte{attractStr[i], attractStr[i+1]}
		attract.result = attractStr[i+2]
		attracts = append(attracts, attract)
	}
	return
}

func readOppose() (opposes []Oppose, err os.Error) {
	opposes = make([]Oppose, 0, 10)
	// Read attracting elements
	var numOppose int
	if _, err = fmt.Scan(&numOppose); err != nil || numOppose == 0 {
		return
	}

	for i := 0; i < numOppose; i++ {
		var opposeStr string
		if _, err = fmt.Scan(&opposeStr); err != nil {
			return
		}
		opposes = append(opposes, []byte{opposeStr[0], opposeStr[1]})
	}

	return
}

func readCast() (cast []byte, err os.Error) {
	cast = make([]byte, 0, 10)
	// Read attracting elements
	var numElems int
	if _, err = fmt.Scan(&numElems); err != nil || numElems == 0 {
		return
	}

	var elemStr string
	if _, err = fmt.Scan(&elemStr); err != nil {
		return
	}

	if len(elemStr) != numElems {
		err = os.ErrorString("Wrong number of elements")
		return
	}
	cast = []byte(elemStr)
	return
}

func main() {
	var err os.Error
	var cases []Case
	if cases, err = readInput(); err != nil {
		fmt.Printf("Error: %v\n", err)
		return
	}

	for i, cast := range cases {
		remain := cast.invoke()
		fmt.Printf("Case #%d: [", i+1)
		for i, elem := range remain {
			fmt.Printf("%c", elem)
			if i < len(remain)-1 {
				fmt.Print(", ")
			}
		}
		fmt.Print("]\n")
	}
}

func (this *Case) invoke() (remain []byte) {
	remain = make([]byte, 0, 10)
	for i := range this.cast {
		element := this.cast[i]

		// Handle attraction
		if len(remain) > 0 {
			prevElem := remain[len(remain)-1]
			reacted := false
			var result byte
			if result, reacted = this.handleAttraction(prevElem, element); reacted {
				// Swap the last element for the result
				remain[len(remain)-1] = result
				continue
			}

			// Handle opposition
			if remain, reacted = this.handleOpposition(remain, element); reacted {
				continue
			}
		}

		// Add to remaining elements in cauldron
		remain = append(remain, element)
	}

	return
}

func (this *Case) handleAttraction(a, b byte) (result byte, reacted bool) {
	for _, combo := range this.attract {
		// Do the elements mix to form a different result?
		if (a == combo.bases[0] && b == combo.bases[1]) || (a == combo.bases[1] && b == combo.bases[0]) {
			reacted = true
			result = combo.result
			return
		}
	}

	return
}

func (this *Case) handleOpposition(remain []byte, element byte) (result []byte, reacted bool) {
	contains := func (str []byte, elem byte) bool {
		for i := range str {
			if str[i] == elem {
				return true
			}
		}
		return false
	}

	for _, combo := range this.oppose {
		if (element == combo[0] && contains(remain, combo[1])) || (element == combo[1] && contains(remain, combo[0])) {
			remain = make([]byte, 0, 10)
			reacted = true
			return
		}
	}

	result = remain
	return
}
