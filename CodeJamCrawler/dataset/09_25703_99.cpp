#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 128;
const int INF = 1000000100;
const int dir[][2] = {{-1,0},{0,-1},{0,1},{1,0}};
int a[MAXN][MAXN], col[MAXN][MAXN];
int sink[MAXN*MAXN][2];
vector<pair<int,int> > mp[MAXN][MAXN];

#define IN(x,y) ((x)>=0&&(x)<H&&(y)>=0&&(y)<W)

int q[MAXN*MAXN][2];
void bfs(int sx, int sy, int c) {
	int qh, qt, i;
	q[0][0] = sx; q[0][1] = sy;
	col[sx][sy] = c;
	for (qh = 0, qt = 1 ; qh < qt ; ++qh) {
		for (i = 0 ; i < mp[q[qh][0]][q[qh][1]].size() ; i++) {
			int tx = mp[q[qh][0]][q[qh][1]][i].first;
			int ty = mp[q[qh][0]][q[qh][1]][i].second;
			if (col[tx][ty]) continue;
			col[tx][ty] = c;
			q[qt][0] = tx;
			q[qt++][1] = ty;
		}
	}
}

int main() {
	freopen("b-large.in","r",stdin);
	freopen("b-large.out","w",stdout);
	int T, ca, i, j, H, W, d, ti, tj;
	scanf("%d",&T);
	for (ca = 1 ; ca <= T ; ca++) {
		scanf("%d%d",&H,&W);
		for (i = 0 ; i < H ; i++)
			for (j = 0 ; j < W ; j++) {
				scanf("%d",&a[i][j]);
				mp[i][j].clear();
			}
		int ps = 0;
		for (i = 0 ; i < H ; i++)
			for (j = 0;  j < W ; j++) {
				int lowest = INF;
				int ld = -1, lx, ly;
				for (d = 0 ; d < 4 ; d++) {
					ti = i + dir[d][0];
					tj = j + dir[d][1];
					if (!IN(ti,tj)) continue;
					if (a[ti][tj] < a[i][j]) {
						if (a[ti][tj] < lowest) {
							lowest = a[ti][tj];
							ld = d;
							lx = ti;
							ly = tj;
						}
					}
				}
				if (ld == -1) {
					sink[ps][0] = i;
					sink[ps++][1] = j;
				} else {
					mp[lx][ly].push_back(make_pair(i,j));
				}
			}

		memset(col, 0, sizeof(col));
		for (i = 0 ; i < ps ; i++) {
			bfs(sink[i][0], sink[i][1], i+1);
		}
		int tk[32], cnt = 0;
		memset(tk, -1, sizeof(tk));
		printf("Case #%d:\n",ca);
		for (i = 0 ; i < H ; i++) {
			for (j = 0 ; j < W ; j++) {
				if (tk[col[i][j]] == -1) {
					tk[col[i][j]] = cnt++;
				}
				if (j) printf(" ");
				printf("%c",tk[col[i][j]]+'a');
			}
			printf("\n");
		}
	}
	return 0;
}
