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
	int n;
	cin >> n;

	vector< vector<char> > v;
	v.assign(n, vector<char>(n));
	vector<double> wp(n, 0), owp(n, 0), oowp(n, 0), tmp(n, 0);
	
	double cnt = 0, sum = 0;
	double cnt1 = 0, sum1 = 0;
	forn(i, n)
	{
		cnt = 0;
		sum = 0;
		forn(j, n)
		{
			cin >> v[i][j];
			if (v[i][j] != '.')
				cnt++;
			if (v[i][j] == '1')
				sum++;
		}
		wp[i] = sum/cnt;
	}
	
	forn(i, n)
	{
		cnt = 0;
		sum = 0;
		forn(j, n)
		{
			if (v[i][j] != '.')
			{
				cnt1 = 0;
				sum1 = 0;
				forn(k, n)
				{
					if (v[j][k]!='.' && k!=i)
					{
						cnt1 ++;
						sum1 += v[j][k] == '1';
					}
				}

				cnt++;
				sum += sum1/cnt1;
			}
		}
		owp[i] = sum/cnt;
	}

	forn(i, n)
	{
		cnt = 0;
		sum = 0;
		forn(j, n)
		{
			if (v[i][j] != '.')
			{
				cnt++;
				sum += owp[j];
			}
		}
		oowp[i] = sum/cnt;
	}

	forn(i, n)
	{
		printf("%.9f\n", 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i]);
	}

}

void SolveB()
{

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
		cout << "Case #" << (i+1) << ":";
		SolveA();
		//SolveB();
		//SolveC();
	}
	
	return 0;
}

