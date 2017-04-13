#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	int t;
	ll n;
	int d[22];
	char ln[22];
	scanf("%d", &t);
	getchar();
	for(int ncs = 1; ncs <= t; ncs ++) {
		gets(ln);
		int ct = strlen(ln), i, j;
		int mi, np, cur;
		bool fg = 0;

		for(i = 0; i < ct; i++) {
			d[i] = ln[ct - i - 1] - '0';
		}

		for(i = 0; i < ct; i++) {
			mi = 11, np = -1;
			for(j = 0; j < i; j++) {
				if(d[j] > d[i] && d[j] < mi) {
					mi = d[j];
					np = j;
				}
			}
			if(np == -1) continue;
			else {
				fg = 1;
				cur = i;
				break;
			}
		}
		printf("Case #%d: ", ncs);
		if(fg) {
			for(i = ct - 1; i > cur; i--) {
				printf("%d", d[i]);
			}
			int tmp = d[np];
			printf("%d", d[np]);
			sort(d, d + cur + 1);
			for(i = 0; i <= cur; i++) {
				if(d[i] == tmp) {
					tmp = -1;
					continue;
				}
				printf("%d", d[i]);
			}
			printf("\n");
		}
		else {
			for(i = ct -1; i >= 0; i--) {
				if(!d[i]) break;
			}
			sort(d + i + 1, d + ct);
			printf("%d0", d[i + 1]);
			for(j = 0; j <= i; j++) {
				printf("0");
			}
			for(j = i + 2; j < ct; j++) {
				printf("%d", d[j]);
			}
			printf("\n");
		}
	}

	return 0;
}