#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define MP make_pair
#define FS first
#define SC second
#define SZ size() 


using namespace std;


VI qs;

map<pair<int,int>, int > calc;

int cnt(int a, int b)
{
	if (b<a)
		return 0;

	if (calc.count(MP(a,b))!=0)
		return calc[MP(a,b)];

	int &res = calc[MP(a,b)];

	int max_res = INT_MAX;

	REP(i, qs.size())
	{
		if (qs[i] > b)
			break;

		if (qs[i] >= a)
		{
			int res_new = b-a + cnt(a, qs[i]-1)+cnt(qs[i]+1, b);
			max_res = min(max_res, res_new);
		}
	}

	if (max_res != INT_MAX)
		res = max_res;


	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;

	REP(t,T)
	{
		int N;

		cin >> N;

		VS m;
		REP(n, N)
		{
			string s;
			cin >> s;
			m.PB(s);
		}

		int res = 0;

		VI v;
		for(int n = 0; n<N; ++n)
		{
			int p = 0;
			for(int c=0; c < N; ++c)
				if (m[n][c] == '1')
					p = c;

			v.PB(p);
		}

		for(int n = 0; n<N; ++n)
		{
			if (v[n] > n)
			{
				for(int e = n+1; e < N; ++e)
				{
					if (v[e] <= n)
					{
						for(int k = e; k > n; --k)
						{
							swap(v[k],v[k-1]);
							res++;
						}
						break;
					}


				}
			}
		}




		cout << "Case #" << (t+1) << ": " << res << "\n";
		cerr << "Case #" << (t+1) << ": " << res << "\n";
	}




}