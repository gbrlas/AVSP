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

ll L;
int n, a[111];
int f[1000000];

void Solve(){
	cin >> L >> n;
	REP (i, n) cin >> a[i];
	sort(a, a + n);
	f[0] = 0;
	FOR (i, 1, 1000000) {
		f[i] = -1u/4;
		REP (j, n) if (a[j] <= i)
			f[i] <?= f[i - a[j]] + 1;
	}
	ll res = L + 1;
	if (L < 1000000) res = f[(int)L];
	else {
		REP (i, n) {
			ll k = (L - 1000000) / a[i] + 1;
			int r = L - a[i] * k;
			if (f[r] != -1u/4) {
				res <?= k + f[r];
			}
		}
	}
	if (res <= L) cout << res << endl;
	else puts("IMPOSSIBLE");
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}
