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

const int mod = 1000000007;

int sub(int x, int y) { x -= y; return x < 0 ? x + mod : x; }
int sum(int x, int y) { x += y; return x < mod ? x : x - mod; }
int mul(int x, int y) { return x * ll(y) % mod; }

ll n;
int b, m;
int a[70];
int F[2][70][71][70];
int G[2500][71][71];
int C[100][100], FF[100];

int g(int s, int k, int x0) {
	if (k == 0) return s == 0;
	if (s < 0 || x0 == b || s >= 2500) return 0;
	int &res = G[s][k][x0];
	if (res < 0) res = sum(g(s, k, x0 + 1), g(s - x0, k - 1, x0 + 1));
	return res;
}

int f(int i, int d, int k0, int k) {
	if (i == m) return d == 0 && k0 == 0;
	int &res = F[k0][i][k][d];
	if (res < 0) {
		res = 0;
		for (int z = k0; z <= k; ++z) {
			for (int D = 0; D < b; ++D) {
				int q = g(D * b + a[i] - d, z, 1);
				int r = f(i + 1, D, 0, z); 
				if (i) {
					int qq = mul(FF[z], C[z - k0][k - k0]);
					r = mul(qq, r);
				}
				res += mul(q, r);
				if (res >= mod) res -= mod;
			}
		}
		for (int z = 0; z < k; ++z) {
			for (int D = 0; D < b; ++D) {
				int q = g(D * b + a[i] - d, z, 1);
				int r = f(i + 1, D, 1, z + 1);
				if (i) {
					int qq = mul(FF[z + 1], C[z + 1 - k0][k - k0]);
					r = mul(r, qq);
				}
				res += mul(q, r);
				if (res >= mod) res -= mod;
			}
		}
	}
	return res;
}

void Solve(){
	cin >> n >> b;
	m = 0;
	for (; n; n /= b) a[m++] = n % b;
	CL(F, -1), CL(G, -1);
	cout << f(0, 0, 0, b) << endl;
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	FF[0] = 1;
	for (int n = 1; n < 100; ++n)
		FF[n] = mul(FF[n - 1], n);
	for (int n = 0; n < 100; ++n)
		for (int k = 0; k <= n; ++k)
			if (k == 0 || k == n) C[k][n] = 1;
			else C[k][n] = sum(C[k - 1][n - 1], C[k][n - 1]);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}
