#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::string foo(const std::vector<std::string>& board)
{
	if ((board[0][0] == 'O' || board[0][0] == 'T') &&
		(board[0][1] == 'O' || board[0][1] == 'T') &&
		(board[0][2] == 'O' || board[0][2] == 'T') &&
		(board[0][3] == 'O' || board[0][3] == 'T'))
	{
		return "O won";
	}
	if ((board[1][0] == 'O' || board[1][0] == 'T') &&
		(board[1][1] == 'O' || board[1][1] == 'T') &&
		(board[1][2] == 'O' || board[1][2] == 'T') &&
		(board[1][3] == 'O' || board[1][3] == 'T'))
	{
		return "O won";
	}
	if ((board[2][0] == 'O' || board[2][0] == 'T') &&
		(board[2][1] == 'O' || board[2][1] == 'T') &&
		(board[2][2] == 'O' || board[2][2] == 'T') &&
		(board[2][3] == 'O' || board[2][3] == 'T'))
	{
		return "O won";
	}
	if ((board[3][0] == 'O' || board[3][0] == 'T') &&
		(board[3][1] == 'O' || board[3][1] == 'T') &&
		(board[3][2] == 'O' || board[3][2] == 'T') &&
		(board[3][3] == 'O' || board[3][3] == 'T'))
	{
		return "O won";
	}
	for (int i = 0; i < 4; ++i)
	{
		if ((board[0][i] == 'O' || board[0][i] == 'T') &&
			(board[1][i] == 'O' || board[1][i] == 'T') &&
			(board[2][i] == 'O' || board[2][i] == 'T') &&
			(board[3][i] == 'O' || board[3][i] == 'T'))
		{
			return "O won";
		}
	}
	if ((board[0][0] == 'O' || board[0][0] == 'T') &&
		(board[1][1] == 'O' || board[1][1] == 'T') &&
		(board[2][2] == 'O' || board[2][2] == 'T') &&
		(board[3][3] == 'O' || board[3][3] == 'T'))
	{
		return "O won";
	}
	if ((board[3][0] == 'O' || board[3][0] == 'T') &&
		(board[2][1] == 'O' || board[2][1] == 'T') &&
		(board[1][2] == 'O' || board[1][2] == 'T') &&
		(board[0][3] == 'O' || board[0][3] == 'T'))
	{
		return "O won";
	}
	
	if ((board[0][0] == 'X' || board[0][0] == 'T') &&
		(board[0][1] == 'X' || board[0][1] == 'T') &&
		(board[0][2] == 'X' || board[0][2] == 'T') &&
		(board[0][3] == 'X' || board[0][3] == 'T'))
	{
		return "X won";
	}
	if ((board[1][0] == 'X' || board[1][0] == 'T') &&
		(board[1][1] == 'X' || board[1][1] == 'T') &&
		(board[1][2] == 'X' || board[1][2] == 'T') &&
		(board[1][3] == 'X' || board[1][3] == 'T'))
	{
		return "X won";
	}
	if ((board[2][0] == 'X' || board[2][0] == 'T') &&
		(board[2][1] == 'X' || board[2][1] == 'T') &&
		(board[2][2] == 'X' || board[2][2] == 'T') &&
		(board[2][3] == 'X' || board[2][3] == 'T'))
	{
		return "X won";
	}
	if ((board[3][0] == 'X' || board[3][0] == 'T') &&
		(board[3][1] == 'X' || board[3][1] == 'T') &&
		(board[3][2] == 'X' || board[3][2] == 'T') &&
		(board[3][3] == 'X' || board[3][3] == 'T'))
	{
		return "X won";
	}
	for (int i = 0; i < 4; ++i)
	{
		if ((board[0][i] == 'H' || board[0][i] == 'T') &&
			(board[1][i] == 'H' || board[1][i] == 'T') &&
			(board[2][i] == 'H' || board[2][i] == 'T') &&
			(board[3][i] == 'H' || board[3][i] == 'T'))
		{
			return "H won";
		}
	}
	if ((board[0][0] == 'X' || board[0][0] == 'T') &&
		(board[1][1] == 'X' || board[1][1] == 'T') &&
		(board[2][2] == 'X' || board[2][2] == 'T') &&
		(board[3][3] == 'X' || board[3][3] == 'T'))
	{
		return "X won";
	}
	if ((board[3][0] == 'X' || board[3][0] == 'T') &&
		(board[2][1] == 'X' || board[2][1] == 'T') &&
		(board[1][2] == 'X' || board[1][2] == 'T') &&
		(board[0][3] == 'X' || board[0][3] == 'T'))
	{
		return "X won";
	}
	

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (board[i][j] == '.')
			{
				return "Game has not completed";
			}
		}
	}
	
	return "Draw";
}

int main (int argc, char * const argv[]) {
    // insert code here...
	std::ifstream input(argv[1]);
	std::vector<std::string> board;
	int n;
	input >> n;
	for (int i = 0; i < n; ++i)
	{
		board.clear();
		std::string s;
		for (int j = 0; j < 4; ++j)
		{
			input >> s;
			//std::cout << s << std::endl;
			board.push_back(s);
		}
		//input >> s; // empty line
		
		std::cout << "Case #" << i << ": " << foo(board) << std::endl;
	}
    return 0;
}
