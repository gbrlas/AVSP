//============================================================================
// Name        : Tic-Tac-Toe-Tomek.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <string>

using namespace std;
string status(char (*input)[4]);
int main() {
	int T;
	char input[4][4];
	cin >> T;
	string emptyline;
	for (int i = 1; i <= T; ++i) {
		for (int j = 0; j < 4; ++j){
			for (int k = 0; k < 4; ++k)
				cin >> input[j][k];
			//cin >> newline;
		}
		cout << "Case #" << i << ": " << status(input) << endl;
		getline(cin, emptyline);
	}
	return 0;
}

string status(char (*input)[4])
{
	int Xstatus = 0, Ostatus = 0;
	bool completed = true;
	for(int i = 0; i < 4; ++i){
		Xstatus = 0;
		Ostatus = 0;
		for (int j = 0; j < 4; ++j)	{
			if(input[i][j] == 'X')
				++Xstatus;
			else if (input[i][j] == 'O')
				++Ostatus;
			else if (input[i][j] == '.')
				completed = false;
			else {
				++Xstatus;
				++Ostatus;
			}
		}
		if (Xstatus == 4)
			return "X won";
		if (Ostatus == 4)
			return "O won";
	}
	for(int j = 0; j < 4; ++j){
		Xstatus = 0;
		Ostatus = 0;
		for (int i = 0; i < 4; ++i)	{
			if(input[i][j] == 'X')
				++Xstatus;
			else if (input[i][j] == 'O')
				++Ostatus;
			else if (input[i][j] == '.')
				completed = false;
			else {
				++Xstatus;
				++Ostatus;
			}
		}
		if (Xstatus == 4)
			return "X won";
		if (Ostatus == 4)
			return "O won";
	}

	Xstatus = 0;
	Ostatus = 0;
	for(int i = 0; i < 4; ++i){
			if(input[i][i] == 'X')
				++Xstatus;
			else if (input[i][i] == 'O')
				++Ostatus;
			else if (input[i][i] == '.')
				completed = false;
			else {
				++Xstatus;
				++Ostatus;
			}
	}
	if (Xstatus == 4)
		return "X won";
	if (Ostatus == 4)
		return "O won";

	Xstatus = 0;
	Ostatus = 0;
	for(int i = 0; i < 4; ++i){
			if(input[i][3-i] == 'X')
				++Xstatus;
			else if (input[i][3-i] == 'O')
				++Ostatus;
			else if (input[i][3-i] == '.')
				completed = false;
			else {
				++Xstatus;
				++Ostatus;
			}
	}
	if (Xstatus == 4)
		return "X won";
	if (Ostatus == 4)
		return "O won";

	if (completed)
		return "Draw";
	else
		return "Game has not completed";
}
