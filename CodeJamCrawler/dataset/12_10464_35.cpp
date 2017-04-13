#include <stdio.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
int n, in[10050][2], d;

struct xds {
	int l, r, n;
}s[40050];


void init(int x, int a, int b) {
	s[x].l = a;
	s[x].r = b;
	s[x].n = 0;
	if(a == b) return;
	int mid = (a + b) / 2;
	init(2 * x, a, mid);
	init(2 * x + 1, mid + 1, b);
}

void insert(int x, int i, int n) {
	//printf("insert %d %d %d %d\n", x, i, s[x].l, s[x].r);
	if(s[x].n < n) s[x].n = n;
	if(i == s[x].l && i == s[x].r) return;
	int mid = (s[x].l + s[x].r) / 2;
	if(i <= mid) {
		insert(2 * x, i, n);
	} else {
		insert(2 * x + 1, i, n);
	}
}

int qu(int x, int n) {
	if(s[x].n < n) return -1;
	if(s[x].l == s[x].r) return s[x].l;
	if(s[2 * x].n >= n) return qu(2 * x, n);
	return qu(2 * x + 1, n);
}

int solve() {
	if(in[0][0] * 2 >= d) return 1;
	init(1, 0, n);
	insert(1, 0, in[0][0] * 2);
	REP(i, 1, n) {
		int x = qu(1, in[i][0]);
		if(x == -1) continue;
		int y = MIN(in[i][0] - in[x][0], in[i][1]);
		//printf("%d %d\n", i, in[i][0] + y);
		if(in[i][0] + y >= d) return 1;
		insert(1, i, in[i][0] + y);
	}
	return 0;
}


int main()
{
//	freopen("A.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d %d", in[i], in[i] + 1);
		scanf("%d", &d);
		int ret = solve();
		printf("Case #%d: %s\n",case_id, ret ? "YES" : "NO");
	}
	return 0;
}
/*
99
3
3 4
4 10
6 10
9
3
3 4
4 10
7 10
9
2
6 6
10 3
13
2
6 6
10 3
14
*/
