#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int get(int h, int m) {
	return 60*h + m;
}

void solve(int tcase ) {
	int ttime;
	int na, nb;
	int sA[25*60], sB[25*60];
	memset(sA, 0, sizeof(sA));
	memset(sB, 0, sizeof(sB));
	int cntA, cntB, solA = 0, solB=0;
	cntA=cntB=0;
	scanf("%d", &ttime);
	scanf("%d%d", &na, &nb);
	for(int i=0; i<na; i++) {
		int a, b, c,d;
		scanf("%d:%d %d:%d", &a, &b, &c, &d);
		a = get(a, b);
		c = get(c, d);
		c += ttime;
		sA[a]--;
		sB[c]++;
	}
	for(int i=0; i<nb; i++) {
		int a, b, c,d;
		scanf("%d:%d %d:%d", &a, &b, &c, &d);
		a = get(a, b);
		c = get(c, d);
		c += ttime;
		sB[a]--;
		sA[c]++;
	}
	for(int i=0; i<25*60; i++) {
		cntA += sA[i];
		cntB += sB[i];
		while(cntA < 0) cntA++, solA++;
		while(cntB < 0) cntB++, solB++;
	}
	printf("Case #%d: %d %d\n", tcase, solA, solB);
}

int main() {
	int t, c;
	scanf("%d", &t);
	c=0;
	while(t--) {
		solve(++c);
	}
}
