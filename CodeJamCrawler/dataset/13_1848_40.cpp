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
#define GI              ({int t;scanf("%d",&t);t;})
#define GL              ({LL t;scanf("%lld",&t);t;})
#define GD              ({double t;scanf("%lf",&t);t;})
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
#define FREOPEN 			freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

//Main code begins here
vector < int > v;

template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}

bool ispalin(int n)
{
	string ns = toString(n);
	int l = SZ(ns);
	for(int i=0; i<l/2; ++i)
	{
		if(ns[i] != ns[l-1-i]) return false;
	}
	return true;
}

bool gen()
{
	for(int i = 1; i <=32; ++i)
	{
		if(ispalin(i) && ispalin(i*i)) v.push_back(i*i);
	}
}

int main()
{
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int kase = GI;
	int ret;
	int a, b;

	v.clear();
	gen();

	for(int t = 1; t < kase + 1; ++t)
	{
		ret = 0;
		cin>>a>>b;
		for(int i = 0; i < SZ(v); ++i)
		{
			if(v[i] >= a && v[i]<=b) ret++;
			else if(v[i] > b) break;
		}
		cout<<"Case #"<<t<<": "<<ret<<endl;
	}

	return 0;
}