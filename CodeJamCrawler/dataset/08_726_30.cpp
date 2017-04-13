#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

typedef long long ll;

const double PI = atan(1.0) * 4.0;
const int inf = 1000000009;
const double eps = 1e-8;

#define F0(i,n) for(int i=0;i<(n);i++)
#define F1(i,n) for(int i=1;i<=(n);i++)

using namespace std;

int main() {
    int caseN;
    scanf("%d", &caseN);

    for (int cas = 1; cas <= caseN; ++cas) {

	int K, P, L;
	scanf("%d%d%d", &P, &K, &L);

	ll f[L];
	for (int i = 0; i < L; ++i)
	    scanf("%lld", &f[i]);

	sort(f, f+L, greater<ll>());
//	for (int i = 0; i < L; ++i)
//	    printf("%lld ", f[i]);
//	printf("\n");

	ll cnt = 0;
	for (int i = 0; i < L; ++i)
	    cnt += f[i] * (i/K + 1);

	printf("Case #%d: %d\n", cas, cnt);
    }

    return 0;
}
