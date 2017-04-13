// ProbC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

FILE *fin, *fout;

#define _countof(x) (sizeof(x) / sizeof(x[0]))

bool initfiles(){
	errno_t error;

	error = fopen_s(&fin, "C-small-attempt0.in", "r");
	if (error != 0)
	{
		printf("Cannot read input file: 0x%X\n", error);
		return false;
	}

	error = fopen_s(&fout, "output-small.txt", "w");
	if (error != 0)
	{
		printf("Cannot read output file: 0x%X\n", error);
		return false;
	}

	return true;
}

void closefiles()
{
	if (fin != NULL) fclose(fin);
	if (fout != NULL) fclose(fout);
}

int GetSqrt(long long x)
{
	long long v = (long long) sqrt(1.0 * x);

	//
	// In case of rounding problem
	//
	if (v * v > x) v = v - 1;
	else if ((v+1) * (v+1) <= x) v = v + 1;

	return (int)v;
}

bool IsPalindrome(long long x)
{
    char st[20];
	int l = 0;
	
	do
	{
		st[l] = '0' + (x % 10);
		x /= 10;
		l++;
	} while (x > 0);
	
	for (int i = 0; i < l/2; i++)
		if (st[i] != st[l-i-1]) return false;

	return true;
}

int SolveEasy(long long lo, long long hi)
{
	int sqrlo = GetSqrt(lo - 1) + 1;
	int sqrhi = GetSqrt(hi);
	
	int cnt = 0;
	for (int i = sqrlo; i <= sqrhi; i++)
	{
		if (IsPalindrome(i) && IsPalindrome(((long long)i) * i))
		{
			printf("%d %I64d\n", i, 1LL * i * i);
			cnt++;
		}
	}

	printf("\n");
	return cnt;
}

string Reverse(const string &x)
{
	return string(x.rbegin(), x.rend());
}

string AddReverse(const string &a, const string &b)
{
	string result;
	int c = 0;

	for (int i = 0; i < a.size() || i < b.size() || c > 0; i++)
	{
		if (i < a.size()) c += a[i] - '0';
		if (i < b.size()) c += b[i] - '0';
		result.push_back('0' + (c%10));

		c /= 10;
	}

	return result;
}

string MultReverse(const string &a, int b)
{
	string result;
	int c = 0;
	for (int i = 0; i < a.size() || c > 0; i++)
	{
		if (i < a.size())
		{
			c = (a[i]-'0') * b + c;
		}

		result.push_back('0' + (c%10));
		c /= 10;
	}
	
	return result;
}

string Add(const string &a, const string &b)
{
	return Reverse(AddReverse(Reverse(a), Reverse(b)));
}

string CalcSquare(const string &x)
{
	string y = Reverse(x);
	string t;
	string result = "0";
	for (int i = 0; i < y.size(); i++)
	{
		t = MultReverse(y, y[i] - '0');
		t.insert(t.begin(), i, '0');
		result = AddReverse(result, t);
	}

	return Reverse(result);
}

int Compare(const string &x, const string &y)
{
	if (x.size() != y.size()) return (x.size() < y.size() ? -1 : 1);
	int i;
	for (i = 0; i < x.size(); i++)
		if (x[i] != y[i]) return x[i] < y[i] ? -1 : 1;
	return 0;
}

int Search(const string *palinds, int n, string x)
{
	int l = 0, r = n;

	while (l < r)
	{
		int mid = (l + r) / 2;
		string sq = CalcSquare(palinds[mid]);
		if (Compare(sq, x) < 0) l = mid + 1;
		else r = mid;
	}

	return l;
}

int SolveMedium(string lo, string hi)
{
	const string palinds[] = {"1", "2", "3", "11", "22", "101", 
	"111", "121", "202", "212", "1001", 
	"1111", "2002", "10001", "10101", "10201", "11011", 
	"11111", "11211", "20002", "20102", "100001", "101101", "110011", 
	"111111", "200002", "1000001", "1001001", "1002001", "1010101", "1011101", "1012101", "1100011", "1101011", "1102011", "1110111", 
	"1111111", "2000002", "2001002"};

	string hip = Add(hi, "1");
	int n = _countof(palinds);

	return Search(palinds, n, hip) - Search(palinds, n, lo);
}

void Test()
{
}


int _tmain(int argc, _TCHAR* argv[])
{
	if (!initfiles()) return -1;
	int testCount;
	int iTest;
	fscanf_s(fin, "%d\n", &testCount);
	
	const int MaxL = 105;
	char lo[MaxL], hi[MaxL];

	Test();
	for (iTest = 0; iTest < testCount; iTest++)
	{
		fscanf_s(fin, "%s %s\n", &lo, _countof(lo), &hi, _countof(hi));
		fprintf_s(fout, "Case #%d: %d\n", iTest+1, SolveMedium(lo, hi));
		/*long long lov, hiv;
		fscanf_s(fin, "%I64d %I64d\n", &lov, &hiv);
		fprintf_s(fout, "Case #%d: %d\n", iTest+1, SolveEasy(lov, hiv));*/
	}
	closefiles();
	return 0;
}

