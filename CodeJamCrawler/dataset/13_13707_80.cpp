// Google Code Jam 2013 
// Problem C : Fair and Square 
// 
// Problem
//
// Little John likes palindromes, and thinks them to be fair (which is a fancy word for nice). A palindrome is just a number that 
// reads the same backwards and forwards - so 6, 11 and 121 are all palindromes, while 12, 223 and 2244 are not.
//
// He recently became interested in squares as well, and formed the definition of a fair and square number - it is a number that 
// is a palindrome and a square of a palindrome at the same time. For instance, 1, 9 and 121 are fair and square (being palindromes
// and squares, respectively, of 1, 3 and 11), while 16, 22 and 676 are not fair and square - the first is not a palindrome, the 
// second is not a square, and the third is a square, but not a square of a palindrome.
//
// Now he wants to search for bigger fair and square numbers. Your task is, given an interval Little John is searching through, 
// to tell him how many fair and square numbers are there in the interval, so he knows when he has found them all.
//
// Solving this problem
//
// Usually, Google Code Jam problems have 1 Small input and 1 Large input. This problem has 1 Small input and 2 Large inputs. Once 
// you have solved the Small input, you will be able to download any of the two Large inputs. As usual, you will be able to retry the 
// Small input (with a time penalty), while you will get only one chance at each of the Large inputs.
//
// Input
//
// The first line of the input gives the number of test cases, T. T lines follow. Each lines contains two numbers, A and B - the 
// endpoints of the interval Little John is looking at.
//
// Output
//
// For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the number of 
// fair and square numbers greater or equal to A and smaller or equal than B. 


#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include <list> 
#include <cstdio> 
using namespace std; 

bool inline check_palindrome(string s) 
{ 

	// Get the number of digits 
	int len = s.length(); 

	// If there is only a single digit, it is always a palindrome 
	if (len == 1) return true; 

	// Get the mid point 
	int midpt = ceil((double)len / 2); 

	// Iterate through the digits to check 
	for (int k = 0; k < midpt; k++) 
	{ 
		if (s[k] != s[len-k-1]) 
			return false; 
	} 

	return true; 

} 

string add_number(string a, string b) 
{
	string o; 

	// Get the number of digits 
	int alen = a.length(); 
	int blen = b.length(); 

	// Pad the smaller number with leading zeros 
	int len = alen; 
	if (alen < blen) 
	{ 
		len = blen; 
	} else if (blen < alen) { 
		len = alen; 
	} 

	// Add the numbers 
	int carry = 0; 
	for (int k = 0; k < len; k++) 
	{ 
		int aval, bval; 
		int count = 0; 

		if (k < alen) aval = a[alen - 1 - k] - '0'; 
		else aval = 0; 

		if (k < blen) bval = b[blen - 1 - k] - '0'; 
		else bval = 0; 

		count = aval + bval + carry; 
		if (count > 9) {
			carry = 1; 
			count -= 10; 
		} else carry = 0; 
		o = "0" + o; 
		o[0] += count; 
	} 
	if (carry == 1) 
		o = "1" + o; 

	return o; 

} 

string add_one(string a) 
{
	string o = a; 

	// Get the number of digits 
	int len = a.length(); 

	// Increment by one 
	int carry = 0; 
	for (int k = 0; k < len; k++) 
	{ 
		int aval; 
		int count = 0; 

		aval = a[len - 1 - k] - '0'; 
		count = aval + (k == 0) + carry; 

		if (count > 9) {
			carry = 1; 
			count -= 10; 
		} else carry = 0; 

		o[len - 1- k] = '0' + count; 
		if (carry == 0) break; 

	} 
	if (carry == 1) 
		o = "1" + o; 

	return o; 

} 

string multiply_number(string a, string b) 
{ 
	string o("0"); 

	// get the number of digits 
	int alen = a.length(); 
	int blen = b.length(); 

	// Multiply with the smaller number 
	if (alen < blen) 
	{ 

		string numtoadd = b; 

		// Iterate through the smaller number 
		for (int k = 0; k < alen; k++) 
		{ 
			int count = a[alen - 1 - k] - '0'; 
			
			for (int m = 0; m < count; m++) 
			{ 
				o = add_number(o, numtoadd); 
			} 

			numtoadd = numtoadd + "0"; 
		} 

	} else {

		string numtoadd = a; 

		// Iterate through the smaller number 
		for (int k = 0; k < blen; k++) 
		{ 
			int count = b[blen - 1 - k] - '0'; 
			
			for (int m = 0; m < count; m++) 
			{ 
				o = add_number(o, numtoadd); 
			} 

			numtoadd = numtoadd + "0"; 
		} 

	} 

	return o; 

} 

string inline square_number(string s) 
{ 
	return multiply_number(s, s); 
} 

bool inline check_greater(string a, string b) 
{ 

	// Check whether number a is greater than number b 
	// Get the number of digits 
	int alen = a.length(); 
	int blen = b.length(); 

	// If a has more digits, it is also greater 
	if (alen > blen) return true; 

	// If a has less digits, it is smaller 
	if (blen > alen) return false; 

	// Else if they have equal number of digits 
	return a.compare(b) > 0; 

} 


bool inline check_greaterequal(string a, string b) 
{ 

	// Check whether number a is greater than number b 
	// Get the number of digits 
	int alen = a.length(); 
	int blen = b.length(); 

	// If a has more digits, it is also greater 
	if (alen > blen) return true; 

	// If a has less digits, it is smaller 
	if (blen > alen) return false; 

	// Else if they have equal number of digits 
	return a.compare(b) >= 0; 

} 

bool checkSquare(string start, string stop, string sqnum) 
{ 
	// Iterate through from start to stop 
	string curnum = start; 
	do 
	{ 
		if (!check_palindrome(curnum)) { 
			curnum = add_one(curnum); 
			continue; 
		} 

		string num = square_number(curnum); 
		if (num.compare(sqnum) == 0) 
		{ 
			// It's a match. The square of the palindrome exist! 
			return true; 
		} else if (check_greater(num, sqnum)) { 
			break; 
		} 

		curnum = add_one(curnum); 

	} while (curnum.compare(stop) != 0); 

	return false; 
} 

int findNumFairSquareVer1(string a, string b) 
{ 
	int num = 0; 

	// Iterate through the numbers from the range 
	// and first check if they are palindromes 
	string curnum = a; 
	int tm = 0; 
	do 
	{ 
		if (check_palindrome(curnum)) 
		{ 
			// The current number is a palindrome, now we also 
			// check that it is a square of a palindrome 

			// We start from approximately the square root of the 
			// number and search through to see if there are any 
			// palindromes whose square is equal to the current number 
			double aproxval = stod(curnum); 
			double root = sqrt(aproxval); 
			char buf[4096]; 
			sprintf(buf, "%.0f", root - 1); 
			string start = string(buf); 
			sprintf(buf, "%.0f", root + 1); 
			string stop = string(buf); 
			if (checkSquare(start, stop, curnum)) 
			{
				num++; 
			}
		} 

		// Increment the number 
		curnum = add_one(curnum); 
	} while (curnum.compare(b) != 0);  

	// Check for the end interval 
	if (check_palindrome(curnum)) 
	{ 
		// The current number is a palindrome, now we also 
		// check that it is a square of a palindrome 

		// We start from approximately the square root of the 
		// number and search through to see if there are any 
		// palindromes whose square is equal to the current number 
		double aproxval = stod(curnum); 
		double root = sqrt(aproxval); 
		char buf[4096]; 
		sprintf(buf, "%.0f", root - 1); 
		string start = string(buf); 
		sprintf(buf, "%.0f", root + 1); 
		string stop = string(buf); 
		if (checkSquare(start, stop, curnum)) 
		{
			num++; 
			cout << "Fair and Square: " << curnum << endl; 
		}
	} 

	return num; 

} 

int findNumFairSquare(string a, string b) 
{ 
	int num = 0; 

	// Convert the numbers to double and take the square roots 
	// as the range 
	double aroot = sqrt(stod(a)) - 1; 
	double broot = sqrt(stod(b)) + 1; 
	if (aroot <= 0) aroot = 1; 
	char buf[4096]; 
	sprintf(buf, "%0.f", aroot); 
	string start = buf; 
	sprintf(buf, "%0.f", broot); 
	string stop = buf; 


	// Search through to find the number of fair and square 
	string curnum = start; 
	do 
	{
		
		if (check_palindrome(curnum)) 
		{
			string sqnum = square_number(curnum); 
			if (check_palindrome(sqnum)) 
			{ 
				// It is a palindrome 
				// Check that it is within the bounds also 
				if (check_greaterequal(sqnum, a) && check_greaterequal(b, sqnum)) 
					num++; 
			}
		}

		curnum = add_one(curnum); 

	} while (curnum.compare(stop) != 0); 

	return num; 

} 


int main(int argc, char *argv[]) 
{ 
	// Check that we have the right inputs 
	if (argc < 3) 
	{ 
		cout << "[Usage] ProblemC input_file output_file" << endl; 
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

		// Get the two intervals 
		string A, B; 
		inputfile >> A >> B; 
		getline(inputfile, line); 

		if (!inputfile.good()) break; 

		// Contains the output for a single line 
		stringstream s; 
		s << "Case #" << count << ": "; 

		// Find the number of fair and square numbers 
		int num = findNumFairSquare(A, B); 
		s << num; 

		// Output the processed line to the output 
		outfile << s.str() << endl; 
	} 

	// Closes the file 
	inputfile.close(); 
	outfile.close(); 

	// Successful run 
	return 0; 
}


