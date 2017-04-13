#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int cases, n;
int data[1001];
int stack[1001], spt;
double expect;

int main() {
	//freopen("D-large.in", "r", stdin);
	//freopen("D-large.out", "w", stdout);

	scanf("%d", &cases);
	for(int I = 1; I <= cases; ++I) {
		expect = 0.0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &data[i]);
		for(int i = 1; i <= n; ++i) {
			int cnt = 0, tmp;
			spt = 0;
			stack[spt++] = i;
			for(int j = data[i]; j != i; j = data[j]) {
				++cnt;
				stack[spt++] = j;
			}
			for(int j = 0; j < spt; ++j)
				data[stack[j]] = stack[j];
			if(cnt)
				expect += cnt + 1;
		}
		printf("Case #%d: %.6lf\n", I, expect);
	}
	return 0;
}
