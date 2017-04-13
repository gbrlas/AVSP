// ProbB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <algorithm>

using namespace std;

FILE *fin, *fout;

bool initfiles(){
	errno_t error;

	error = fopen_s(&fin, "input.txt", "r");
	if (error != 0)
	{
		printf("Cannot read input file: %X\n", error);
		return false;
	}

	error = fopen_s(&fout, "output.txt", "w");
	if (error != 0)
	{
		printf("Cannot read output file: %X\n", error);
		return false;
	}

	return true;
}

void closefiles()
{
	if (fin != NULL) fclose(fin);
	if (fout != NULL) fclose(fout);
}

const int MaxSize = 101;
const int MaxHeight = 100;

int a[MaxSize][MaxSize];
int N, M;

bool Solve()
{
	int row[MaxSize], col[MaxSize];
	int i, j;
	for (i = 0; i < N; i++) row[i] = 0;
	for (i = 0; i < M; i++) col[i] = 0;

	for (i = 0; i < N; i++) for (j = 0; j < M; j++)
	{
		row[i] = max(row[i], a[i][j]);
		col[j] = max(col[j], a[i][j]);
	}

	for (i = 0; i < N; i++) for (j = 0; j < M; j++)
	{
		if (a[i][j] != min(row[i], col[j])) return false;
	}

	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (!initfiles()) return -1;

	int testCount;
	int iTest;
	fscanf_s(fin, "%d\n", &testCount);
	for (iTest = 0; iTest < testCount; iTest++)
	{
		fscanf_s(fin, "%d %d\n", &N, &M);
		int i, j;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				fscanf_s(fin, "%d", &a[i][j]);
			}
			fscanf_s(fin, "\n");
		}

		fprintf_s(fout, "Case #%d: %s\n", iTest+1, Solve() ? "YES" : "NO");
	}
	closefiles();
	return 0;
}

