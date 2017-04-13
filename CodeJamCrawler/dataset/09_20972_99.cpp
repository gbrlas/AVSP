#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 100;

const int MOVES[4][2] = {
	{-1, 0},
	{0, -1},
	{0, 1},
	{1, 0}
};

typedef pair<int, int> PII;

int si, sj;
int heights[MAXN][MAXN];
char ans[MAXN][MAXN];
char nextAns;

char getAns(int i, int j) {
	if (ans[i][j] != -1) {
		return ans[i][j];
	} else {
		int d = -1;
		int least = heights[i][j];
		for (int k = 0; k < 4; k++) {
			int ni = i + MOVES[k][0];
			int nj = j + MOVES[k][1];
			if (0 <= ni && ni < si && 0 <= nj && nj < sj) {
				if (heights[ni][nj] < least) {
					least = heights[ni][nj];
					d = k;
				}
			}
		}
		if (d == -1) {
			return ans[i][j] = nextAns++;
		} else {
			return ans[i][j] = getAns(i + MOVES[d][0], j + MOVES[d][1]);
		}
	}
}

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		scanf("%d%d", &si, &sj);
		for (int i = 0; i < si; i++) {
			memset(ans[i], (char) -1, sizeof(char) * sj);
			for (int j = 0; j < sj; j++) {
				scanf("%d", &heights[i][j]);
			}
		}
		nextAns = 'a';
		printf("Case #%d:\n", caseIndex);
		for (int i = 0; i < si; i++) {
			for (int j = 0; j < sj; j++) {
				if (j > 0) {
					putchar(' ');
				}
				putchar(getAns(i, j));
			}
			putchar('\n');
		}
	}
	
	return 0;
}
