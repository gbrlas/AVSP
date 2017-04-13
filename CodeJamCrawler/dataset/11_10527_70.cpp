#include<cstdio>

using namespace std;

int main() {
	int t, casen = 0, n, sum, xorsum, min;
	int c[1000];
	scanf("%d",&t);
	while(casen++ < t) {
		scanf("%d",&n);
		sum = xorsum = 0;
		min = 1000001;
		for(int i = 0; i < n; i++) {
			scanf("%d",&c[i]);
			sum += c[i];
			xorsum ^= c[i];
			if(c[i] < min) min = c[i];
		}
		if(!xorsum) {
			printf("Case #%d: %d\n",casen,sum-min);
		} else {
			printf("Case #%d: NO\n",casen);
		}
	}
}
