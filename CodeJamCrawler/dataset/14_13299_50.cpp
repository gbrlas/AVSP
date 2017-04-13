#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int test_case_num;

	scanf("%d", &test_case_num);

	for(int test_case = 0; test_case < test_case_num; ++test_case) {

		vector<int> s;
		int n, t;

		scanf("%d%d", &n, &t);
		s.resize(n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &s[i]);
		sort(s.begin(), s.end());

		int ans = 0;
		vector<bool> used(n, false);

		for(int i = n - 1; i >= 0; --i) {

			if(used[i])
				continue;

			int l = -1;
			for(int j = 0; j < i; ++j) {
				if(used[j]) continue;
				if(s[i] + s[j] > t) break;
				l = j;
			}

			if(l != -1)
				used[l] = true;
			used[i] = true;
			ans += 1;
		}


		printf("Case #%d: %d\n", test_case + 1, ans);
	}

	return 0;
}