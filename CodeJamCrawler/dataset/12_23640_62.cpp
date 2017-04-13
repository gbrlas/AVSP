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

#define dbg(x)
#define trace()

#else

#define dbg(x) do { cout << "DEBUG, line " << __LINE__ << " (" << __func__ << "), " << #x << ": " << x << endl; } while(0)
#define trace() do { cout << "TRACE, line " << __LINE__ << " (" << __func__ << ")" << endl; } while(0)

#endif

const int N = 2003;
const int INF = 100000000;
int nx[N];
int h[N];
int tan[N];
int n;

bool check(){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(nx[i] > j && nx[j] > nx[i]) return false;
		}
	}
	return true;
}

void go(int fst){
	dbg(fst);
	int lst = fst;
	while(h[lst]==-1) {
		lst = nx[lst];
	}
	dbg(lst);
	int v = fst;
	int newtan = tan[lst]+1;
	while(h[v]==-1){
		h[v] = h[lst] - (lst-v)*tan[lst];
		tan[v] = newtan;
		v = nx[v];
	}
	tan[lst] = newtan;
}

typedef long long LL;
bool ccw(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3){
	x2-=x1; y2-=y1;
	x3-=x1; y3-=y1;
	return x2*y3 > x3*y2;
}

int next(int v){
	int res = v+1;
	for(int u = v+2; u<n; u++){
		if(ccw(v, h[v], res, h[res], u, h[u])) res = u;
	}
	return res;
}

void solve(){
	scanf("%d",&n);
	for(int i=0; i<n-1; i++){
		scanf("%d", &nx[i]);
		nx[i]--;
	}
	nx[n-1]=n-1;

	if(!check()){
		printf("Impossible\n");
		return;
	}

	for(int i=0; i<n; i++) h[i] = -1;
	h[n-1] = INF;
	tan[n-1] = 0;

	//for(int i=0; i<n; i++) printf("%d) h %d, nx %d\n", i, h[i], nx[i]);

	for(int i=0; i<n; i++) if(h[i]==-1){
		go(i);
	}

	for(int i=0; i<n; i++) printf("%d ", h[i]); printf("\n");

	for(int i=0; i<n-1; i++){
		//printf("checking %d: nx %d, real nxt %d\n", i, nx[i], next(i));
		assert(next(i)==nx[i]);
	}

}

int main(){
	int t; scanf("%d",&t);
	for(int tc=1; tc<=t; tc++){
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
