#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int calcNormal(vector<int> &ord)
{
	int n = ord.size() / 2;
	int ans = 0;

	int kencount = 0;

	for(int p = n * 2 - 1; p >= 0; --p) {

		if(ord[p] == 1) {
			kencount += 1;
			continue;
		}

		if(kencount > 0)
			kencount -= 1;
		else
			ans += 1;

	}

	return ans;
}

int calcDec(vector<int> &ord)
{
	int n = ord.size() / 2;
	int ans = 0;

	int kencount = 0;

	for(int p = 0; p < n * 2; ++p) {

		if(ord[p] == 1) {
			kencount += 1;
			continue;
		}

		if(kencount > 0) {
			kencount -= 1;
			ans += 1;
		}
	}

	return ans;
}

int main()
{
	int testcase;

	scanf("%d", &testcase);

	for(int casenum = 0; casenum < testcase; ++casenum) {

		int n;
		vector<pair<double, int> > li;
		vector<int> ord;

		scanf("%d", &n);

		li.resize(n * 2);
		for(int i = 0; i < n; ++i)
			scanf("%lf", &li[i].first);
		for(int i = 0; i < n; ++i)
			scanf("%lf", &li[i + n].first);
		for(int i = 0; i < n * 2; ++i)
			li[i].second = i / n;

		sort(li.begin(), li.end());
		ord.resize(n * 2);
		for(int i = 0; i < n * 2; ++i)
			ord[i] = li[i].second;

		/*for(int i = 0; i < n * 2; ++i)
			printf("%d ", ord[i]);
		printf("\n");*/

		int normal = calcNormal(ord);
		int dec = calcDec(ord);

		printf("Case #%d: %d %d\n", casenum + 1, dec, normal);
	}

	return 0;
}