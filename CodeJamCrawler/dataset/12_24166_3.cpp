#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <functional>
#include <utility>
using namespace std;
#define INP(s...) scanf(s)
#define OUP(s...) printf(s)
#define DEB(s...) fprintf(stderr,s)
#define PB push_back
#define MP make_pair
#define SZ(x) (int((x).size()))
#define REP(i,n,s...) for(int(i)=s+0;(i)<(int)(n);++(i))
#define EACH(i,s) for(typeof(s.begin())i=s.begin();i!=s.end();i++)
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
int l[1111], p[1111];
int main() {
	int testnum, n;
	INP("%d", &testnum);
	for (int test = 1;test <= testnum;test++) {
		vector<pair<PII, PII> > q;
		INP("%d", &n);
		REP(i, n) {
			INP("%d", &l[i]);
		}
		REP(i, n) {
			INP("%d", &p[i]);
			q.PB(MP(MP(-l[i] * p[i], -p[i]), MP(-l[i], i)));
		}
		sort(q.begin(), q.end());
		OUP("Case #%d:", test);
		REP(i, n) {
			OUP(" %d", q[i].second.second);
		}
		OUP("\n");
	}
	return 0;
}