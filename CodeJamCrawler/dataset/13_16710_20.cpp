#include "iostream"
#include "fstream"
#include "string"
using namespace std;

string getStatus(char tictac[][4])
{
	for(int row=0;row<4;row++)
	{
		if(((tictac[row][0] == tictac[row][1] && tictac[row][1] == tictac[row][2]) && (tictac[row][3] == tictac[row][0] || tictac[row][3] == 'T')) || 
			((tictac[row][0] == tictac[row][1] && tictac[row][1] == tictac[row][3]) && (tictac[row][2] == tictac[row][0] || tictac[row][2] == 'T')) || 
			((tictac[row][0] == tictac[row][2] && tictac[row][2] == tictac[row][3]) && (tictac[row][1] == tictac[row][0] || tictac[row][1] == 'T')) || 
			((tictac[row][1] == tictac[row][2] && tictac[row][2] == tictac[row][3]) && (tictac[row][0] == tictac[row][1] || tictac[row][0] == 'T')))
		{
			if(tictac[row][0] == 'X' || tictac[row][1] == 'X' || tictac[row][2] == 'X' || tictac[row][3] == 'X' )	
			{ 
				return "X won";
			}
			else if(tictac[row][0] == 'O' || tictac[row][1] == 'O' || tictac[row][2] == 'O' || tictac[row][3] == 'O' )	
			{
				return "O won";
			}
		}
	}
	
	for(int col=0;col<4;col++)
	{
		if(((tictac[0][col] == tictac[1][col] && tictac[1][col]   == tictac[2][col]) && (tictac[3][col] == tictac[0][col] || tictac[3][col] == 'T')) || 
			((tictac[0][col] == tictac[1][col] && tictac[1][col]  == tictac[3][col]) && (tictac[2][col] == tictac[0][col] || tictac[2][col] == 'T')) || 
			((tictac[0][col] == tictac[2][col] && tictac[2][col] == tictac[3][col]) && (tictac[1][col] == tictac[0][col] || tictac[1][col] == 'T')) || 
			((tictac[1][col] == tictac[2][col] && tictac[2][col] == tictac[3][col]) && (tictac[0][col] == tictac[1][col] || tictac[0][col] == 'T')))
		{
			if(tictac[0][col] == 'X' || tictac[1][col] == 'X' || tictac[2][col] == 'X' || tictac[3][col] == 'X' )	return "X won";
			else if(tictac[0][col] == 'O' || tictac[1][col] == 'O' || tictac[2][col] == 'O' || tictac[3][col] == 'O' ) return "O won";
		}
	}

	if(((tictac[0][0] == tictac[1][1] == tictac[2][2]) && (tictac[3][3] == tictac[0][0] || tictac[3][3] == 'T')) || 
			((tictac[0][0] == tictac[1][1] && tictac[1][1] == tictac[3][3]) && (tictac[2][2] == tictac[0][0] || tictac[2][2] == 'T')) || 
			((tictac[0][0] == tictac[2][2] && tictac[2][2] == tictac[3][3]) && (tictac[1][1] == tictac[0][0] || tictac[1][1] == 'T')) || 
			((tictac[1][1] == tictac[2][2] && tictac[2][2]== tictac[3][3]) && (tictac[0][0] == tictac[1][1] || tictac[0][0] == 'T')))
		{
			if(tictac[0][0] == 'X' || tictac[1][1] == 'X' || tictac[2][2] == 'X' || tictac[3][3] == 'X' )	return "X won";
			else if(tictac[0][0] == 'O' || tictac[1][1] == 'O' || tictac[2][2] == 'O' || tictac[3][3] == 'O' ) return "O won";
		}

	if(((tictac[0][3] == tictac[1][2] && tictac[1][2] == tictac[2][1]) && (tictac[3][0] == tictac[0][3] || tictac[3][0] == 'T')) || 
			((tictac[0][3] == tictac[1][2] && tictac[1][2] == tictac[3][0]) && (tictac[2][1] == tictac[0][3] || tictac[2][1] == 'T')) || 
			((tictac[0][3] == tictac[2][1] && tictac[2][1] == tictac[3][0]) && (tictac[1][2] == tictac[0][3] || tictac[1][2] == 'T')) || 
			((tictac[1][2] == tictac[2][1] && tictac[2][1] == tictac[3][0]) && (tictac[0][3] == tictac[1][2] || tictac[0][3] == 'T')))
		{
			if(tictac[0][3] == 'X' || tictac[1][2] == 'X' || tictac[2][1] == 'X' || tictac[3][0] == 'X' )	return "X won";
			else if(tictac[0][3] == 'O' || tictac[1][2] == 'O' || tictac[2][1] == 'O' || tictac[3][0] == 'O' ) return "O won";
		}

	if(tictac[0][0] != '.' && tictac[0][1] != '.' && tictac[0][2] != '.' && tictac[0][3] != '.' && tictac[1][0] != '.' && tictac[1][1] != '.' && 
		tictac[1][2] != '.' && tictac[1][3] != '.' && tictac[2][0] != '.' && tictac[2][1] != '.' && tictac[2][2] != '.' && tictac[2][3] != '.' &&
		tictac[3][0] != '.' && tictac[3][1] != '.' && tictac[3][2] != '.' && tictac[3][3] != '.')
	{
		return "Draw";
	}

	return "Game has not completed";

}

int main()
{
	string line;
	ifstream input("A-small-attempt0.in");
	ofstream output("output.txt", ios::out | ios::trunc);
	if(input.is_open() && output.is_open())
	{
			getline(input,line);
			int T = atoi(line.c_str());
			for(int i=1;i<=T;i++)
			{
				char tt[4][4];
				for(int j=0;j<4;j++)
				{
					getline(input,line);
					for(int k=0;k<4;k++)
					{
						tt[j][k]=line.at(k);
					}
				}

				string status= getStatus(tt);
				
				output<<"Case #"<<i<<": "<<status<<endl;

				getline(input,line);
			}

		input.close();
		output.close();
	}
}