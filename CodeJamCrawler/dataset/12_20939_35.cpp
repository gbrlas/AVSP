#include <iostream>
#include <cstdio>
using namespace std;
int tc;
int main () {
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		int n, s, p, o=0, x;
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			if ( (x + (3-(x%3))%3 )/3 >= p) o++;
			else if (x == 0) continue;
			else if (x % 3 == 0 && x/3 >= p-1) {
				if (s > 0) {
					s--;
					o++;
				}
			}
			else if (x % 3 == 1) continue;
			else if (x % 3 == 2 && x/3 >= p-2) {
				if (s > 0) {
					s--;
					o++;
				}
			}
		}
		printf("Case #%d: %d\n", t, o);
	
	}
}
