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

		int n, p, q, r, s;
		vector<int64> score, sum;
		int64 total, maximum;

		scanf("%d%d%d%d%d", &n, &p, &q, &r, &s);
		score.resize(n);
		sum.resize(n);
		for(int i = 0; i < n; ++i) {
			score[i] = (i * (int64)p + (int64)q) % (int64)r + (int64)s;
			sum[i] = score[i] + (i > 0 ? sum[i - 1] : 0);
		}
		total = maximum = sum[n - 1];

		//for(int i = 0; i < n; ++i)
		//	printf("%lld%c", score[i], i < n - 1 ? ' ' : '\n');

		for(int a = 0; a < n; ++a) {

			int64 lv = a > 0 ? sum[a - 1] : 0;
			int64 half = (total - lv) / 2;

			int b = -1;
			int lb = a, hb = n - 1;

			if(score[lb] >= half)
				b = a;
			while(b == -1 && (hb - lb) > 1) {
				int mb = (hb + lb) / 2;
				if(sum[mb] - lv >= half)
					hb = mb;
				else
					lb = mb;
			}
			if(b == -1)
				b = lb;

			int64 mv, rv;

			mv = sum[b] - lv;
			rv = total - sum[b];
			maximum = min(maximum, max(lv, max(mv, rv)));
			//printf("debug: %lld %lld %lld\n", lv, mv, rv);

			if(b < n - 1) {
				mv = sum[b + 1] - lv;
				rv = total - sum[b + 1];
				maximum = min(maximum, max(lv, max(mv, rv)));
				//printf("debug: %lld %lld %lld\n", lv, mv, rv);
			}
		}

		double ans = (double)(total - maximum) / total;

		printf("Case #%d: %.10lf\n", test_case + 1, ans);
	}

	return 0;
}