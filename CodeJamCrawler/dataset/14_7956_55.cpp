#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	int ctr1 = 1;
	while (t--) {
		double c, f, x, t1 = 0.0, t2=0.0, ans = 0.0;
		scanf("%lf%lf%lf", &c, &f, &x);
		double r = 2.0;
		while (1) {
			t1 = x / r;
			t1 = t1 + ans;
			t2 = c / r;
			t2 = t2 + x / (r + f);
			t2 = t2 + ans;
			if (t1 < t2) {
				ans = t1;
				break;
			}
			else
				ans += c/r;
			r = r + f;
		}
		printf("Case #%d: %0.7lf\n", ctr1, ans);
		ctr1++;
	}
	return 0;
}

			