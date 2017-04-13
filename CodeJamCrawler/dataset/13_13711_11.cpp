// Google Code Jam 2013 
// Problem A : Bullseye
// 

#define _USE_MATH_DEFINES 

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include <list> 
#include <cassert> 
#include <cmath> 
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
		double amtpaint = 0; 
		double initradius = 1; 
		int numcircle = 0; 

		// Read in the amount of paint and the initial circle radius 
		inputfile >> initradius >> amtpaint; 
		//getline(inputfile, line); 

		// Compute the initial area 
		unsigned long long int oldradius = initradius; 
		unsigned long long int curradius = oldradius + 1; 
		unsigned long long int oldcirclearea, curcirclearea; 
		oldcirclearea = oldradius * oldradius; 
		curcirclearea = curradius * curradius; 
		unsigned long long int area = curcirclearea - oldcirclearea; 

		// Compute the number of circles that can be drawn 
		numcircle++; 
		amtpaint -= area; 
		while (amtpaint > 0) 
		{ 
			// pi * (r + 2) * (r + 2) = pi * (r^2 + 4r + 4) = (pi * r^2) + (pi * (4r + 4)) 
			curcirclearea += ((curradius << 2) + 4); 
			oldcirclearea += ((oldradius << 2) + 4);
			curradius += 2; 
			oldradius += 2; 
			area = curcirclearea - oldcirclearea; 
			if (area <= amtpaint) 
			{ 
				numcircle++; 
			}
			amtpaint -= area; 
		} 

		// Ensure we have the complete test case 
		if (!inputfile.good()) break; 

		// Contains the output for a single line 
		stringstream s; 
		s << "Case #" << count << ": "; 
		s << numcircle;

		// Output the processed line to the output 
		outfile << s.str() << endl; 
		cout << s.str() << endl; 

		// Get empty line 
		getline(inputfile, mline); 

	} 

	// Closes the file 
	inputfile.close(); 
	outfile.close(); 

	// Successful run 
	return 0; 
}


