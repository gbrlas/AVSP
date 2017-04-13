#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define FILL(a,val) memset((a),(int)val,sizeof(a));
#define CLEAR(a) FILL(a,0)
#define REP(i,n) for (int i=0, _n=(n); i<_n; ++i)
#define FOR(i,a,b) for (int i=(a), _n=(b); i<_n; ++i)
#define REPD(i,n) for (int _n=(n), i=_n; i>=0; --i)
#define FORD(i,b,a) for (int _n=(b), _a=(a), i=_n; i>=_a; --i)
#define PB push_back
#define VI vector<int>
#define VVI vector< VI >
#define MII map<int,int>
#define SZ(x) (x.size())

template <class T> inline void checkmin(T& a, const T& b){if (b<a) a=b;}
template <class T> inline void checkmax(T& a, const T& b){if (b>a) a=b;}
template <class T> inline T sqr(const T&a){return a*a;}
//bool myfunc(int i,int j){return i<j;}
//////////////////////////////////////////
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
//////////////////////////////////////////

//double round(double d){
//	return d>=0? floor(d+0.5): -floor(-d+0.5);
//}

const int MAX = 1000+1;
int C[MAX];

int main(){
	freopen("C-small-attempt0.in", "rt", stdin);
    freopen("C-small-attempt0.out", "wt", stdout);
	int T;
	scanf("%d",&T);

	REP(t,T){
		int N;
		scanf("%d",&N);

		REP(i,N) scanf("%d",&C[i]);
		int total=0;
		REP(i,N) total^=C[i];
		if (total!=0){
			printf("Case #%d: NO\n",t+1);
		}else{
			LL sum=0;
			int min_el=C[0];
			REP(i,N){
				min_el=min(min_el,C[i]);
				sum+=C[i];
			}
			printf("Case #%d: %d\n",t+1,sum-min_el);
		}

		//output	
		
	}

	return 0;
}