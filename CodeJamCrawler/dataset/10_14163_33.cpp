#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int T, a, b, caseNo = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %s\n", ++caseNo,
			(b % (1 << a)) + 1 == (1 << a) ? "ON" : "OFF");
	}
	return 0;
}
