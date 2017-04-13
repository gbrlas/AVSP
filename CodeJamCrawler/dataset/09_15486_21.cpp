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

#define sz 10

int m[sz][sz];
int ls[sz];

void swapRow(int x, int y, int n) {
	int tmp;
	for(int i = 0; i < n; i++) {
		tmp = m[x][i];
		m[x][i] = m[y][i];
		m[y][i] = tmp;
	}
	tmp = ls[x];
	ls[x] = ls[y];
	ls[y] = tmp;
}

void display(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d", m[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int ncs = 1; ncs <= t; ncs ++) {
		int n, i, j;
		scanf("%d", &n);
		memset(ls, 0, sizeof(ls));
		getchar();
		char x;
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				x = getchar();
				m[i][j] = x - '0';
				if(m[i][j]) 
					ls[i] = j;
			}
			x = getchar();
		}
		int ret = 0;
		int tmp;
		for(i = 0; i < n; i++) {
			if(ls[i] > i) {
				for(j = i + 1; j < n; j++) {
					if(ls[j] <= i) {
						tmp = j;
						break;
					}
				}
				for(j = tmp; j > i; j--) {
					swapRow(j, j - 1, n);
					ret ++;
				}			
				//printf("%d\n", ret);
				//display(n);
			}

			//for(j = 0; j + 1< n; j++) {
			//	if(ls[j] > j) {
			//		//printf("%d %d\n", ls[j], ls[j + 1]);
			//		swapRow(j, j + 1, n);
			//		ret ++;
			//	}
			//}

		}
		printf("Case #%d: ", ncs);
		printf("%d\n", ret);
	}
	return 0;
}