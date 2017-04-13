#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;


#define FOR(i,x,y) for(LL i=x; i<=y; i++)
#define REP(i,n) for(LL i=0; i<n; i++)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define SZ(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define X first
#define Y second



const double eps = 1.0e-11;
const double pi = acos(-1.0);

string pass = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int TESTS;
	scanf("%d\n", &TESTS);

	REP(test, TESTS) {
		string s;
		getline(cin, s);
		printf("Case #%d: ", test + 1);
		REP(i, SZ(s)) {
			if (isalpha(s[i])) {
				cout << pass[s[i] - 'a'];
			} else {
				cout << s[i];
			}
		}
		cout << endl;
	}
	return 0;
}