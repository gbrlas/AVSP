#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
using namespace std;

#ifdef moskupols 
    #define debug(...) fprintf(stderr, __VA_ARGS__) // thank Skird it's friday!
#else
    #define debug(...) 
#endif

#define timestamp(x) debug("["#x"]: %.3f\n", (double)clock() / CLOCKS_PER_SEC)

const long long modulo = 1000002013;


int n, m;
inline long long cost(int a, int b)
{
	return (n*n - (b-a)*(b-a-1)/2) % modulo;
}

long long solve()
{
	cin >> n >> m;
	vector<int> v;
	vector< pair< pair<int,int>, int > > p;

	long long ret = 0;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		ret = (ret + cost(a, b)*c%modulo) % modulo;
		p.push_back(make_pair(make_pair(a,b), c));
		v.push_back(a);
		v.push_back(b);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int k = v.size();

	vector<int> st(k), fn(k);
	for (int i = 0; i < m; ++i)
	{
		int a = lower_bound(v.begin(), v.end(), p[i].first.first) - v.begin();
		int b = lower_bound(v.begin(), v.end(), p[i].first.second) - v.begin();
		st[a] += p[i].second;
		fn[b] += p[i].second;
	}

	vector<int> cnt(k);

	for (int i = 0; i < k; ++i)
	{
		cnt[i] += st[i];
		for (int j = i; j >= 0 && fn[i]; --j)
		{
			int d = min(fn[i], cnt[j]);
			ret = (ret - cost(v[j],v[i])*d%modulo + modulo) % modulo;
			cnt[j] -= d;
			fn[i] -= d;
		}
	}
	return ret;
}

int main()
{
	cin.sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		cout << "Case #" << i+1 << ": " << solve() << endl;

	timestamp(end);
	return 0;
}
