#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 128;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
struct MAP{
	int pos;
	int list_id;
	int height;
	char ans;
}map[MAXN][MAXN];

struct Q{
	int x, y, h;
}q[MAXN*MAXN];

vector<int> list[30];
int row, col, n, visit[MAXN*MAXN], done[MAXN];

bool cmp(Q a, Q b){
	return a.h < b.h;
}

bool in(int x, int y){
	if(x < 0 || x >= row || y < 0 || y >= col) return 0;
	return 1;
}

bool judge(int x, int y, int px, int py){
	if(!in(px, py)) return false;
	int min_h = 2000000;
	for(int d = 0; d < 4; d++){
		int nx = px + dx[d];
		int ny = py + dy[d];
		if(!in(nx, ny)) continue;
		if(min_h > map[nx][ny].height) min_h = map[nx][ny].height;
	}
	if(min_h >= map[px][py].height) return false;
	for(int d = 0; d < 4; d++){
		int nx = px + dx[d];
		int ny = py + dy[d];
		if(!in(nx, ny)) continue;
		if(min_h == map[nx][ny].height){
			if(nx == x && ny == y) return true;
			return false;
		}
	}
	return false;
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int casenum, x, y, nx, ny, tail, head;
	scanf("%d",&casenum);
	for(int ca = 1; ca <= casenum; ca++){
		for(int i = 0; i < 30; i++) list[i].clear();
		memset(map, 0, sizeof(map));
		memset(q, 0, sizeof(q));
		memset(visit, 0, sizeof(visit));
		memset(done, 0, sizeof(done));
		scanf("%d %d", &row, &col);
		n = 0;
		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++){
				scanf("%d", &map[i][j].height);
				q[n].x = i;
				q[n].y = j;
				q[n++].h = map[i][j].height;
			}
		sort(q, q+n, cmp);
		for(int i = 0; i < n; i++){
			x = q[i].x;
			y = q[i].y;
			map[x][y].pos = i;
		}
		int list_tp = -1;
		for(int i = 0; i < n; i++){
			if(visit[i] == 0){
				++list_tp;
				list[list_tp].push_back(i);
				tail = 1;
				head = 0;
				visit[i] = 1;
				while( head < tail ){
					int p = list[list_tp][head];
					x = q[p].x;
					y = q[p].y;
					map[x][y].list_id = list_tp;
					for(int d = 0; d < 4; d++){
						nx = x + dx[d];
						ny = y + dy[d];
						if(judge(x, y, nx, ny)){

							p = map[nx][ny].pos;
							if(visit[p]) continue;
							list[list_tp].push_back(p);
							visit[p] = 1;
							tail++;
						}
					}
					head++;
				}
			}

		}
		char ch = 'a' - 1;
		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++){
				if(done[map[i][j].list_id] == 0){
					done[map[i][j].list_id] = 1;
					++ch;
					int id = map[i][j].list_id;
					for(int k = 0; k < list[id].size(); k++){
						x = q[list[id][k]].x;
						y = q[list[id][k]].y;
						map[x][y].ans = ch;
					}
				}
			}
		printf("Case #%d:\n", ca);
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(j) printf(" ");
				printf("%c", map[i][j].ans);		
			}
			puts("");
		}
	}	
	return 0;
}
