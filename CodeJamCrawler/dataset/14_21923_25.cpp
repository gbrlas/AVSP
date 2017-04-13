#include <cstdio>
#include <set>

using namespace std;

const int N = 4;

int mat[N][N];

int main() {
	int cas; scanf("%d", &cas);
	for (int ca = 1; ca <= cas; ca++) {
		int r; scanf("%d", &r);
		bool vis[N*N + 10] = {0};
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		for (int i = 0; i < N; i++) vis[mat[r - 1][i]] = true;
		scanf("%d", &r);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		int ans = -1, cnt = 0;
		for (int i = 0; i < N; i++) {
			if (vis[mat[r - 1][i]]) {
				ans = mat[r - 1][i];
				cnt++;
			}
		}
		printf("Case #%d: ", ca);
		if (cnt == 1) {
			printf("%d\n", ans);
		} else if (cnt == 0) {
			printf("Volunteer cheated!\n");
		} else {
			printf("Bad magician!\n");
		}
	}
	return 0;
}
