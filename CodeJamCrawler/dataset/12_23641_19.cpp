#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
#include<sstream>
#include<set>
#include<cctype>
#include<cassert>
using namespace std;

#ifdef ONLINE_JUDGE

#define assert(x)
#define dbg(x)
#define trace()

#else

#define dbg(x) do { cout << "DEBUG, line " << __LINE__ << " (" << __func__ << "), " << #x << ": " << x << endl; } while(0)
#define trace() do { cout << "TRACE, line " << __LINE__ << " (" << __func__ << ")" << endl; } while(0)

#endif

const int N = 10000;
struct x{
	int p,l,nr;
}X[N];;

bool operator < (x a, x b){
	int p = a.l + b.l*a.p;
	int q = b.l + a.l*b.p;
	if(p==q) return a.nr < b.nr;
	return q < p;
}

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		X[i].nr = i;
		scanf("%d", &X[i].l);
	}
	for(int i=0; i<n; i++){
		scanf("%d", &X[i].p);
	}
	sort(X,X+n);
	for(int i=0; i<n; i++) printf("%d ", X[i].nr);
	printf("\n");
}

int main(){
	int t;
	scanf("%d",&t);
	for(int tc=1; tc<=t; tc++){
		printf("Case #%d: ", tc);
		solve();
	}
}
