#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <complex>
#include <cctype>
#include <ctime>
using namespace std;

//Commonly used macros
#define FOREACH(i,a)    for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define SZ(a)           (int)(a.size())
#define ALL(a)          (a).begin(),(a).end()
#define SORT(a)         sort(ALL(a));
#define REVERSE(a)      reverse(ALL(a))
#define UNIQUE(a)       SORT(a),(a).resize(unique(ALL(a))-(a).begin())
#define IN(a,b)         ((b).find(a)!=(b).end())
#define fill(x,a)       memset(x, a, sizeof(x))
#define abs(a)          ((a)<0?-(a):(a))
#define maX(a,b)        ((a)>(b)?(a):(b))
#define miN(a,b)        ((a)<(b)?(a):(b))
#define checkbit(n,b)   ((n>>b)&1)
#define INDEX(arr,ind)	(lower_bound(all(arr),ind)-arr.begin())

//Main code begins here
#define EPS 	(double(1e-7))

double c, f, x, ret;
double rate, otbuy, tbuy, tgen;

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);

	int kase;
	cin >> kase;
	for(int tt = 1; tt <= kase; ++tt)
	{
		cin >> c >> f >> x;
		ret = 0.0; rate = 2.0;

		while(1)
		{
			otbuy = (x/rate);
			tbuy = (c/rate);
			tgen = (x/(rate + f));
			if(otbuy + EPS < tbuy + tgen) {ret += otbuy; break;}
			else
			{
				ret += tbuy;
			}
			rate += f;
		}
		printf("Case #%d: %.7lf\n", tt, ret);
	}

	//system("pause");
	return 0;
}
