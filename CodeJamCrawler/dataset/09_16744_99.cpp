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

vector<string> nazwy;
set<char> zbior[20];
char kodzio[10000];

void testcase() {
	int l, d, n;
	scanf("%d%d%d", &l, &d, &n);
	REP(i,d) {
		char buf[20];
		scanf("%s", buf);
		string s = buf;
		nazwy.PB(s);
	}
	REP(i,n) {
		printf("Case #%d: ", i+1);
		scanf("%s", kodzio);
		int gdzie = 0, latacz = 0;
		while(gdzie < l) {
			if(kodzio[latacz] != '(') {
				zbior[gdzie].insert(kodzio[latacz]);
				++gdzie;
				++latacz;
				continue;
			} else {
				++latacz;
				while(kodzio[latacz] != ')') {
					zbior[gdzie].insert(kodzio[latacz]);
					++latacz;
				}
				++latacz;
				++gdzie;
			}
		}
		int result = 0;
		REP(j,d) {
			bool zle = false;
			REP(a,l) if(zbior[a].find( nazwy[j][a] ) == zbior[a].end()) zle = true;
			if(!zle) ++result;
		}
		printf("%d\n", result);
		REP(a,l) zbior[a].clear();
	}
}

int main() {
	testcase();
	return 0;
}