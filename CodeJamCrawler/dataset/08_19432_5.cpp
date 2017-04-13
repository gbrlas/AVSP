#define dbg(x) {cout << #x << " -> " << (x) << "\t";}
#define dbge(x) {cout << #x << " -> " << (x) << "\n";}

using namespace std;
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

#define INF (int)1e9
#define V(x) vector< x >
#define LET(x,a) typeof(a) x(a)
#define FOR(i,a,b) for(LET(i,(a));i!=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(it,v) FOR(it,(v).begin(),(v).end())
#define ALL(f,x) ({ bool _ok = true ; f if( ! (x) ) { _ok=false; break; } ; _ok; })
#define EXISTS(f,x) ({ book _ok=false; f if( x ) { _ok=true;break;} ; _ok; })
#define COUNT(f,x) ({int _cnt=0; f if (x) ++_cnt; _cnt; })
#define sz size()
#define cs c_str()
#define pb push_back
#define GI ({int t;scanf("%d",&t); t;})
#define MIN(f,x) ({int k=INF;f k<?=(x);k;})
#define MAX(f,x) ({int k=0;f k>?=(x);k;})
#define s2i(s) ({int i;sscanf((s).cs,"%d",&i);i;})

typedef V(int) VI;
typedef V(string) VS;
typedef V(VI) VII;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;

int N, p, k, l, f[1001], pos[1001];
int main() {
	cin >> N;

	REP(tt, N) {
		memset(f, 0, sizeof(l));
		cin >> p >> k >> l;
		REP(i, l) cin >> f[i];
		sort(f, f+l);
		reverse(f, f+l);
		//pos[i] - position in that key ; no of kp = sigma([i]*pos[i])
		memset(pos, -1, sizeof(pos));
		int cnt = 1;
		for(int i =0;i<l;i+=k) {
			if(cnt > p) break;
			REP(j, k) {
				if(i+j<l && pos[i+j] == -1) pos[i+j] = cnt;			
			}	
			cnt++;
		}
		int flag=0;
		REP(i, l) if(pos[i] == -1) flag = 0;
		if(flag) { printf("Case #%d: Impossible\n", tt+1); continue;}
		LL ret = 0;
		REP(i, l) ret += pos[i]*f[i];			
		printf("Case #%d: %d\n", tt+1, ret); 
	}
	return 0;
}

