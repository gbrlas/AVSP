#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cctype>
#include <ctime>
 
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <list>
#include <iterator>
#include <functional>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long ull;
 
int64 labs(int64 a)
{
        return a<0 ? (-a) : a;
}
int64 max(int64 a, int64 b)
{
        return a>b?a:b;
}
int64 min(int64 a, int64 b)
{
        return a<b?a:b;
}
template<typename T> struct Point
{
        T x, y; Point(){} Point(T xx, T yy): x(xx), y(yy){}
};
template<typename T> bool operator <(const Point<T> &p1, const Point<T> &p2)
{
        return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y;
}
template<typename T> bool operator >(const Point<T> &p1, const Point<T> &p2)
{
        return p1.x > p2.x || p1.x == p2.x && p1.y > p2.y;
}

#define mp make_pair
#define pb push_back
#define forn(i, n) for(int (i)=0; (i)<(n); (i)++)
#define forr(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define forit(i,c) for((i)=(c).begin(); (i)!=(c).end(); (i)++)
#define all(x) (x).begin(), (x).end()
#define zero(a) memset((a), 0, sizeof(a))
 
typedef vector<int> vint;
typedef vector<bool> vbool;
typedef vector<int64> vint64;
typedef Point<int> pint;
typedef Point<int64> pint64;

void SolveA()
{
	cout << endl;
	int n, m;
	cin >> n >> m;

	vector<vector<char>> v(n, vector<char>(m));
	forn(i, n)
	{
		forn(j, m)
		{
			cin >> v[i][j];
		}
	}

	forn(i, n-1)
	{
		forn(j, m-1)
		{
			if (v[i][j] == '#' && v[i+1][j] == '#' 
				&& v[i][j+1] == '#' &&v[i+1][j+1] == '#')
			{
				v[i][j] = v[i+1][j+1] = '/';
				v[i+1][j] = v[i][j+1] = '\\';
			}
		}
	}
	forn(i, n)
	{
		forn(j, m)
		{
			if (v[i][j] == '#')
			{
				cout << "Impossible" << endl;
				return;
			}
		}
	}
		
	forn(i, n)
	{
		forn(j, m)
		{
			cout << v[i][j];
		}
		cout << endl;
	}
}

void SolveHalfB()
{
	int64 n, c, l, t;
	cin >> l >> t >> n >> c;
	vint64 v(c);
	forn(i, c)
	{
		cin >> v[i];
	}
	
	int64 bres = LLONG_MAX;
	int64 a, b;
	forn(p, max(1, (l < 1 ? 0 : n)))
	{
		for(int q = p+1; q < max(p+2, (l < 2 ? 0 : n)); q++)
		{		
			int64 res = 0;
			forn(i, n)
			{
				if (i == p && l >= 1 || i == q && l >= 2)
				{
					if (t <= res)
					{
						res += v[i%c];
					}
					else
					{
						a = min(max(t, res), res + 2*v[i%c]);
						b = a - res;
						res += b/2 + v[i%c];
					}
				}
				else
				{
					res+=2*v[i%c];
				}
			}

			bres = min(bres, res);
		}
	}
	cout << bres << endl;

}

void SolveB()
{
	int64 n, c, l, t;
	cin >> l >> t >> n >> c;
	vint v(c);
	vector<pint> cs(c);
	forn(i, c)
	{
		cin >> v[i];
		cs[i] = pint(v[i], i);
	}

	sort(all(cs));
	
	for(int k=0; k<c; k++)
	{	
		int num = cs[k].y;
	
	
	}

	int64 res = 0;

}

void SolveC()
{

}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int TC;
	cin >> TC;

	forn(i, TC)
	{
		cout << "Case #" << (i+1) << ": ";
		//SolveA();
		SolveHalfB();
		//SolveB();
		//SolveC();
	}
	
	return 0;
}

