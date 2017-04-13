//Karol Farbiś - xneby
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <functional>
#include <complex>

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef complex<LL> PL;
typedef complex<double> P;
template<class T> T operator&(const complex<T>& a, const complex<T>& b){return real(a)*real(b)+imag(a)*imag(b);}
template<class T> T operator|(const complex<T>& a, const complex<T>& b){return real(a)*imag(b)-imag(a)*real(b);}
template<class T> bool operator||(const complex<T>& a, const complex<T>& b){return a|b==0;}
template<class T> bool operator&&(const complex<T>& a, const complex<T>& b){return a&b==0;}

const LD EPS = 1e-6;
const LL INF = 1000000000000000000LL;
const int SINF = 1000000000;

#define REP(I, N) for(int I=0; I<(N); ++I)
#define FOR(I, M, N) for(int I=(M); I<=(N); ++I)
#define FORD(I, M, N) for(int I=(M); I>=(N); --I)
#define EACH(it, x) for(typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(), (x).end()

#ifdef DEBUG

#define D(x) printf("%s: %d\n", #x, (x))
#define Ds(x) printf("%s: %s\n", #x, (x))
#define Dt(x,n) do { printf("%s:\n", #x); REP(_i, (n)) printf("%d ", (x)[_i]); printf("\n"); } while(0)
#define Dtz(x,s,k) do { printf("%s <%d, %d):\n", #x, (s), (k)); FOR(_i, (s), (k)) printf("%d ", (x)[_i]); printf("\n"); } while(0)
#define DUPA printf("dupa from line %d\n", __LINE__)
#define Dbg printf
#include <iostream>

#else

#define D(x)
#define Ds(x)
#define Dt(x,n)
#define Dtz(x,s,k)
#define DUPA
#define Dbg(...)

#endif

const int MAX_N = 507;

int tab[MAX_N][MAX_N];
int pref[MAX_N][MAX_N];

int n,m;
LL check(int a, int b, int c, int d){
	if(c-a!=d-b)return 0;
	double X=0, Y=0;
	double cx = (c+a)/2.0, cy = (d+b)/2.0;
	FOR(i,a,c)FOR(j,b,d){
		if(i==a && j==b) continue;
		if(i==c && j==b) continue;
		if(i==a && j==d) continue;
		if(i==c && j==d) continue;
		X += tab[i][j] * (cx-i);
		Y += tab[i][j] * (cy-j);
	}

	if(abs(X)<10e-6 && abs(Y)<10e-6)
		return c-a+1;
	return 0;
}

void solve(){
	scanf("%d %d %*d", &n, &m);
	FOR(i,1,n)FOR(j,1,m){
		char c;
		scanf(" %c", &c);
		tab[i][j] = c-'0';
	}
	FOR(i,1,n)FOR(j,1,m)pref[i][j] = tab[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];

	LL wy = 0;
	FOR(i,1,n){
		FOR(j,1,m){
			FOR(k,i+2,n)
				FOR(l,j+2,m)
			wy=max(wy, check(i,j,k,l));
		}
	}
	if(wy)
		printf("%lld\n", wy);
	else
		puts("IMPOSSIBLE");
}

int main(int argc, char** argv, char** envp){
	int t;
	scanf("%d", &t);

	FOR(i,1,t){
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
