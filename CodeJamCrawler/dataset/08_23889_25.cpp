#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

int key[1000] = {0};
int f[1010] = {0};

int cmp(const void *a, const void *b);
int main() {

	int tt, tn;
	cin >> tn;

	F1(tt,tn) {
		int ans = 0;
		int P, K, L;
		cin >> P >> K >> L;
		for (int i = 0; i < L; i++)
			cin >> f[i];
		
		qsort(f, L, sizeof(f[0]), cmp);
		
		for (int i = 0; i < L; i++) {
			ans += f[i] * (1 + (i / K));
		}


		if (1 + ((L - 1) / K) > P) printf("Case #%d: Impossible\n", tt);
		else printf("Case #%d: %d\n", tt, ans);
	}

	return 0;
}

int cmp(const void *a, const void *b) {
	int c = *(int*)a;
	int d = *(int*)b;
	if (c < d) return 1;
	return -1;
}
