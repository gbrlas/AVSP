/* Piotr Zielinski, Uniwersytet Jagiellonski */

#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <list>
#include <deque>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define FORE(it,V) for( __typeof(V.begin()) it = V.begin(); it != V.end(); ++it)
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(),x.end()

typedef long long ll;

int DP[520][20];
char buf[520];

string tekst = "welcome to code jam";

void testcase() {
	gets(buf);
	int dl = strlen(buf);
	REP(i,dl) REP(j,tekst.length()) DP[i][j] = 0;
	REP(i,dl) REP(j,tekst.length())
		if(buf[i] == tekst[j]) {
			if(j) { 
				REP(k,i) DP[i][j] = (DP[k][j-1] + DP[i][j])%10000;
			}
			else DP[i][j] = 1;
		}
	int result = 0;
	REP(i,dl) result += DP[i][ tekst.length() -1 ];
	result %= 10000;
	if(result < 10) printf("0");
	if(result < 100) printf("0");
	if(result < 1000) printf("0");
	printf("%d\n", result);
}

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	REP(i,t) {
		printf("Case #%d: ", i+1);
		testcase();
	}
	return 0;
}