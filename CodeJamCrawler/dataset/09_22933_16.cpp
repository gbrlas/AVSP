#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <vector>
#include <cctype>
#include <cmath>
#include <list>
#include <string>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <algorithm>
#include <stack>
#include <numeric>
#include <bitset>
#include <ext/numeric>

#define DISP(v,i) for(typeof(v.begin()) i=v.begin();i!=v.end();++i) printf("%d ",*i); printf("\n")
#define DTAB(i,start,end) for(int i=0;i<end-start;++i) printf("%d ",*(start+i)); printf("\n")
#define PRI(a) printf(#a": %d\n",a)
#define PRF(a) printf(#a": %f\n",a)

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORTO(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,b,a) for(int i=(b);i>=(a);--i)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define ZLO printf("ZLOOOOOOO!\n"); return 1
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define GCD __gcd

using namespace std;
using namespace __gnu_cxx;

inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }

int toi(char ch) { return int(ch)-int('0'); }
int chg(char ch) { return int(ch)-int('a'); }

typedef long long LL;
typedef unsigned long long ULL;
typedef double D;
typedef long double LD;
typedef unsigned U;
typedef vector<int> VI;
typedef pair<int,int> PI;
typedef vector<string> VS;

const int INF=2000000000;
const double EPS=1e-10;

int main() {
	int t;
	scanf("%d",&t);
	REP(CASE,t) {
		int ans=0;
		int n;
		scanf("%d",&n);getchar();
		char a[50];
		int tab[50];
		REP(i,n) {
			gets(a);
			int l=-1;
			REP(j,n)
				if(a[j]=='1') l=j;
			tab[i]=l;
		}
		int k=n-1;
		FOR(i,0,n-1) {
			if(tab[i]<=i) continue;
			FOR(j,i,n) {
				if(tab[j]<=i) {
					FORD(k,j,i+1) {
						swap(tab[k],tab[k-1]);
						++ans;
						//printf("%d %d %d\n",i,k-1,k);
					}
					break;
				}
			}
		}
		printf("Case #%d: %d\n",CASE+1,ans);
	}
	return 0;
}

