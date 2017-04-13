#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int mod = 10007;

#define FU(i,a,b) for(i = a; i < b; i++)
#define FD(i,a,b) for(i = a; i > b; i--)
#define FE(i,a) for(i = a.begin(); i != a.end(); i++)
#define PB(a,b) a.push_back(b)
#define SZ(a) (int)a.size()

typedef long long LL;
typedef vector<int> VI;

int bad[1000][1000];
int n, m, a[1000][1000];


int main(void) {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, j, k, t, c;

	scanf("%d", &t);
	FU(c, 1, t+1) {
		scanf("%d%d%d", &n, &m, &k);
		while(k--) {
			scanf("%d%d", &i, &j);
			bad[i-1][j-1] = c;
		}

		FU(i, 0, n) FU(j, 0, m) a[i][j] = 0;
		a[0][0] = 1;

		FU(i, 0, n) FU(j, 0, m) {
			if(bad[i+2][j+1] != c) a[i+2][j+1] = (a[i+2][j+1]+a[i][j])%mod;
			if(bad[i+1][j+2] != c) a[i+1][j+2] = (a[i+1][j+2]+a[i][j])%mod;
		}

		printf("Case #%d: %d\n", c, a[n-1][m-1]);
	}

	exit(0);
}