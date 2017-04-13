#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

//Problem: recycled numbers.
//	A <= n < m <= B
// a recycled pair is where you move the end of an int
//	string to the beginning and it is still with in the range.

struct SymPair
{
	int a, b;
	SymPair(int aa, int bb)
		:a(aa), b(bb)
	{}

	bool operator==(const SymPair& p) const
	{
		return a == p.a && b == p.b
				||	a == p.b && b == p.a;
	}

	bool operator<(const SymPair& p) const
	{
		return a < p.a
				|| a == p.a && b < p.b;
	}
};

int numOfPossibleRecycledNumbers(int A, int B);
int numOfDigits(int number);
int moveXDigitsToFront(int x, int number, int size);

int main()
{
	int numOfCases;
	cin >> numOfCases;

	for(int caseNum = 1; caseNum <= numOfCases; ++caseNum)
	{
		int from, to;
		scanf("%d %d", &from, &to);
		cout << "Case #" << caseNum << ": "
			<< numOfPossibleRecycledNumbers(from, to) << endl;
	}
	
	return 0;
}

int numOfPossibleRecycledNumbers(int A, int B)
{
	set<SymPair> results;
	for(int i = A; i <= B; ++i)
	{
		int iSize = numOfDigits(i);
		int lastLeft, lastRight;
		for(int k = 1; k < iSize; ++k)
		{
			int result = moveXDigitsToFront(k, i, iSize);
			if(i < result && result <= B)
				results.insert(SymPair(i, result));
		}
	}
	//cout << "pairs: " << results.size() << endl;
	//cout << "----------------" << endl;
	//for(set<SymPair>::iterator it=results.begin(); it!=results.end(); ++it)
	//	cout << it->a << " = " << it->b << endl;

	return results.size();
}

int numOfDigits(int number)
{
	int k = 0, count = 0;
	while((number / pow(10.0, k++)) > 1)
		++count;
	
	return count;
}

int moveXDigitsToFront(int x, int number, int size)
{
	
	int a = number / (int)pow(10.0, x);
	int b = number % (int)pow(10.0, x) * (int)pow(10.0, size-x);
	return a + b;
	/*
	return
		number / pow(10.0, x)
		+	number % (int)pow(10.0, x) * pow(10.0, size-x);
		*/
}

