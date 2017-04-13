#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>

using namespace std;

#define DMAX 105

int T, H, W;
int in[DMAX][DMAX];
char out[DMAX][DMAX], c = 'a';

int d[5][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {0, 0}};

bool valid(int i, int j, int k = 4) {
	if (i+d[k][0]>=0 && i+d[k][0]<H && j+d[k][1]>=0 && j+d[k][1]<W) return true;
	else return false;
}

int lowest(int i, int j) {
	int ret = in[i][j];
	for (int k=0; k<4; k++) {
		if (valid(i, j, k) && in[i][j]>in[i+d[k][0]][j+d[k][1]]) {
			ret = min(ret, in[i+d[k][0]][j+d[k][1]]);
		}
	}
	return ret;
}

char dfs(int i, int j) {
	int low = lowest(i, j);
	if (out[i][j]>='a') {
		// This node already goes to the sink so we will just use this, so we don't have to go deeper.
		return out[i][j];
	} else if (low == in[i][j]) {
		// This node is a sink.
		out[i][j] = c;
		c++;
		return out[i][j];
	} else {
		for (int k=0; k<4; k++) {
			if (valid(i, j, k) && in[i+d[k][0]][j+d[k][1]] == low) {
				out[i][j] = dfs(i+d[k][0], j+d[k][1]);
				return out[i][j];
			}
		}
	}
	return out[i][j];
}

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d", &T);
	for (int k=0; k<T; k++) {
		scanf("%d%d", &H, &W);
		for (int i=0; i<H; i++) {
			for (int j=0; j<W; j++) {
				scanf("%d", &in[i][j]);
			}
		}
		memset(out, 0, sizeof(out));
		c = 'a';
		for (int i=0; i<H; i++) {
			for (int j=0; j<W; j++) {
				if (out[i][j]<'a') {
					out[i][j] = dfs(i, j);
				}
			}
		}
		printf("Case #%d:\n", k+1);
		for (int i=0; i<H; i++) {
			printf("%c", out[i][0]);
			for (int j=1; j<W; j++) {
				printf(" %c", out[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

