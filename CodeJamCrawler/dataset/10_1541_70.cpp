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

int n, k, b, t;
int x[55], v[55];

void Solve(){
	cin >> n >> k >> b >> t;
	REP (i, n) cin >> x[i];
	REP (i, n) cin >> v[i];
	int res = 0, mk = 0;
	REP (i, n) if (x[i] + v[i] * t >= b) ++mk;
	if (mk < k) puts("IMPOSSIBLE");
	else {
		for (int i = n - 1; k > 0 && i >= 0; --i)
			if (x[i] + v[i] * t < b)
				res += k;
			else --k;
		cout << res << endl;
	}
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}
