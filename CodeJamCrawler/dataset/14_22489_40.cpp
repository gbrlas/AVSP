#include <bits/stdc++.h>
using namespace std;
int TC, N, X, cnt;
multiset<int> s;
int main () {
	freopen("datapacking.in", "r", stdin);
	freopen("datapacking.out", "w", stdout);
	
	scanf("%d", &TC);
	for (int T = 1; T<=TC; ++T) {
		scanf("%d%d", &N, &X);
		cnt = 0;
		for (int i = 0, a; i < N; ++i) {
			scanf("%d", &a);
			s.insert(a);
		}
		for (multiset<int>::iterator it = s.begin(); it != s.end();) {
			//printf("find %d - ", *it);
			if (X-*it < *it) {
				s.erase(it++);
				++cnt;
				continue;
			}
			multiset<int>::iterator it2 = s.upper_bound(X-*it);
			--it2;
			//printf("%d\n", *it2);
			if (it2 == it) {
				s.erase(it++);
				++cnt;
			}
			else {
				s.erase(it2);
				s.erase(it++);
				++cnt;
			}
		}
		assert(s.size() == 0);
		printf("Case #%d: %d\n", T, cnt);
	}
}
