#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define DOT 0
#define RED 1
#define BLUE 2

#define NEITHER 0
#define REDWIN 1
#define BLUEWIN 2
#define BOTH 3

int& elementAt(int *table, int N, int row, int col)
{
	return table[row * N + col];
}

int checkTable(int *table, int N, int K)
{
	bool redWin = false;
	bool blueWin = false;
	// check rows
	for(int i = 0 ; i < N; i++)
	{
		int redNum = 0;
		int blueNum = 0;
		for(int j = 0; j < N; j++)
		{
			int elem = elementAt(table, N, i, j);
			if(elem == DOT)
			{
				redNum = 0;
				blueNum = 0;
			}
			else if(elem == RED)
			{
				//if(redNum > 0)
				//{
					redNum++;
					blueNum = 0;
				//}
			}
			else if(elem == BLUE)
			{
				//if(blueNum > 0)
				//{
					blueNum++;
					redNum = 0;
				//}
			}
			if(redNum >= K)
			{
				redWin = true;
			}
			if(blueNum >= K)
			{
				blueWin = true;
			}
			if(redWin && blueWin)
			{
				return BOTH;
			}
		}
	}
	// check cols
	for(int j = 0; j < N; j++)
	{
		int redNum = 0;
		int blueNum = 0;
		for(int i = 0; i < N; i++)
		{
			int elem = elementAt(table, N, i, j);
			if(elem == DOT)
			{
				redNum = 0;
				blueNum = 0;
				//continue;
			}
			else if(elem == RED)
			{
				//if(redNum > 0)
				//{
					redNum++;
					blueNum = 0;
				//}
			}
			else if(elem == BLUE)
			{
				//if(blueNum > 0)
				//{
					blueNum++;
					redNum = 0;
				//}
			}
			if(redNum >= K)
			{
				redWin = true;
			}
			if(blueNum >= K)
			{
				blueWin = true;
			}
			if(redWin && blueWin)
			{
				return BOTH;
			}
		}
	}
	// check diagonals
	for(int i = K - 1; i < N; i++)
	{
		int redNum = 0;
		int blueNum = 0;
		int rowIndex = i;
		int colIndex = 0;
		while(true)
		{
			int elem = elementAt(table, N, rowIndex, colIndex);
			if(elem == DOT)
			{
				redNum = 0;
				blueNum = 0;
			}
			else if(elem == RED)
			{
				//if(redNum > 0)
				//{
					redNum++;
					blueNum = 0;
				//}
			}
			else if(elem == BLUE)
			{
				//if(blueNum > 0)
				//{
					blueNum++;
					redNum = 0;
				//}
			}
			if(redNum >= K)
			{
				redWin = true;
			}
			if(blueNum >= K)
			{
				blueWin = true;
			}
			if(redWin && blueWin)
			{
				return BOTH;
			}
			rowIndex -= 1;
			colIndex += 1;
			if(rowIndex < 0 || colIndex > N - 1)
			{
				break;
			}
		}
	}
	for(int j = N - K; j >= 1; j--)
	{
		int redNum = 0;
		int blueNum = 0;
		int rowIndex = N - 1;
		int colIndex = j;
		while(true)
		{
			int elem = elementAt(table, N, rowIndex, colIndex);
			if(elem == DOT)
			{
				redNum = 0;
				blueNum = 0;
			}
			else if(elem == RED)
			{
				//if(redNum > 0)
				//{
					redNum++;
					blueNum = 0;
				//}
			}
			else if(elem == BLUE)
			{
				//if(blueNum > 0)
				//{
					blueNum++;
					redNum = 0;
				//}
			}
			if(redNum >= K)
			{
				redWin = true;
			}
			if(blueNum >= K)
			{
				blueWin = true;
			}
			if(redWin && blueWin)
			{
				return BOTH;
			}
			rowIndex -= 1;
			colIndex += 1;
			if(rowIndex < 0 || colIndex > N - 1)
			{
				break;
			}
		}
	}
	// check the other diagonals
	for(int j = N - K; j >= 0; j--)
	{
		int redNum = 0;
		int blueNum = 0;
		int rowIndex = 0;
		int colIndex = j;
		while(true)
		{
			int elem = elementAt(table, N, rowIndex, colIndex);
			if(elem == DOT)
			{
				redNum = 0;
				blueNum = 0;
			}
			else if(elem == RED)
			{
				//if(redNum > 0)
				//{
					redNum++;
					blueNum = 0;
				//}
			}
			else if(elem == BLUE)
			{
				//if(blueNum > 0)
				//{
					blueNum++;
					redNum = 0;
				//}
			}
			if(redNum >= K)
			{
				redWin = true;
			}
			if(blueNum >= K)
			{
				blueWin = true;
			}
			if(redWin && blueWin)
			{
				return BOTH;
			}
			rowIndex += 1;
			colIndex += 1;
			if(rowIndex > N - 1 || colIndex > N - 1)
			{
				break;
			}
		}	
	}
	for(int i = 1; i <= N - K; i++)
	{
		int redNum = 0;
		int blueNum = 0;
		int rowIndex = i;
		int colIndex = 0;
		while(true)
		{
			int elem = elementAt(table, N, rowIndex, colIndex);
			if(elem == DOT)
			{
				redNum = 0;
				blueNum = 0;
			}
			else if(elem == RED)
			{
				//if(redNum > 0)
				//{
					redNum++;
					blueNum = 0;
				//}
			}
			else if(elem == BLUE)
			{
				//if(blueNum > 0)
				//{
					blueNum++;
					redNum = 0;
				//}
			}
			if(redNum >= K)
			{
				redWin = true;
			}
			if(blueNum >= K)
			{
				blueWin = true;
			}
			if(redWin && blueWin)
			{
				return BOTH;
			}
			rowIndex += 1;
			colIndex += 1;
			if(rowIndex > N - 1 || colIndex > N - 1)
			{
				break;
			}
		}	
	}
	if(redWin)
	{
		return REDWIN;
	}
	else if(blueWin)
		return BLUEWIN;
	else
		return NEITHER;
}

void printTable(int *table, int N)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int elem = elementAt(table, N, i, j);
			if(elem == DOT)
			{
				cout<<"."<<" ";
			}
			else if(elem == RED)
			{
				cout<<"R"<<" ";
			}
			else if(elem == BLUE)
			{
				cout<<"B"<<" ";
			}
		}
		cout<<endl;
	}
}

int main(int argc, char *argv[])
{
	ifstream input("A-large.in");
	ofstream output("A-large.out");
	int T, N, K;
	input>>T;
	for(int cases = 1; cases <= T; cases++)
	{
		input>>N>>K;
		int *originalTable = new int[N * N];
		int *rotatedTable = new int[N * N];
		vector<int> currentNonDotElem;
		int currentIndex = 0;
		for(int i = 0; i < N; i++)
		{
			int rotatedCol = N - 1 - i;
			string str;
			input>>str;
			for(int j = 0; j < N; j++)
			{
				if(str[j] == '.')
					originalTable[i * N + j] = DOT;
				else if(str[j] == 'R')
				{
					originalTable[i * N + j] = RED;
					currentNonDotElem.push_back(RED);
				}
				else if(str[j] == 'B')
				{
					originalTable[i * N + j] = BLUE;
					currentNonDotElem.push_back(BLUE);
				}
				else
					;
			}
			for(int row = N - 1; row >= 0; row--)
			{
				int size = currentNonDotElem.size();
				if(size > 0)
				{
					int elem = currentNonDotElem[size - 1];
					currentNonDotElem.pop_back();
					rotatedTable[row * N + rotatedCol] = elem;
				}
				else
				{
					rotatedTable[row * N + rotatedCol] = DOT;
				}
			}
		}
		//printTable(originalTable, N);
		//cout<<"******************************\n";
		//printTable(rotatedTable, N);
		int result1 = checkTable(originalTable, N, K);
		if(result1 == BOTH)
		{
			output<<"Case #"<<cases<<": Both"<<endl;
		}
		else
		{
			bool redWin = false;
			bool blueWin = false;
			int result2 = checkTable(rotatedTable, N, K);
			if(result1 == REDWIN || result2 == REDWIN)
			{
				redWin = true;
			}
			if(result1 == BLUEWIN || result2 == BLUEWIN)
			{
				blueWin = true;
			}
			if(result1 == BOTH || result2 == BOTH)
			{
				redWin = true;
				blueWin = true;
			}
			if(redWin == true && blueWin == true)
			{
				output<<"Case #"<<cases<<": Both"<<endl;
			}
			else if(redWin == true && blueWin == false)
			{
				output<<"Case #"<<cases<<": Red"<<endl;
			}
			else if(redWin == false && blueWin == true)
			{
				output<<"Case #"<<cases<<": Blue"<<endl;
			}
			else
				output<<"Case #"<<cases<<": Neither"<<endl;
		}
	}
	return 0;
}