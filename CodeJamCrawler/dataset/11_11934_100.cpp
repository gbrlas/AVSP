#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long i64;

int cases, n;
int tmp, xorsum, minval;
i64 sum;


int main() {
	//freopen("C-large.in", "r", stdin);
	//freopen("C-large.out", "w", stdout);

	scanf("%d", &cases);
	for(int I = 1; I <= cases; ++I) {
		sum = xorsum = 0;
		minval = 0x33333333;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			sum = sum + tmp;
			xorsum ^= tmp;
			minval = min(minval, tmp);
		}
		if(xorsum)
			printf("Case #%d: NO\n", I);
		else
			printf("Case #%d: %lld\n", I, sum - minval);
	}
	return 0;
}
