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
int num[20], a, b;
int x[5][5], y[5][5];
vector < int > vals;
string ret;

template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);

	int kase;
	cin >> kase;
	for(int tt = 1; tt <= kase; ++tt)
	{
		for(int i = 0; i <= 16; ++i) num[i] = 0;
		vals.clear();

		cin >> a;
		for(int i = 0; i < 4; ++i)
		{
			for(int j = 0; j < 4; ++j)
			{
				cin >> x[i][j];
			}
		}
		cin >> b;
		for(int i = 0; i < 4; ++i)
		{
			for(int j = 0; j < 4; ++j)
			{
				cin >> y[i][j];
			}
		}
		for(int j = 0; j < 4; ++j)
		{
			num[x[a - 1][j]]++;
			num[y[b - 1][j]]++;
		}
		for(int i = 1; i <= 16; ++i)
		{
			if(num[i] == 2) vals.push_back(i);
		}
		if(vals.empty()) ret = "Volunteer cheated!";
		else if(SZ(vals) > 1) ret = "Bad magician!";
		else ret = toString(vals[0]);

		cout << "Case #" << tt << ": " << ret << endl;
	}

	//system("pause");
	return 0;
}
