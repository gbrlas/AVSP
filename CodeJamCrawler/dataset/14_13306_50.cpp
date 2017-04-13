#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;

int main()
{
	int test_case_num;

	scanf("%d", &test_case_num);

	for(int test_case = 0; test_case < test_case_num; ++test_case) {

		int n;
		vector<int> a;
		vector<pair<int, int> > b;
		int64 ans = 0;

		scanf("%d", &n);
		a.resize(n);
		b.resize(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			b[i] = make_pair(a[i], i);
		}

		sort(b.begin(), b.end());

		for(int i = 0; i < n; ++i) {

			int pos = b[i].second;
			int h = b[i].first;

			int l = 0;
			int r = 0;

			for(int p = 0; p < pos; ++p) {
				if(a[p] > h) l += 1;
			}

			for(int p = pos + 1; p < n; ++p) {
				if(a[p] > h) r += 1;
			}

			ans += min(l, r);
		}

		printf("Case #%d: %lld\n", test_case + 1, ans);
	}

	return 0;
}