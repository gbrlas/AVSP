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
int p;
int s[2];
int casenum = 1;
double n[2][MAXN];

void read_sort(int idx){
	for(int i = 0; i < N; i++) {
		scanf("%lf", &n[idx][i]);
	}
	sort(n[idx], n[idx] + N);
}

int main() {

	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &T);
	while (T--) {

		scanf("%d", &N);
		read_sort(0);
		read_sort(1);


		s[0] = s[1] = 0;

		// first solution
		p = N - 1;
		for(int i = N - 1; i >= 0; i--) {
			if(n[0][p] > n[1][i]) {
				s[0]++;
				p--;
			}
		}

		// second solution
		p = 0;
		for(int i = 0; i < N; i++) {
			if(n[0][p] > n[1][i]) {
				s[1]++;
			} else {
				p++;
			}
		}

		printf("Case #%d: %d %d\n", casenum++, s[0], s[1]);

	}
	return 0;
}
