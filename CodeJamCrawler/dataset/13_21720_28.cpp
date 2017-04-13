#include <cstdio>
#include <map>
#include <stack>
#define M 1000002013ll
using namespace std;
typedef long long ll;
typedef pair<int, ll> pl;
ll n, tc, m;
map<int, ll> s, f;
stack<pl> st;
ll calc (int start, int end) {
	int x = end-start;
	return (((2*n)%(M*2)+((x-1)*(-1))%(M*2))*x/2)%M;
}
int main () {
	scanf("%lld", &tc);
	for (int t = 1; t <= tc; ++t) {
		scanf("%lld%lld", &n, &m);
		s.clear();
		f.clear();
		ll ori = 0;
		for (ll i = 0, x, y, p; i < m; ++i) {
			scanf("%lld%lld%lld", &x, &y, &p);
			s[x] += p;
			s[y] -= p;
			ori += (calc(x, y)*p)%M;
		}
		ll cur = 0, cost = 0;
		for (map<int, ll>::iterator it = s.begin(); it != s.end(); ++it) {
			cur += it->second;
			f[it->first] = cur;
		}
		while (true) {
			ll mini = 1000000000000000000ll;
			for (map<int, ll>::iterator it = f.begin(); it != f.end(); ++it) {
				if (it->second == 0) continue;
				mini = min(it->second, mini);
			}
			if (mini == 1000000000000000000ll) break;
			ll dist = 0;
			for (map<int, ll>::iterator it = f.begin(); it != f.end();) {
				if (it->second == 0) {
					//printf("-> %lld %lld\n", dist, mini);
					cost += (calc(0, dist)*mini)%M;
					cost %= M;
					dist = 0;
					++it;
				}
				else {
					ll curN = it->first;
					it->second -= mini;
					++it;
					dist += it->first - curN;
				}
			}
		}
		ll ans = ((ori - cost)+M)%M;
		printf("Case #%d: %lld\n", t, ans);
	}
}