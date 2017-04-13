#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define rep(i, n) for (int i = 0, _n = n; i < _n; ++i)
#define REP(i, a, b) for (int i = a, _n = b; i < _n; ++i)

int mem[105][105];
const int infty = 1 << 29;

int solve(const vector<int>& v, int b, int e)
{
	int & r = mem[b][e];
	if (r >= 0)
		return r;

	int c = e - b - 1;
	
	if (c == 0)
	{
		r = 0;
		return r;
	}

	if (c == 1)
	{
		r = v[e] - v[b] - 2;
		return r;
	}

	r = infty;

	for ( int i = b + 1; i < e; ++i)
	{
		int num = solve(v, b, i) + solve(v, i, e) + v[e] - v[b] - 2;
		if (num < r) r = num;
	}

	return r;
}

int main()
{
	ifstream cin("C-large.in");
	ofstream cout("C-large.out");

	int tc; cin >> tc;
	rep(t, tc)
	{
		int p, q;
		cin >> p >> q;

		vector <int> v(q);

		rep(i, q) cin >> v[i];

		v.insert(v.begin(), 0);
		v.push_back(p + 1);

		memset(mem, -1, sizeof(mem));

		int r = solve(v, 0, v.size() - 1);

		cout << "Case #"<< (t + 1) <<": " << r << '\n';
	}

	return 0;
}