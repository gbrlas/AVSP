// Google Code Jam 2013 
// Problem B : Lawnmower  
// 
// Problem
//
// Alice and Bob have a lawn in front of their house, shaped as a rectangle of N by M metres. Each year, they try to cut the lawn in 
// some interesting pattern. So far, they had to do it with shears, which was very time-consuming, but now they have a new automatic 
// lawnmower with multiple settings, and they want to try it out.
// 
// The new lawnmower has a height setting - you can set it to any height h between 1 and 100 millimetres, and it will cut all the 
// grass higher than h it encounters to height h. You run it by entering the lawn at any part of the edge of the lawn, and the 
// lawnmower goes in a straight line, perpendicular to the edge of the lawn it entered, cutting grass in a swath 1m wide, until it 
// exits the lawn on the other side.
// 
// Alice and Bob have a number of various patterns of grass that they could have on their lawn. For each of those, they want to know 
// whether it's possible to cut the grass into this pattern with their new lawnmower. Each pattern is described by specifying the 
// height of the grass on each 1m x 1m square of the lawn.
// 
// The grass is 100mm high on the whole lawn initially.
// 
// Input
// 
// The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing 
// two numbers: N and M. Next follow N lines, with the ith line containing M numbers ai,j each, the number ai,j describing the desired 
// height of the grass in the jth square of the ith row.
// 
// Output
// 
// For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is either the 
// word "YES" if it's possible to get the x-th pattern using the lawnmower, or "NO", if it's impossible (quotes for clarity only).


#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include <list> 
using namespace std; 

#define MAXSZ	100 

int main(int argc, char *argv[]) 
{ 
	// Check that we have the right inputs 
	if (argc < 3) 
	{ 
		cout << "[Usage] ProblemB input_file output_file" << endl; 
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

		// Define problem variables 
		int lawn[MAXSZ][MAXSZ] = {0}; 
		int maxlawn[MAXSZ][MAXSZ]; 

		for (int j = 0; j < MAXSZ; j++) 
		{ 
			memset(maxlawn[j], 9999, sizeof(int) * MAXSZ); 
		} 

		// Read in the size of the lawn 
		int N, M; 
		inputfile >> N >> M; 
		getline(inputfile, line); 

		// Read in the lawn 
		for (int n = 0; n < N; n++) 
		{ 
			for (int m = 0; m < M; m++) 
			{ 
				int val; 
				inputfile >> val; 
				lawn[n][m] = val; 
			} 
			getline(inputfile, line); 
		}

		if (!inputfile.good()) break; 

		// Contains the output for a single line 
		stringstream s; 
		s << "Case #" << count << ": "; 

		// Go through each row of the lawn to find the max 
		for (int n = 0; n < N; n++) 
		{ 
			int maxval = lawn[n][0]; 
			for (int m = 1; m < M; m++) 
			{ 
				if (lawn[n][m] > maxval) 
					maxval = lawn[n][m]; 
			} 

			// Set the max 
			for (int m = 0; m < M; m++) 
			{ 
				maxlawn[n][m] = min(maxlawn[n][m], maxval); 
			} 
		} 

		// Go through each col of the lawn to find the max 
		for (int m = 0; m < M; m++) 
		{ 
			int maxval = lawn[0][m]; 
			for (int n = 1; n < N; n++) 
			{ 
				if (lawn[n][m] > maxval) 
					maxval = lawn[n][m]; 
			} 

			// Set the max 
			for (int n = 0; n < N; n++) 
			{ 
				maxlawn[n][m] = min(maxlawn[n][m], maxval); 
			} 
		} 

		// Go through each entry 
		bool possible = true; 
		for (int m = 0; m < M; m++) 
		{ 
			for (int n = 0; n < N; n++) 
			{ 
				if (maxlawn[n][m] > lawn[n][m]) 
				{ 
					possible = false; 
					break; 
				}
			} 
		} 

		if (possible) s << "YES"; 
		else s << "NO"; 

		// Output the processed line to the output 
		outfile << s.str() << endl; 
		cout << s.str() << endl; 
	} 

	// Closes the file 
	inputfile.close(); 
	outfile.close(); 

	// Successful run 
	return 0; 
}


