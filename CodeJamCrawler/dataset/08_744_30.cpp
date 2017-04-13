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
	ll n, m, X, Y, Z;
	scanf("%lld%lld%lld%lld%lld", &n, &m, &X, &Y, &Z);
	
	ll A[m];
	for (int i = 0; i < m; ++i) {
	    scanf("%lld", &A[i]);    
//	    printf("%lld ", A[i]);
	}
//	printf("\n");

	ll sign[n + 1];
	for (int i = 0; i < n; ++i){
	    sign[i + 1] = A[i%m];
	    A[i%m] = (X * A[i%m] + Y * (i+1)) % Z;		
	}

//	for (int i = 1; i <= n; ++i)
//	    printf("%lld ", sign[i]);
//	printf("\n");

	sign[0] = -1;

	ll table[n+1][n+1];
	for (int i = 0; i <= n; ++i) table[0][i] = 0;
	for (int i = 1; i <= n; ++i) table[1][i] = 1;
	for (int i = 0; i <= n; ++i) table[i][0] = 0;	
	
	for (int i = 2; i <= n; ++i) // length.
	    for (int j = 1; j <= n; ++j) { // end point.
		table[i][j] = 0;
		for (int k = 1; k < j; ++k){
		    if (sign[k] < sign[j]) {
			table[i][j] += table[i-1][k];
			table[i][j] %= 1000000007;
		    }
		}
	    }

//for i = 0 to n-1
//  print A[i mod m]
//    A[i mod m] = (X * A[i mod m] + Y * (i + 1)) mod Z
    
	ll cnt = 0;
	for (int i = 1; i <= n; ++i)
	    for (int j = 1; j <= n; ++j){
		cnt += table[i][j];
		cnt %= 1000000007;
	    }

	printf("Case #%d: %lld\n", cas, cnt);
    }

    return 0;
}
