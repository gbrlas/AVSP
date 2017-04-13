#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <numeric>
#include <iterator>

#define foreach(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define MOD (1000000007)
using namespace std;

long long memorize_dfs(long long x, vector<vector<long long> >& G, vector<long long>& P) {
	if(P[x] != -1)
		return P[x];
	
	long long ret = 1;
	foreach(i, G[x]) {
		ret += memorize_dfs(*i, G, P);
	}
	ret %= MOD;
	P[x] = ret;
//	cout << x << ' ' << ret << endl;
	return ret;
}

int main() {
	long long nn;
	cin >> nn;
	
	for(size_t ii = 0; ii < nn; ++ii)
	{
		long long n, m, X, Y, Z;
		
		cin >> n >> m >> X >> Y >> Z;
		
		vector<long long> A(m);
		
		for(size_t i = 0; i < m; ++i)
		{
			cin >> A[i];
		}
		
		vector<long long> S(n);
		for(size_t i = 0; i < n; ++i)
		{
			S[i] = A[i % m];
			A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
		}

//		copy(S.begin(), S.end(), ostream_iterator<long long>(cout, " "));
//		cout << endl;
		
		vector<vector<long long> > G(n);
		for(size_t i = 0; i < n; ++i)
		{
			for(size_t j = i + 1; j < n; ++j)
			{
				if(S[i] < S[j])
					G[i].push_back(j);
			}
//			cout << G[i].size() << endl;
		}
		
		vector<long long> P(n, -1);
		long long res = 0;
		
		for(size_t i = 0; i < n; ++i)
		{
			res += memorize_dfs(i, G, P);
		}
		res %= MOD;
		
		cout << "Case #" << ii+1 << ": " << res << endl;
	}
}