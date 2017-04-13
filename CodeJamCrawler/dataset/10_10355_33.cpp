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

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
typedef pair<int, int> PII;

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

#else

#define D(x)
#define Ds(x)
#define Dt(x,n)
#define Dtz(x,s,k)
#define DUPA

#endif

bool test(int k, long long n){
	LL K = (1<<k)-1;
	return (n|K)==n;
}

int main(int argc, char** argv, char** envp){
	int q;
	scanf("%d", &q);
	FOR(i,1,q){
		int n;
		long long k;
		scanf("%d %lld", &n, &k);
		printf("Case #%d: %s\n", i, test(n,k)?"ON":"OFF");
	}
	return 0;
}
