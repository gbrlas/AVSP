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

const int mod = 100003;

int C[555][555];
int F[555][555];

int f(int x, int i) {
	if (i == 1) return 1;
	int &res = F[x][i];
	if (res < 0) {
		res = 0;
		for (int j = 1; j < i; ++j)
			res += f(i, j) * C[i - j - 1][x - i - 1], res %= mod;
	}
	return res;
}

void Solve(){
	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i < n; ++i)
		res += f(n, i), res %= mod;
	cout << res << endl;
}

int main(){
	REP (n, 555)
		REP (k, 555)
			if (k == 0 || k == n) C[k][n] = 1;
			else C[k][n] = (C[k - 1][n - 1] + C[k][n - 1]) % mod;
	CL(F, -1);
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	int a = 0, b;
	for(cin >> b; a++ < b ; Solve()) printf("Case #%d: ", a);
	return 0;
}
