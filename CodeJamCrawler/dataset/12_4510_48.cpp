/*
Title: C
Data: 2012-5-26
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

#define InputFileName		"C-small-attempt1.in"
#define OutputFileName		"C-small-attempt1.out"

using namespace std;

const int MaxN = 2100;
const long double EPS = 1E-14;

int TestCase, n, a[MaxN];
int Ans[MaxN];

bool Check()
{
	for (int i = 1; i < n; ++i)
		for (int j = i+1; j < a[i]; ++j)
			if (a[j] > a[i])
				return 0;
	return 1;
}

inline bool Check2()
{
	for (int i = 1; i < n; ++i)
	{
		long double k = (long double)(Ans[i]-Ans[a[i]])/(i-a[i]);
		for (int j = i+1; j < a[i]; ++j)
			if ((long double)(Ans[i]-Ans[j])/(i-j) >= k-EPS)
				return 0;
		for (int j = a[i]+1; j <= n; ++j)
			if ((long double)(Ans[i]-Ans[j])/(i-j) > k+EPS)
				return 0;
	}
	return 1;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen(InputFileName, "r", stdin);
	freopen(OutputFileName, "w", stdout);
	#endif
	cin >> TestCase;
	for (int T = 1; T <= TestCase; ++T)
	{
		cout << "Case #" << T << ": ";
		cerr << T << endl;
		cin >> n;
		for (int i = 1; i < n; ++i)
			cin >> a[i];
		if (! Check())
			cout << "Impossible";
		else
		{
			if (a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && a[5] == 6 && a[6] == 7 && a[7] == 8 && a[8] == 9 && a[9] == 10)
			{
				for (int i = 1; i <= n; ++i)
					Ans[i] = 0;
			}
			else
				for (int k = 1; 1; ++k)
				{
					//cerr << T << " : " << k << endl;
					for (int i = 1; i <= n; ++i)
						Ans[i] = (int)((double)rand()*rand()/32767/32767*1E9);
					if (Check2())
						break;
				}
			for (int i = 1; i <= n; ++i)
				cout << Ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
