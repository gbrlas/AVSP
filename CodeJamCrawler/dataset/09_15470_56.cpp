#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

struct node{
	double wt;
	char des[20];
	int ch[2];
};

node d[300];
char ln[110][100];
char feature[110][20];
int n, m, cnt = 0;

inline void build(int &r, int &c, int cur) {
	while((ln[r][c] < 'a' || ln[r][c] > 'z') && ln[r][c] != '(' && ln[r][c] != ')') {
		if(ln[r][c] == '\0')	r ++, c = 0;
		else					c ++;
	}
	//if(ln[r][c] == ')') return 0;
	d[cur].des[0] = '\0';
	if(ln[r][c] >= 'a' && ln[r][c] <= 'z') {
		sscanf(ln[r] + c, "%s", d[cur].des);
	}
	while(ln[r][c] != '(') {
		if(ln[r][c] == '\0')	r ++, c = 0;
		else					c ++;
	}
	if(ln[r][c] == '(') {
		c ++;
		sscanf(ln[r] + c, "%lf", &d[cur].wt);
		while((ln[r][c] >= '0' && ln[r][c] <= '9') || ln[r][c] == '.' || ln[r][c] == ' ') {
			if(ln[r][c] == '\0')	r ++, c = 0;
			else					c++;
		}
	}
	d[cur].ch[0] = -1;
	d[cur].ch[1] = -1;
	int ct = 0;
	while(ln[r][c] != ')') {
		if((ln[r][c] >= 'a' && ln[r][c] <= 'z') || ln[r][c] == '(') {
			d[cur].ch[ct] = cnt ++;
			build(r, c, d[cur].ch[ct]);
			ct ++;
		}
		if(ln[r][c] == '\0')	r ++, c = 0;
		else					c ++;
	}
	if(ln[r][c] == ')')
		return ;
}

inline double workItOut() {
	double ret = 1.0;
	int cur = 0, i, j;
	bool fg;
	while(1) {
		ret *= d[cur].wt;
		if(d[cur].ch[0] == -1) break;
		fg = 0;
		for(i = 0; i < n; i++) {
			if(strcmp(feature[i], d[d[cur].ch[0]].des) == 0) {
				fg = 1;
				break;
			}
		}
		if(fg)
			cur = d[cur].ch[0];
		else
			cur = d[cur].ch[1];
	}
	return ret;
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int ncs = 1; ncs <= t; ncs ++) {
		scanf("%d", &n);
		getchar();
		int i, j;
		double ret;
		for(i = 0; i < n; i++) {
			gets(ln[i]);
		}
		cnt = 1;
		int r = 0, c = 0;
		build(r, c, 0);
		printf("Case #%d:\n", ncs);
		scanf("%d", &m);
		for(i = 0; i < m; i++) {
			scanf("%s", ln[0]);
			scanf("%d", &n);
			for(j = 0; j < n; j++) {
				scanf("%s", feature[j]);
			}
			ret = workItOut();
			printf("%.7lf\n", ret);
		}
	}
	return 0;
}
