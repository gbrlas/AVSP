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
const double EPS=1e-10;;
	
char num[30];

int main() {
	int t;
	scanf("%d",&t);
	getchar();
	REP(CASE,t) {
		printf("Case #%d: ",CASE+1);
		gets(num);
		int len=strlen(num);
		reverse(num,num+len);
		bool good=false;
		FOR(i,1,len) {
			if(num[i]<num[i-1]) good=true;
			else continue;
			int wat=i-1;
			REP(j,i-1)
				if(num[j]<num[wat]&&num[j]>num[i]) wat=j;
			swap(num[i],num[wat]);
			reverse(num,num+len);
			sort(num+len-i,num+len);
			puts(num);
			break;
		}
		if(good) continue;
		sort(num,num+len);
		int k=0;
		for(k=0;k<len;++k) if(num[k]!='0') break;
		putchar(num[k]); ++k;
		REP(i,k) putchar('0');
		for(;k<len;++k) putchar(num[k]);
		puts("");
	}
	return 0;
}

