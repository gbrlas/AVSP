// Google Code Jam 2013 
// Problem A : Tic-Tac-Toe-Tomek  
// 
// Tic-Tac-Toe-Tomek is a game played on a 4 x 4 square board. The board starts empty, except that a single 'T' symbol may appear in 
// one of the 16 squares. There are two players: X and O. They take turns to make moves, with X starting. In each move a player puts 
// her symbol in one of the empty squares. Player X's symbol is 'X', and player O's symbol is 'O'.
// 
// After a player's move, if there is a row, column or a diagonal containing 4 of that player's symbols, or containing 3 of her symbols 
// and the 'T' symbol, she wins and the game ends. Otherwise the game continues with the other player's move. If all of the fields are 
// filled with symbols and nobody won, the game ends in a draw. See the sample input for examples of various winning positions.
// 
// Given an 4 x 4 board description containing 'X', 'O', 'T' and '.' characters (where '.' represents an empty square), describing the 
// current state of a game, determine the status of the Tic-Tac-Toe-Tomek game going on. The statuses to choose from are:
// 
// "X won" (the game is over, and X won)
// "O won" (the game is over, and O won)
// "Draw" (the game is over, and it ended in a draw)
// "Game has not completed" (the game is not over yet)
//
// Input
// 
// The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of 4 lines with 4 
// characters each, with each character being 'X', 'O', '.' or 'T' (quotes for clarity only). Each test case is followed by an empty 
// line.
// 
// Output
// 
// For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is one of the 
// statuses given above. Make sure to get the statuses exactly right. When you run your code on the sample input, it should create 
// the sample output exactly, including the "Case #1: ", the capital letter "O" rather than the number "0", and so on


// There are only 10 possible combinations of winning, i.e. each of the four columns, each of the four rows, and the two 
// diagonals. So we just have to check for all these combinations to see if any one of them are winning. This meant that 
// we just have to maintain a sum for each column, row and diagonal for each of the player separately. The symbol 'T' will 
// add to both player's sums. Thus there is a win if any of this sum is equal to 4. Since the game is given to be a valid 
// state, then a draw is assumed if neither of them win. We do not have to check that the game is in a valid state 

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
		int Xsum[10] = {0};		// Initialize the players' sums to zero corresponding to the 4 cols, 4 rows, 2 diagonals 
		int Osum[10] = {0}; 
		bool won = false;		// Indicates whether anyone won 
		bool completed = true; // Indicates whether game is completed 

		// Read through the four lines to get the game state 
		for (int r = 0; r < 4; r++) 
		{ 
			getline(inputfile, line); 

			string::iterator k; 
			int c = 0; 
			for (k = line.begin(); k != line.end(); k++) 
			{ 
			
				// Go through each character of the line 
				// Thus now we are at row r, col c 
				// Increment the corresponding sum 
				if (*k == 'O' || *k == 'o') 
				{ 

					// Player O 
					// Increment the sum for the row it is in 
					Osum[4 + r]++; 

					// Increment the sum for the col it is in 
					Osum[c]++; 

					// Increment the sum for the diagonal it is in, if it is in a diagonal 
					if (r == c) 
					{ 
						// Main diagonal 
						Osum[8]++; 
					} else if (3 - r == c) { 
						// Opposite diagonal 
						Osum[9]++; 
					} 

				} else if (*k == 'X' || *k == 'x') { 

					// Player X 
					// Increment the sum for the row it is in 
					Xsum[4 + r]++; 

					// Increment the sum for the col it is in 
					Xsum[c]++; 

					// Increment the sum for the diagonal it is in, if it is in a diagonal 
					if (r == c) 
					{ 
						// Main diagonal 
						Xsum[8]++; 
					} else if (3 - r == c) { 
						// Opposite diagonal 
						Xsum[9]++; 
					} 

				} else if (*k == 'T' || *k == 't') { 

					// It is the token T, increment both players' sums 
					// Increment the sum for the row it is in 
					Osum[4 + r]++; 
					Xsum[4 + r]++; 

					// Increment the sum for the col it is in 
					Osum[c]++; 
					Xsum[c]++; 

					// Increment the sum for the diagonal it is in, if it is in a diagonal 
					if (r == c) 
					{ 
						// Main diagonal 
						Osum[8]++; 
						Xsum[8]++; 
					} else if (3 - r == c) { 
						// Opposite diagonal 
						Osum[9]++; 
						Xsum[9]++; 
					} 

				} else if (*k == '.') { 

					// There is still an empty square, game is not over 
					completed = false; 

				} else { 

					// It should not come into here 
					assert(1); 

				} 
				// Increment the column c 
				c++; 
			}

		} 

		// Ensure we have the complete test case 
		if (!inputfile.good()) break; 

		// Contains the output for a single line 
		stringstream s; 
		s << "Case #" << count << ": "; 

		// Check whether X or O  won 
		for (int p = 0; p < 10; p++) 
		{ 
			// If sum equals four, then the particular player has won 
			if (Xsum[p] == 4) 
			{ 
				s << "X won"; 
				won = true; 
				break; 
			} else if (Osum[p] == 4) { 
				s << "O won"; 
				won = true; 
				break; 
			} 
		} 

		// Check if it is a draw 
		if (completed && !won) s << "Draw"; 
		else if (!completed && !won) s << "Game has not completed"; 

		// Output the processed line to the output 
		outfile << s.str() << endl; 

		// Get empty line 
		getline(inputfile, mline); 

	} 

	// Closes the file 
	inputfile.close(); 
	outfile.close(); 

	// Successful run 
	return 0; 
}


