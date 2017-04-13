package main

import (
	"fmt"
	"os"
)

func main() {
	// Read cases from standard input
	var seqs [][]Instruction
	var err os.Error
	if seqs, err = readInput(); err != nil {
		//fmt.Print("Error: ", err)
		os.Exit(-1)
	}

	// Execute all cases
	for i, seq := range seqs {
		// Create our machinations
		robots := make(map[string]*Robot)
		robots["O"] = &Robot{name: "O", pos: 1, instructions: make([]*RobotInstruction, 0, 10)}
		robots["B"] = &Robot{name: "B", pos: 1, instructions: make([]*RobotInstruction, 0, 10)}
		totalTime := executeInstructions(robots, seq)
		fmt.Printf("Case #%d: %d\n", i+1, totalTime)
	}

}

func readInput() (seqs [][]Instruction, err os.Error) {
	seqs = make([][]Instruction, 0, 10)
	var numSeqs int

	// Attempt to read number of sequences from input, fail on error
	if _, err = fmt.Scanf("%d", &numSeqs); err != nil {
		return
	}
	for s := 0; s < numSeqs; s++ {
		var numInstructions int
		seq := make([]Instruction, 0, 10)

		// Attempt to read number of sequences from input, fail on error
		if _, err = fmt.Scanf("%d", &numInstructions); err != nil {
			return
		}
		// Read each instruction
		for i := 0; i < numInstructions; i++ {
			var ins Instruction

			// Attempt to read instruction, fail on error
			if _, err = fmt.Scanf("%s %d", &ins.robotName, &ins.buttonPos); err != nil {
				return
			}
			// Queue up the instruction
			seq = append(seq, ins)
		}

		// Queue up the sequence (aka, 'case')
		seqs = append(seqs, seq)
	}

	return
}

type Robot struct {
	instructions []*RobotInstruction
	name string
	pos int
	time int
}

type RobotInstruction struct {
	buttonPos int
	startAt chan int
	doneAt chan int
}

type Instruction struct {
	robotName string
	buttonPos int
}

func executeInstructions(robots map[string]*Robot, seq []Instruction) int {
	var doneAt chan int
	startAt := make(chan int)
	go func (startAt chan int) {
		// First robot can start immediately
		startAt <-0
	}(startAt)

	// Iterate over the instructions, executing each one in order, concurrently
	for _, ins := range seq {
		doneAt = make (chan int)

		// Create an instruction for the robot
		r := robots[ins.robotName]
		i := &RobotInstruction{buttonPos: ins.buttonPos, startAt: startAt, doneAt: doneAt}

		// Send the instruction to the robot
		r.instructions = append(r.instructions, i)

		// One robot's done chan is another's start chan
		startAt = doneAt
	}

	for _, r := range robots {
		go func(r *Robot) {
			r.processInstructions()
		}(r)
	}
	// Wait for all robots to finish and find the end time
	return <-doneAt
}

func (r *Robot) processInstructions() {
	for _, i := range r.instructions {
		// Get into position
		r.time += r.moveToButton(i.buttonPos)
		// Wait until it's okay to press
		earliestPushTime := <-i.startAt
		if r.time < earliestPushTime {
			// We did some waiting
			r.time = earliestPushTime
		}

		// Push the button
		r.time += r.pushButton()
		// Signal our completion time
		go func(doneAt chan int, time int) {
			doneAt<-time
		}(i.doneAt, r.time)
	}
}

func (r *Robot) moveToButton(buttonPos int) (time int) {
	// absolute value for an integer
	abs := func(a int) int {
		if a > 0 {
			return a
		}
		return -a
	}
	// Account for seconds required to move to button
	time = abs(r.pos - buttonPos)
	// Robot r is now at button
	r.pos = buttonPos
	return
}

func (r *Robot) pushButton() int {
	// It always takes 1 second to push a button
	return 1
}
