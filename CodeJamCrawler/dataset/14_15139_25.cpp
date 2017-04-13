// Google Code Jam 2014 
// Problem A : Magic Trick   
// 
// Recently you went to a magic show. You were very impressed by one of the tricks, so you decided to try to figure out the secret behind it!
//
// The magician starts by arranging 16 cards in a square grid: 4 rows of cards, with 4 cards in each row. Each card has a different number from 1 to 16 written on the side that is showing. Next, the magician asks a volunteer to choose a card, and to tell him which row that card is in.
//
// Finally, the magician arranges the 16 cards in a square grid again, possibly in a different order. Once again, he asks the volunteer which row her card is in. With only the answers to these two questions, the magician then correctly determines which card the volunteer chose. Amazing, right?
//
// You decide to write a program to help you understand the magician's technique. The program will be given the two arrangements of the cards, and the volunteer's answers to the two questions: the row number of the selected card in the first arrangement, and the row number of the selected card in the second arrangement. The rows are numbered 1 to 4 from top to bottom.
//
// Your program should determine which card the volunteer chose; or if there is more than one card the volunteer might have chosen (the magician did a bad job); or if there's no card consistent with the volunteer's answers (the volunteer cheated).
//
// Solving this problem
//
// Usually, Google Code Jam problems have 1 Small input and 1 Large input. This problem has only 1 Small input. Once you have solved the Small input, you have finished solving this problem.
//
// Input
//
// The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line containing an integer: the answer to the first question. The next 4 lines represent the first arrangement of the cards: each contains 4 integers, separated by a single space. The next line contains the answer to the second question, and the following four lines contain the second arrangement in the same format.
//
// Output
//
// For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1).
//
// If there is a single card the volunteer could have chosen, y should be the number on the card. If there are multiple cards the volunteer could have chosen, y should be "Bad magician!", without the quotes. If there are no cards consistent with the volunteer's answers, y should be "Volunteer cheated!", without the quotes. The text needs to be exactly right, so consider copying/pasting it from here.
//
// Limits
//
// 1 ≤ T ≤ 100.
// 1 ≤ both answers ≤ 4.
// Each number from 1 to 16 will appear exactly once in each arrangement.

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include <list> 
#include <cassert> 
using namespace std; 


int main(int argc, char *argv[]) 
{ 
	// Check that we have the right inputs 
	if (argc < 3) 
	{ 
		cout << "[Usage] ProblemA input_file output_file" << endl; 
		return -1; 
	} 

	// Initialize problem variables 
	int numcases = 0; 

	// Initialize auxiliary variables 
	string line, mline; 

	// Open the input and outputfile  
	ifstream inputfile; 
	ofstream outfile; 
	inputfile.open(argv[1]); 
	outfile.open(argv[2]); 

	// Get the number of cases 
	inputfile >> numcases; 
	getline(inputfile, line); 

	// Read through the input 
	int count = 0; 
	while (inputfile.good()) 
	{ 
		count++;  

		// Problem variables 
		int rownum = 0; 
		int curnum = 0; 
		int values[16] = {0}; 
		int ans = -1; 
		int multiple = 0; 

		// Get the row number 
		inputfile >> rownum; 
		getline(inputfile, line); 

		// Skip the first few rows 
		for (int k = 0; k < rownum - 1; k++) 
		{ 
			getline(inputfile, line); 
		} 

		// Get the desired row 
		for (int k = 0; k < 4; k++) 
		{ 
			inputfile >> curnum; 
			values[curnum - 1]++; 
		} 
		getline(inputfile, line); 

		// Skip the rest of the rows 
		for (int k = rownum; k < 4; k++) 
		{ 
			getline(inputfile, line); 
		} 

		// Get the row number 
		inputfile >> rownum; 
		getline(inputfile, line); 

		// Skip the first few rows 
		for (int k = 0; k < rownum - 1; k++) 
		{ 
			getline(inputfile, line); 
		} 

		// Get the desired row 
		for (int k = 0; k < 4; k++) 
		{ 
			inputfile >> curnum; 
			values[curnum - 1]++; 
			if (values[curnum - 1] > 1) 
			{ 
				if (ans >= 0) 
				{ 
					multiple = 1; 
				} else { 
					ans = curnum - 1; 
				} 
			} 
		} 
		getline(inputfile, line); 

		// Skip the rest of the rows 
		for (int k = rownum; k < 4; k++) 
		{ 
			getline(inputfile, line); 
		} 


		// Contains the output for a single line 
		stringstream s; 
		s << "Case #" << count << ": "; 

		if (ans < 0) 
		{ 
			s << "Volunteer cheated!"; 
		} else if (multiple > 0) { 
			s << "Bad magician!"; 
		} else { 
			s << ans + 1; 
		} 

		// Output the processed line to the output 
		outfile << s.str() << endl; 
		cout << s.str() << endl; 

		// Ensure we have the complete test case 
		if (!inputfile.good()) break; 

	} 

	// Closes the file 
	inputfile.close(); 
	outfile.close(); 

	// Successful run 
	return 0; 
}


