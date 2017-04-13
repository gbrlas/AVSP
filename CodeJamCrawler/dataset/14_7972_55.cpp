#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	int  c = 1;
	while (t--) {
		int n,ctr = 0,pos = 0,ctr1 = 0;
		scanf("%d", &n);
		vector <double> a(n);
		vector <double> b(n);
		for (int i = 0; i < n; i++) {
			scanf("%lf", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%lf", &b[i]);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++) {
			if (pos == n)
				break;
			for (int j = pos; j < n; j++) {
				if (b[j] > a[i]) {
					ctr++;
					pos = j+1;
					break;
				}
			}
		}
		pos = 0;
		for (int i = 0; i < n; i++) {
			if (pos == n)
				break;
			for (int j = pos; j < n; j++) {
				if (a[j] > b[i]) {
					ctr1++;
					pos = j+1;
					break;
				}
			}
		}
		printf("Case #%d: %d %d\n",c,ctr1, n-ctr);
		c++;
	}
	return 0;
}