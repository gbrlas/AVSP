/*
Title: C
Data: 2012-4-14
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define InputFileName		"C-small-attempt0.in"
#define OutputFileName		"C-small-attempt0.out"

using namespace std;

const int MaxN = 3000000;

int n = 2000000, a, b, Ans, TestCase;
bool Flag[MaxN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(InputFileName, "r", stdin);
	freopen(OutputFileName, "w", stdout);
	#endif
	cin >> TestCase;
	for (int T = 1; T <= TestCase; ++T)
	{
		cin >> a >> b;
		Ans = 0;
		for (int i = a, j, k; i <= b; ++i)
		{
			ostringstream ssout;
			ssout << i;
			string s = ssout.str();
			istringstream(s) >> k;
			Flag[k] = 1;
			for (j = 0; s[j]; ++j)
			{
				istringstream(s) >> k;
				if (! Flag[k] && k >= a && k <= b)
				{
					Flag[k] = 1;
					++Ans;
				}
				s = s.substr(s.length()-1, 1)+s.substr(0, s.length()-1);
			}
			istringstream(s) >> k;
			Flag[k] = 0;
			for (j = 0; s[j]; ++j)
			{
				istringstream(s) >> k;
				Flag[k] = 0;
				s = s.substr(s.length()-1, 1)+s.substr(0, s.length()-1);
			}
		}
		Ans /= 2;
		cout << "Case #" << T << ": " << Ans << endl;
	}
	return 0;
}
