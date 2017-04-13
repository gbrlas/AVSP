/*
Title: B
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

#define InputFileName		"B-small-attempt0.in"
#define OutputFileName		"B-small-attempt0.out"

using namespace std;

const int MaxN = 1100, Fail = 10000;
const double EPS = 1E-5;

int n, TestCase;
double x[MaxN], y[MaxN], w, l, r[MaxN];

inline void Get(double &x, double &y)
{
	x = (double)rand()*rand()/36767/36767*w;
	y = (double)rand()*rand()/36767/36767*l;
}

inline bool Check(const int i)
{
	for (int j = 1; j < i; ++j)
		if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= (r[i]+r[j])*(r[i]+r[j])+EPS)
			return 0;
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
		cout << "Case #" << T << ": " << setprecision(6) << fixed;
		cin >> n >> w >> l;
		for (int i = 1; i <= n; ++i)
			cin >> r[i];
		for (int i = 1, j, k; i <= n; ++i)
		{
			cerr << i << endl;
			k = 0;
			for (Get(x[i], y[i]); ! Check(i) && k <= Fail; Get(x[i], y[i]), ++k);
			cout << x[i] << " " << y[i] << " ";
			if (k > Fail)
			{
				cerr << "Fail" << endl;
				while (1);
			}
		}
		cout << endl;
	}
	return 0;
}
