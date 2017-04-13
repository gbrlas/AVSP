#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int cases, n, l, h;
int data[10000];

bool check(int val) {
	for(int i = 0; i < n; ++i)
		if(max(val, data[i]) % min(val, data[i]) != 0)
			return false;
	return true;
}

bool find() {
	for(int i = l; i <= h; ++i)
		if(check(i)) {
			printf("%d\n", i);
			return true;
		}
	return false;
}

int main() {
//	freopen("C-small-attempt0.in", "r", stdin);
//	freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &cases);
	for(int I = 1; I <= cases; ++I) {
		scanf("%d%d%d", &n, &l, &h);
		for(int i = 0; i < n; ++i)
			scanf("%d", &data[i]);
		printf("Case #%d: ", I);
		if(!find()) puts("NO");
	}
	return 0;
}