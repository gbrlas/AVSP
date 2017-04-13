#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;

bool isPalindrome(int x)
{
	int num = x;
	int n = num;
	int rev = 0;
	while (num > 0)
	{
		rev = rev * 10 + num % 10;
		num = num / 10;
	}
	return rev == n;
}

int work(int a, int b, ofstream &fcout)
{
	int count = 0;
	int left = (int)ceil(sqrt(a));
	int right = (int)sqrt(b);
	for(int i = left; i <= right; i++)
	{
		// fcout << left << ": " << left*left << endl;
		if(isPalindrome(i))
		{
			if(isPalindrome(i*i))
			{
				count++;
				// fcout << "PALINDROME FOUND: " << left << " " << left*left << endl;
			}
		}
	}
	return count;
}

int main()
{
	ifstream fcin("C-small-attempt0.in", ios::in);
	ofstream fcout("C-small-attempt0.out", ios::out);
	int testCases = 0;
	fcin >> testCases;
	
	int (*testCase)[2];
	testCase = new int[testCases][2];

	for(int i = 0; i < testCases; i++)
	{
		for(int line = 0; line < 2; line++)
		{
			fcin >> testCase[i][line];
		}
	}

	for(int i = 0; i < testCases; i++)
	{
		int numFairSquare = work(testCase[i][0], testCase[i][1], fcout);
		fcout << "Case #" << i + 1 << ": " << numFairSquare << endl;
	}

	delete[] testCase;
	cout.flush();
	fcin.close();
	fcout.close();
	return 0;
}