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

int inv(int x, int mod) {
	int y = mod, a = 1, b = 0, k;
	for (; y; swap(x, y), swap(a, b)) {
		k = x / y;
		x -= y * k;
		a -= b * k;
	}
	return a < 0 ? a + mod : a;
}

int sub(int x, int y, int mod) { x -= y; return x < 0 ? x + mod : x; }
int mul(int x, int y, int mod) { return x * ll(y) % mod; }

void Solve(){
	int d, k, L = 1;
	cin >> d >> k;
	int a[k];
	REP (i, k) cin >> a[i];
	if (k > 2) {
		if (a[0] == a[1]) {
			cout << a[0] << endl;
			return;
		}
		REP (i, d) L *= 10;
		vector <bool> p(L + 1);
		for (int x = 2; x * x <= L; ++x)
			if (p[x] == false)
				for (int y = x * x; y <= L; y += x)
					p[y] = true;
		vector <int> res;
		for (int P = max(2, 1 + *max_element(a, a + k)); P <= L; ++P) if (p[P] == false) {
			int A = mul(sub(a[2], a[1], P), inv(sub(a[1], a[0], P), P), P);
			int B = sub(a[1], mul(a[0], A, P), P);
			int s0 = a[0];
			for (int i = 0; i < k; ++i) {
				if (s0 != a[i]) { s0 = -1; break; }
				s0 = mul(s0, A, P) + B;
				if (s0 >= P) s0 -= P;
			}
			if (~s0) res.pb(s0);
		}
		UN(res);
		if (res.size() == 1) {
			cout << res[0] << endl;
			return;
		}
	} else if (k == 2 && a[0] == a[1]) {
		cout << a[0] << endl;
		return;
	}
	puts("I don't know.");
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}
