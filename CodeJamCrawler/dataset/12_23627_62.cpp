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

const int N = 10005;
int n;
int d[N],l[N];
int best[N];
const int INF = 1000000009;

void solve(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &d[i], &l[i]);
		best[i] = INF;
	}
	scanf("%d",&d[n]);
	best[n] = INF;

	best[0]=0;
	for(int i=0; i<n; i++){
		if(best[i]==INF) continue;

		int mx = d[i] + min(l[i], d[i]-best[i]);
		for(int j=i+1; j<=n; j++){
			if(d[j] > mx) break;
			best[j] = min(best[j], d[i]);
		}
	}
	if(best[n]<INF) printf("YES\n");
	else printf("NO\n");
}

int main(){
	int t; scanf("%d",&t);
	for(int tc=1; tc<=t; tc++){
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
