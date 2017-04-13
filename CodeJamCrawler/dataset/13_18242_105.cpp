#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctype.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>

using namespace std;

typedef pair<int,int> ii;

#define INF 0x3f3f3f3f
#define ll long long
#define MAXN 22
#define MAXK 202

int n,ini[MAXK],key[MAXN][MAXK],type[MAXN],dp[1<<MAXN],choice[1<<MAXN];

int solve(int mask) {
	if (mask == (1<<n)-1) return 1;
	if (dp[mask] != -1) return dp[mask];
	
	int curr[MAXK];
	for (int i=0; i<MAXK; i++)
		curr[i] = ini[i];
	for (int i=0; i<n; i++)
		if (mask & (1<<i)) {
			for (int j=0; j<MAXK; j++)
				curr[j] += key[i][j];
			curr[type[i]]--;
		}
	
	for (int i=0; i<n; i++)
		if (!(mask & (1<<i)) && curr[type[i]]) {
			if (solve(mask|(1<<i))) {
				choice[mask] = i;
				return dp[mask] = 1;
			}
		}
	
	return dp[mask] = 0;
}

void rec(int mask) {
	if (mask == (1<<n)-1) {
		cout << endl;
		return;
	}
	if (mask) cout << " ";
	cout << choice[mask]+1;
	rec(mask|(1<<choice[mask]));
	return;
}

int main() {
	int nt,nteste=1,k,d;
	cin>>nt;
	while (nt--) {
		cin>>k>>n;
		memset(ini,0,sizeof(ini));
		memset(key,0,sizeof(key));
		while (k--) {
			cin>>d;
			ini[d]++;
		}
		
		for (int i=0; i<n; i++) {
			cin>>type[i]>>k;
			while (k--) {
				cin>>d;
				key[i][d]++;
			}
		}
		
		memset(dp,-1,sizeof(dp));
		int r = solve(0);
		cout << "Case #" << nteste++ << ": ";
		if (!r) cout << "IMPOSSIBLE" << endl;
		else rec(0);
	}
	
	return 0;
}
