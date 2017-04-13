#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>
#include<functional>
#include<queue>

#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define FORN(i, a, n) for(int i = (a); i <= (n);i++)
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define ABS(x) (x) > 0 ? (x) : -(x)
#define SIZE(vec) (int)vec.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAX_N = 110;
const ll MOD = 1000002013;
const int INF = 1 << 28;
const double EPS = 1e-9;
const double PI = 3.14159265358979;

int n, m;
int o[MAX_N], e[MAX_N], p[MAX_N];;
int a[MAX_N];

ll solve(){
  ll s = 0;
  REP(i, m){
	ll t = 0;
	int k = n;
	FOR(j, o[i], e[i]){
	  a[j] += p[i];
	  t = (t + (ll)k * p[i]) % MOD;
	  k--;
	}
	s = (s + t) % MOD;
  }
  ll r = 0;
  REP(i, n){
	while(a[i] > 0){
	  int p = i;
	  int k = n;
	  ll t = 0;
	  while(p < n && a[p] > 0){
		a[p]--;
		t = (t + k) % MOD;
		k--;
		p++;
	  }
	  r = (r + t) % MOD;
	}
  }
  return (s - r) % MOD;
}

int main(){
  int T;
  scanf("%d", &T);
  REP(t, T){
	scanf("%d%d", &n, &m);
	REP(i, m){
	  scanf("%d%d%d", &o[i], &e[i], &p[i]);
	  o[i]--;
	  e[i]--;
	}
	printf("Case #%d: %lld\n", t + 1, solve());
  }
  return 0;
}
