#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
#define MAXN 1010

int T, N;
int casenum = 0;
double C, F, X, t, s;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		s = 0;
		t = 2;
		scanf("%lf%lf%lf", &C, &F, &X);
		while(C/t + X/(t + F) < X/t) {
			s += C/t;
			t += F;
		}
		s += X/t;


		printf("Case #%d: %.7lf\n", casenum++, s);

	}
	return 0;
}
