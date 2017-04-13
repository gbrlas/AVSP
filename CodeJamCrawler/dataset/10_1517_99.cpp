#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define UN(v)       sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> point;

int r, k, n;
int g[1024], c[1024], next[1024];
int b[1024];
ll a[1024];

void Solve(){
	cin >> r >> k >> n;
	REP (i, n) cin >> g[i];
	ll t = 0;
	for (int i = 0, j = 0; i < n; t -= g[i++]) {
		if (j < i) t = 0, j = i;
		for (; j - i < n && t + g[j % n] <= k; t += g[j++ % n]);
		c[i] = t;
		next[i] = j % n;
	}
	ll res = 0;
	vi p;
	int i = 0;
	for (; r > 0 && !b[i]; i = next[i], --r) {
		b[i] = true;
		res += c[i];
		a[i] = res;
		p.pb(i);
	}
	int T = p.size() - (find(all(p), i) - p.begin());
	if (T) {
		res += (r / T) * (res + c[i] - a[i]);
		r %= T;
	}
	for (; r > 0; i = next[i], --r) res += c[i];
	cout << res << endl;
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}
