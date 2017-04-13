#include <string>	
#include <string.h>
#include <cstdio>	
#include <iostream>	
#include <memory>	
#include <cstdlib>	
#include <cmath>	
#include <algorithm>
#include <set>		
#include <map>		
#include <vector>
#include <ctime>	
#include <cassert>

using namespace std;

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define I64 "%I64d"
#else
#define I64 "%Ld"
#endif

#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define dbg(x) cerr << #x << " = " << (x) << endl
#define fori(i,b,e) for(int i = (b); i < (e); i++)
#define forall(p,s) for(typeof((s).begin()) p = (s).begin(); p != (s).end(); p++)
#define memclr(a) memset((a), 0, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define fi first
#define se second

typedef long double ldb;
typedef long long int64;
const int inf = (int)1e9;

#define PROBLEM_NAME "b"

char comb[256][256];
bool opp[256][256];
char s[1000];

int main () {
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
	int TT;
	scanf ("%d", &TT);
	fori(tt, 1, TT+1) {
		memset(comb, 0, sizeof(comb));
		memset(opp, 0, sizeof(opp));
		int k;
		scanf ("%d", &k);
		fori(i,0,k) {
			scanf ("%s", s);
			comb[(int)s[0]][(int)s[1]] = s[2];
			comb[(int)s[1]][(int)s[0]] = s[2];
		}
		scanf ("%d", &k);
		fori(i,0,k) {
			scanf ("%s", s);
			opp[(int)s[0]][(int)s[1]] = true;
			opp[(int)s[1]][(int)s[0]] = true;
		}
		int n;
		scanf ("%d", &n);
		scanf ("%s", s);
		vector<char> ans;
		fori(i,0,n) {
			int c = s[i];
			if (sz(ans) != 0 && comb[(int)ans[sz(ans)-1]][c] != 0) {
				char res = comb[(int)ans[sz(ans)-1]][c];
				ans.pop_back();
				ans.pb(res);
			} else {
				ans.pb((char)c);
				fori(i,0,sz(ans)-1) {
					if (opp[(int)ans[i]][c]) {
						ans.clear();
						break;
					}
				}
			}
		}
		printf ("Case #%d: ", tt);
		printf ("[");
		fori(i,0,sz(ans)-1) {
			printf ("%c, ", ans[i]);
		}
		if (sz(ans) != 0) {
			printf ("%c", ans[sz(ans)-1]);
		}
		printf ("]\n");
	}
	return 0;
}
