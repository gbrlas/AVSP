// ProbA.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>

const int Size = 4;
char Board[Size][Size+1];
int TestCount;
FILE *fin, *fout;

void initfiles(){
	fopen_s(&fin, "input.txt", "r");
	fopen_s(&fout, "output2.txt", "w");
}

void closefiles()
{
	fclose(fin);
	fclose(fout);
}

enum EResult
{
	Draw = 0,
	XWon,
	OWon,
	Incomplete
};

bool GameOver(char* a, EResult *presult)
{
	int i;
	bool incomplete = false;
	char ch = 'T';
	for (i = 0; !incomplete && i < Size; i++)
	{
		switch (a[i])
		{
		case 'T':
			break;
		case '.':
			incomplete = true;
			break;
		default:
			if (ch == 'T')
			{
				ch = a[i];
			}
			else if (a[i] != ch)
			{
				incomplete = true;
			}

			break;
		}
	}

	if (incomplete)
	{
		return false;
	}

	if (ch == 'T')
	{
		return false;
	}
	else 
	{
		if (ch == 'X') *presult = XWon;
		else *presult = OWon;
		return true;
	}
}

EResult GetResult()
{
	char row[Size+1] = {0};
	char col[Size+1] = {0};
	char diag1[Size+1] = {0};
	char diag2[Size+1] = {0};

	EResult result;
	bool incomplete = false;

	int i;
	for (i = 0; i < Size; i++)
	{
		int cnt = 0;
		int j;
		for (j = 0; j < Size; j++)
		{
			if (Board[i][j] == '.') 
			{
				incomplete = true;
			}

			row[j] = Board[i][j];
			col[j] = Board[j][i];
		}
	
		if (GameOver(row, &result))
		{
			return result;
		}

		if (GameOver(col, &result))
		{
			return result;
		}
		diag1[i] = Board[i][i];
		diag2[i] = Board[i][Size-i-1];
	}

	if (GameOver(diag1, &result))
	{
		return result;
	}

	if (GameOver(diag2, &result))
	{
		return result;
	}

	return incomplete ? Incomplete : Draw;
}

int _tmain(int argc, _TCHAR* argv[])
{
	initfiles();

	fscanf_s(fin, "%d\n", &TestCount);
	int i, j;
	for (i = 0; i < TestCount; i++)
	{
		for (j = 0; j < Size; j++)
		{
			fscanf_s(fin, "%s\n", Board[j], Size + 1);
		}

		EResult result = GetResult();
		const char* stringResults[] = {
			"Draw", "X won", "O won", "Game has not completed"
		};

		fprintf_s(fout, "Case #%d: %s\n", i+1, stringResults[result]);
		fscanf_s(fin, "\n");
	}

	closefiles();
	return 0;
}

