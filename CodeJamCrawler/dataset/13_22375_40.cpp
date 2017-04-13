// tictactoe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getResult( vector<string> &board )
{
	int i,j;

	int result = 0;

	string res;

	for( i = 0 ; i < board.size() ; i++ )
	{
		string line = board[i];

		if( line == "XXXX" || line == "TXXX" || line == "XTXX" || line == "XXTX" || line == "XXXT")
		{
			result = 1;
		}

		if( line == "OOOO" || line == "TOOO" || line == "OTOO" || line == "OOTO" || line == "OOOT")
		{
			result = 2;
		}
	}

	string line;
	
	for( i = 0 ; i < 4 ; i++ )
	{
		line = "";

		for( j = 0 ; j < 4 ; j++ )
			line += board[j].at(i);

		if( line == "XXXX" || line == "TXXX" || line == "XTXX" || line == "XXTX" || line == "XXXT")
		{
			result = 1;
		}

		if( line == "OOOO" || line == "TOOO" || line == "OTOO" || line == "OOTO" || line == "OOOT")
		{
			result = 2;
		}
	}

	line = "";
	for( i = 0 ; i < 4 ; i++ )
	{
		line += board[i].at(i);
	}

	if( line == "XXXX" || line == "TXXX" || line == "XTXX" || line == "XXTX" || line == "XXXT")
	{
		result = 1;
	}

	if( line == "OOOO" || line == "TOOO" || line == "OTOO" || line == "OOTO" || line == "OOOT")
	{
		result = 2;
	}

	i = 0;

	j = 3;

	line = "";

	while ( i < 4 )
	{
		line += board[i].at(j);

		i++;
		j--;
	}

	if( line == "XXXX" || line == "TXXX" || line == "XTXX" || line == "XXTX" || line == "XXXT")
	{
		result = 1;
	}

	if( line == "OOOO" || line == "TOOO" || line == "OTOO" || line == "OOTO" || line == "OOOT")
	{
		result = 2;
	}

	if ( result > 0 )
	{
		res = (result == 1) ? "X won" : "O won";
	}
	else
	{
		for( i = 0 ; i < board.size() ; i++ )
		{
			string line = board[i];

			if( line.find('.') != string::npos )
			{
				res = "Game has not completed";

				return res;
			}
		}
		res = "Draw";
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nTestCases;

	cin >> nTestCases;
	int i,j;

	vector<string> input;

	for( i = 0 ; i < nTestCases ; i++ )
	{
		input.clear();

		for( j = 0 ; j < 4 ; j++)
		{
			string line;

			cin>>line;

			input.push_back(line);
		}
		string res = getResult( input );
		cout<<"Case #"<<i+1<<": "<<res;
		if( i != nTestCases - 1)
			cout<<endl;
	}
	return 0;
}

