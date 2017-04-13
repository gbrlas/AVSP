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
#define acc(f,x,y) x=f(x,y)

#define INF 123456789
#define M 8

string s[M];
int m, n, id[M];

int cost()
{
	int ans = 0;
	rep(c, n)
	{
		set<string> pre;
		rep(i, m) if(id[i] == c)
		rep(j, s[i].size() + 1)
			pre.insert(s[i].substr(0, j));
		ans += pre.size();
	}
	return ans;
}

pii rec(int i)
{
	if(i == m) return {cost(), 1};
	pii ans = {0, 0};
	for(id[i] = 0; id[i] < n; id[i]++)
	{
		pii next = rec(i + 1);
		if(next.first > ans.first)
			ans = next;
		else if(next.first == ans.first)
			ans.second += next.second;
	}
	return ans;
}

pii work()
{
	cin >> m >> n;
	rep(i, m) cin >> s[i];
	return rec(0);
}

int main()
{
	int nc;
	cin >> nc;
	for(int i = 1; i <= nc; i++)
	{
		pii ans = work();
		cout << "Case #" << i << ": " << ans.first << " " << ans.second << endl;
	}
	return 0;
}
