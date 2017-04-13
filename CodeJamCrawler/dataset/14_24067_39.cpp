#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstdlib>
#define min(a, b) (a < b ? a : b)
#define mp make_pair
#define pb push_back
#define NAME ""

using namespace std;

typedef long double ld;
typedef long long ll;

const int nmax = 2 * 1000 * 100;
const ld pi = M_PI;
const ld inf = 1e17;
const int mod = 1000 * 1000 * 1000 + 7;

ld t, c, f, x;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		cin >> c >> f >> x;
		ld v = 2, answer = inf, tim = 0;
		cout.precision(18);
		for (int i = 0; i < nmax; i++)
		{
			answer = min(answer, x / v + tim);
			tim += c / v;
			v += f;
		}
		cout << "Case #" << q + 1 << ": " << answer << endl;
	}	
}