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
 
deque<pint> v1, v2;
void SolveA()
{
	int n;
	cin >> n;
	char c;
	int a;
	forn(i, n)
	{
		cin >> c >> a;
		if(c == 'O')
		{
			v1.push_back(pint(i, a));	
		}
		else
		{
			v2.push_back(pint(i, a));		
		}
	}

	int cur = 0;
	int p1 = 1, p2 = 1;
	
	int time;
	for(time = 0; !v1.empty() || !v2.empty(); time++)
	{
		bool b = 0;
		if (!v1.empty())
		{
			if (p1 < v1.front().y)
			{
				p1++;
			}
			else if (p1 > v1.front().y)
			{
				p1--;
			}
			else
			{
				if (v1.front().x == cur)
				{
					v1.pop_front();	
					b = 1;
				}
			}
		}

		if (!v2.empty())
		{
			if (p2 < v2.front().y)
			{
				p2++;
			}
			else if (p2 > v2.front().y)
			{
				p2--;
			}
			else
			{
				if (v2.front().x == cur)
				{
					v2.pop_front();	
					b  = 1;
				}
			}
		}
		cur += b;
	}
	cout << time;
}

void SolveB()
{
	map< pair<char, char>, char > combine;
	map<char, char> remove;
	map<char, bool> has;
	
	int n;
	string s;
	cin >> n;
	forn(i, n)
	{
		cin >> s;
		combine[mp(s[0], s[1])] = s[2];
		combine[mp(s[1], s[0])] = s[2];
	}

	cin >> n;
	forn(i, n)
	{
		cin >> s;
		remove[s[0]] = s[1];
		remove[s[1]] = s[0];
	}

	cin >> n >> s;
	vector<char> v;
	forn(i, n)
	{
		v.push_back(s[i]);
		while(v.size()>1 && combine.find(mp(v[v.size()-1], v[v.size()-2])) != combine.end())
		{
			char a, b;
			a = v.back(); v.pop_back();
			b = v.back(); v.pop_back();
			v.push_back(combine[mp(a, b)]);
		}

	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	forn(i, t)
	{
		cout << "Case #" << i+1 << ": ";
		SolveA();
		cout << endl;
	}

	return 0;
}

