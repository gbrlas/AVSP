#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)
#define FORD(i,a,b) for(int i=a,_b=b;i>=b;i--)
#define REPD(i,a) FORD(i,a-1,0)
#define ALL(x) (x).begin(),(x).end()
#define _m(a,b) memset(a,b,sizeof(a))
#define LL long long
#define st first
#define nd second

typedef pair<int,int> PII;
typedef pair<int,string> PIS;

#define MAX 510

int R, C, D;
char M[MAX][MAX];

bool check(int r, int c, int z) {
	double xres = 0.0;
	double yres = 0.0;
	double xc = (double)z / 2.0;
	double yc = (double)z / 2.0;
	
	REP(i, z) REP(j, z) {
		if( (i==0 && j==0) || (i==0&&j==z-1) || (i==z-1&&j==0) || (i==z-1&&j==z-1) ) continue;
		
		if(z % 2) {
			xres += (i-(z/2)) * (M[i+r][j+c]-'0'+D);
			yres += (j-(z/2)) * (M[i+r][j+c]-'0'+D);
		} else {
			xres += (i-(z/2)+(i >= (z/2))) * (M[i+r][j+c]-'0'+D);
			yres += (j-(z/2)+(i >= (z/2))) * (M[i+r][j+c]-'0'+D);
		}
	}
	
	return (xres == 0.0 && yres == 0.0);
}

void run(int testcaseNumber) {
	int res = -1;
	scanf("%d %d %d", &R, &C, &D);
	REP(i, R) scanf("%s", M[i]);
	
	for(int z = min(R, C); z >= 3 && res == -1; z--) {
		for(int r=0; r+z <= R && res == -1; r++) {
			for(int c=0; c+z <= C && res == -1; c++) {
				if(check(r, c, z)) {
					res = z;
				}
			}
		}
	}
	
	if(res == -1)
		printf("Case #%d: IMPOSSIBLE\n", testcaseNumber);
	else
		printf("Case #%d: %d\n", testcaseNumber, res);
}

int main(void) {
	int T; scanf("%d", &T); REP(i, T) run(i + 1);
	return 0;
}
