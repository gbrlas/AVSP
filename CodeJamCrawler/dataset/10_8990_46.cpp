// GCJ Round 3 2010 -- Sat Jun 12 2010
// Problem A
//
// pre-written code follows
// pre-written code follows
// #includes {{{
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// }}}
// constants, typedefs, macros {{{
typedef long long LL;
typedef unsigned long long ULL;
const int oo = 1000000000;
const LL OO = 1000000000000000000LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<string> VS;
typedef queue<int> QI;
typedef queue<PII> QPII;
typedef complex<double> tComp;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
#define FORIT(i,c) for (typeof((c).end()) i=(c).begin(); i!=(c).end(); ++i)
#define CERR(x) cerr << (#x) << " = " << (x) << endl
#define COUT(x) cout << (#x) << " = " << (x) << endl
// }}}

// code written during the competition follows
VI primes;
void init()
{
	const int MAX = 1000000;
	VI c(MAX);
	for (int i=2; i<MAX; i++)
		if (!c[i])
		{
			primes.push_back(i);
			for (int j=2*i; j<MAX; j+=i)
				c[j] = 1;
		}
}
int main()
{
	init();
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		int d, k;
		cin >> d >> k;
		vector<LL> a;
		for (int i=0; i<k; i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
		}
		int p = 1;
		for (int i=0; i<d; i++)
			p *= 10;
		int max_a = *max_element(a.begin(), a.end());
		set<int> values;
		if (k != 1)
		{
			FORIT(it, primes)
			{
				if (*it <= max_a)
					continue;
				if (*it >  p)
					continue;
				int pr = *it;
				for (int i=0; i<pr; i++)
				{
					LL b = a[1] - a[0] * i;
					b %= pr;
					if (b < 0)
						b += pr;
					bool good = true;
					for (int j=1; j+1<k; j++)
						if ((a[j] * i + b) % pr != a[j+1])
						{
							good = false;
						}
					if (good)
					{
						values.insert((a[k-1] * i + b) % pr);
						if (values.size() >= 2)
							goto done;
					}
				}
			}
			done:;
		}
		printf("Case #%d: ", tkase+1);
		if (values.size() == 1)
		{
			cout << *values.begin() << endl;
		}
		else
		{
			cout << "I don't know." << endl;
		}
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
