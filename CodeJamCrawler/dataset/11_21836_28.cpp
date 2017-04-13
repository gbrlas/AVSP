#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

bool isSquare(long long num)
{
	long long l = 0, r = 2000000000LL, x = 0;
	while (l < r - 1)
	{
		x = (l + r) >> 1;
		if (x * x <= num) l = x; else r = x;
	}
	return l * l == num;
}

long long getDecimal(string binary)
{
	long long decValue = 0;
	for(int bit = 0; bit < binary.length(); bit++)
		decValue = decValue * 2 + binary[bit] - '0';
	return decValue;
}

string fillMarks(string arg, int mask)
{
	int seen = 0;
	string res = "";
	for(int ind = 0; ind < arg.length(); ind++)
		if (arg[ind]=='?')
		{
			if (mask & (1 << seen)) res+="1"; else res+="0";
			seen++;
		} else res += arg[ind];
	return res;
}

int main()
{
	freopen("c:/input.txt" , "r" , stdin);
	freopen("c:/output.txt" , "w" , stdout);
	int T, number = 0;
	cin>>T;
	while(T--) {
		string sq, input;
		cin >> input;
		int marks = 0;
		for(int i = 0; i < input.length(); i++)
			marks += input[i] == '?';
		for(int mask = 0; mask < 1 << marks; mask++)
			if (isSquare(getDecimal(fillMarks(input, mask))))
			{
				sq = fillMarks(input, mask);
				break;
			}
		cout << "Case #" << ++number << ": " << sq << endl;
	}

	return 0;
}