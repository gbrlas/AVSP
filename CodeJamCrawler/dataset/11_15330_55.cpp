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

int n,m;

const int MAX_N = 2007;

int pocz[MAX_N];
int kon[MAX_N];
int res[MAX_N];

vector<VI> cykle;

int isin(vector<int> x, int v){
	FOR(i,0,x.size()-1){
		if(x[i] == v)return i;
	}
	return -1;
}

void polacz(int a, int b){
	VI t1, t2;
	EACH(it, cykle){
		int x = isin(*it, a);
		int y = isin(*it, b);
		if(x==-1 || y==-1)continue;
		if(x>y)swap(x,y);
		FOR(i,x,y){
			t1.PB((*it)[i]);
		}
		FOR(i,y,it->size()-1)
			t2.PB((*it)[i]);
		FOR(i,0,x){
			t2.PB((*it)[i]);
		}
		cykle.erase(it);
		break;
	}
	cykle.PB(t1);
	cykle.PB(t2);
}

bool next(int wy){
	FORD(i,n,1){
		if(res[i] == wy)
			res[i] = 1;
		else{
			res[i]++;
			return true;
		}
	}
	return false;
}

bool bylo[MAX_N];

bool check(int wy){
	EACH(x,cykle){
		fill(bylo+1,bylo+1+wy,false);
		EACH(v,*x)
			bylo[res[*v]]=1;
		FOR(i,1,wy)if(!bylo[i])return false;
	}
	return true;
}

int solve(){
	scanf("%d %d", &n, &m);
	FOR(i,1,m){
		scanf("%d", pocz + i);
	}
	FOR(i,1,m){
		scanf("%d", kon + i);
	}
	VI t;
	FOR(i,1,n)t.PB(i);
	cykle.clear();
	cykle.PB(t);
	FOR(i,1,m){
		polacz(pocz[i], kon[i]);
	}
	
	int wy=n;
	EACH(it, cykle){
		wy = min(wy, (int)it->size());
	}

	FOR(i,1,n){
		res[i] = 1;
	}

//	puts("cykle:");
//	EACH(x,cykle){
//		EACH(r,*x)printf("%d ", *r);
//		puts("");
//	}

	while(next(wy)){
//		FOR(i,1,n){
//			printf("%d ", res[i]);
//		}
//		puts("");
		if(check(wy))
			return wy;
	}
	return -1;
}

int main(int argc, char** argv, char** envp){
	int t;
	scanf("%d", &t);

	FOR(i,1,t){
		printf("Case #%d: %d\n", i, solve());
		FOR(i,1,n){
			printf("%d ", res[i]);
		}
		puts("");
	}

	return 0;
}
