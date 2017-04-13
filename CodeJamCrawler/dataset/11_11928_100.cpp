#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int cases, n;
int tmp, sum, xorsum, minval;

int main() {
	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("C-small-attempt0.out", "w", stdout);

	scanf("%d", &cases);
	for(int I = 1; I <= cases; ++I) {
		sum = xorsum = 0;
		minval = 0x33333333;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			sum += tmp;
			xorsum ^= tmp;
			minval = min(minval, tmp);
		}
		if(xorsum)
			printf("Case #%d: NO\n", I);
		else
			printf("Case #%d: %d\n", I, sum - minval);
	}
	return 0;
}
