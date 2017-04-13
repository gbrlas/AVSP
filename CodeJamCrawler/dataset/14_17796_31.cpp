#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define clr1(i) CLR(i,-1)
#define bit(x,i) ((x>>i)&1)
#define M(x) ((x)%MOD)
#define acc(f,x,y) x=f(x,y)

int n;

bool works(vi & a)
{
	int m = 1;
	while(m < n && a[m] > a[m - 1])
		m++;
	range(j, m, n) if(a[j] > a[j - 1])
		return false;
	return true;
}

int solve()
{
	cin >> n;

	vi a;
	rep(i, n)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}

	map<vi, int> d;
	list<vi> q{a};
	d[a] = 0;
	while(!q.empty())
	{
		vi x = q.front();
		if(works(x)) return d[x];
		q.pop_front();
		rep(i, n - 1)
		{
			vi y = x;
			swap(y[i], y[i + 1]);
			if(!d.count(y))
			{
				d[y] = d[x] + 1;
				q.push_back(y);
			}
		}
	}

	return -1;
}

int main()
{
	int nc;
	cin >> nc;
	for(int i = 1; i <= nc; i++)
		cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
