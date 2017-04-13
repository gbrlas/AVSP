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
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
const int MAXN = 1000000; int minp[MAXN + 1], plist[MAXN + 1];
int prime(int n = MAXN){
	int num = 0; memset(minp, 0, sizeof(minp));
	for(int i = 2; i <= n; i++){
		if(!minp[i]) plist[num++] = i, minp[i] = i;
		for(int j = 0; j < num && i * plist[j] <= n; j++){ minp[i * plist[j]] = plist[j]; if (i % plist[j] == 0) break; }
	}
	return num;
}
multiset<LL> se;
multiset<LL> :: iterator it;
multiset<LL> :: reverse_iterator rit;
int main() {
	int testnum, pn = prime(), upper, cnt;
	LL n, mi, ma, up, tmp;
	
	scanf("%d", &testnum);
	for (int test = 1;test <= testnum;test++) {
		scanf("%lld", &n);
		if (n < 3) {
			printf("Case #%d: %d\n", test, n - 1);
			continue;
		}
		upper = (int)(sqrt(n + 0.0) + 1);
		if ((LL)upper * upper > n)
			upper--;
		mi = 0; ma = 1;
		for (int i = pn - 1;i >= 0;i--)
			if (plist[i] <= upper) {
				upper = i;
				break;
			}
		se.clear();
		for (int i = 0;i <= upper;i++) {
			up = n / plist[i];
			cnt = 0;
			tmp = 1;
			while (tmp <= up) {
				tmp *= plist[i];
				cnt++;
			}
			ma += cnt;
			mi++;
			se.insert(tmp);
		}
		printf("Case #%d: %lld\n", test, ma - mi);
		continue;
		
		while (!se.empty()) {
			rit = se.rbegin();
			tmp = n / (*rit);
			it = se.find(*rit);
			se.erase(it);
			while (tmp > 1) {
				it = se.lower_bound(tmp);
				if (it == se.end())
					break;
				tmp /= (*it);
				se.erase(it);
			}
			mi++;
		}
		printf("Case #%d: %lld\n", test, ma - mi);
	}
	return 0;
}
