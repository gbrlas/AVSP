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
#include <sstream>
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

char buf[50];

inline bool is_sorted(int x) {
	REP(i,x-1) if(buf[i] < buf[i+1]) return false;
	return true;
}

void testcase() {
	int ile[10];
	scanf("%s", buf);
	int n = strlen(buf);
	REP(i,10) ile[i] = 0;
	REP(i,n) ++ile[buf[i]-'0'];
	int non_zero = INT_MAX;
	REP(i,n) if(buf[i]-'0' > 0 && buf[i]-'0' < non_zero)
		non_zero = buf[i]-'0';
	if(is_sorted(n)) {
		printf("%d0", non_zero);
		--ile[non_zero];
		REP(i,10) while(ile[i]--)
			printf("%d", i);
		printf("\n");
		return;
	} else {
		next_permutation(buf,buf+n);
		printf("%s\n", buf);
	}
	
}

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	for(int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		testcase();
	}
	return 0;
}