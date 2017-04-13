#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int CENTER = 105;
const int MAXN = CENTER * 2;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

int MOVE[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};

bool hSeg[MAXN][MAXN], vSeg[MAXN][MAXN];

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		memset(hSeg, false, sizeof(hSeg));
		memset(vSeg, false, sizeof(vSeg));
		int n;
		int x, y;
		x = y = CENTER;
		int dire = NORTH;
		char str[32];
		int t;
		for (scanf("%d", &n); n > 0; n--) {
			scanf("%s%d", str, &t);
			while (t-- > 0) {
				for (int i = 0; str[i] != '\0'; i++) {
					switch (str[i]) {
						case 'R': 
							dire = (dire + 1) % 4;
							break;
						case 'L':
							dire = (dire + 3) % 4;
							break;
						case 'F':
							int nx = x + MOVE[dire][0];
							int ny = y + MOVE[dire][1];
							if (dire & 1) {
								hSeg[min(x, nx)][min(y, ny)] = true;
							} else {
								vSeg[min(x, nx)][min(y, ny)] = true;
							}
							//((dire & 1) ? hSeg : vSeg)[min(x, nx)][min(y, ny)] = true;
							//printf("%d: %d %d: %d %d\n", dire & 1, min(x, nx), min(y, ny), hSeg[min(x, nx)][min(y, ny)], vSeg[min(x, nx)][min(y, ny)]);
							x = nx;
							y = ny;
							break;
					}
				}
			}
		}
		//printf("%d\n", vSeg[105][105]);
		int ans = 0;
		for (x = 0; x < MAXN; x++) {
			for (y = 0; y < MAXN; y++) {
				int lCnt = 0;
				for (int nx = x; nx >= 0; nx--) {
					if (vSeg[nx][y]) {
						lCnt++;
					}
				}
				if ((lCnt & 1) == 0) {
					bool right, up, down;
					right = up = down = false;
					for (int nx = x + 1; nx < MAXN; nx++) {
						if (vSeg[nx][y]) {
							right = true;
							break;
						}
					}
					for (int ny = y; ny >= 0; ny--) {
						if (hSeg[x][ny]) {
							down = true;
							break;
						}
					}
					for (int ny = y + 1; ny < MAXN; ny++) {
						if (hSeg[x][ny]) {
							up = true;
							break;
						}
					}
					if ((lCnt && right) || (up && down)) {
						//printf("%d %d: %d %d %d %d\n", x, y, lCnt, right, up, down);
						ans++;
					}
				}
			}
		}

		printf("Case #%d: %d\n", caseIndex, ans);
	}

	return 0;
}
