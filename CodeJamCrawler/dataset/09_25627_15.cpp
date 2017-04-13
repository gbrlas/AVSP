#include <cstdio>
#include <algorithm>
#include <vector>

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int p, q, n, pri[10001];
vector < pair<int,int> > seg;

int solve() {
	int t, best = 10000000;
	seg.clear();
	seg.push_back(make_pair(1, p));
	
	sort(pri, pri + q);
	do {
		//printf("NEW PERM P = %d\n", p);
		//printf("Size %d, [0] %d %d\n", (int)seg.size(), seg[0].first, seg[0].second);
		t = 0;
		FOR(k,0,q) {
			FOR(i,0,seg.size()) {
				if (seg[i].first <= pri[k] && pri[k] <= seg[i].second) {
		//			printf("%d is on %d to %d\n", pri[k], seg[i].first, seg[i].second);
		//			printf("%d + %d\n", t, seg[i].second -seg[i].first );
					t += seg[i].second - seg[i].first;
					seg.push_back(make_pair(pri[k]+1, seg[i].second));
					seg[i].second = pri[k] - 1;
					break;
				}
			}
		}
		if (t < best) best = t;
		seg.clear(); seg.push_back(make_pair(1, p));
		//printf("t = %d\n", t);
	} while (next_permutation(pri, pri + q));
//	printf("best = %d\n", best);
	return best;
}

int main() {

	scanf("%d", &n);
	FOR(i,0,n) {
//		printf("NEW TEST\n");
		scanf("%d %d", &p, &q);
		FOR(j,0,q)	scanf("%d", &pri[j]);
		printf("Case #%d: %d\n", i+1, solve());
	}


	return 0;
}