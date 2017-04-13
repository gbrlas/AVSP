#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
typedef int (*CMP)(const void *, const void *);

int n, w, l, in[2000], s[2000];
double ans[2000][2];

int cmp(int *a, int *b) {
	return in[*b]-in[*a];
}

int myrand(int x) {
	unsigned int ret = ((rand() << 16) | rand());
	return ret % x;
}

void set(int x, double a, double b) {
	//if(x >=2 )printf("%d %lf %lf\n", x, a, b);
	ans[s[x]][0] = a;
	ans[s[x]][1] = b;
}

void init() {
	REP(i, 0, n) set(i, -1, -1);
}

int isOK(int x, int y) {
	double a = ans[x][0] - ans[y][0];
	double b = ans[x][1] - ans[y][1];
	double c = a * a + b * b;
	double d = in[x] + in[y];
	return c > d * d ? 1 : 0;
}

int checkall() {
	REP(i, 0, n) {
		if(ans[i][0] < 0) continue;
		REP(j, i + 1, n) {
			if(ans[j][0] < 0) continue;
			if(!isOK(i, j)) return 0;
		}
	}
	return 1;
}


int check(int x) {
	REP(i, 0, n) {
		if(ans[i][0] < 0) continue;
		if(i == s[x]) continue;
		if(!isOK(i, s[x])) return 0;
	}
	return 1;
}

int solve() {
	init();
	qsort(s, n, sizeof(s[0]), (CMP)cmp);
	set(0, 0, 0);
	set(1, w, l);
	//if(!checkall()) return 0;
	REP(i, 2, n) {
		int flag = 0;
		REP(j, 0, 100) {
			set(i, myrand(w + 1), myrand(l + 1));
			if(check(i)) {
				flag = 1;
				break;
			}
		}
		if(flag == 0) return 0;
	}
	return 1;
	
}

int main()
{
//	freopen("A.in","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int testcase;
	srand(time(0));
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		scanf("%d%d%d",&n, &w, &l);
		for (int i=0;i<n;i++) {
			scanf("%d", in + i);
			s[i] = i;
		}
		
		int ret = 0;
		while(1) {
			ret = solve();
			if(ret == 1) break;
		}
		printf("Case #%d: ",case_id);
		REP(i, 0, n) {
			printf("%lf %lf", ans[i][0], ans[i][1]);
			if(i == n - 1) puts("");
			else printf(" ");
		}
	}
	return 0;
}
