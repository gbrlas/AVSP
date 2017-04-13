#include <stdio.h>
#define MAXN 100
#define MAXGROUP 26
#define MAXVALUE 1000000000

using namespace std;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
int value[MAXN][MAXN], group[MAXN][MAXN];
int mindir[MAXN][MAXN];
int n, m;

void findMindir(int x, int y);
void DFS(int x, int y, int no);

int main()
{
	int ncase, T, i, j, N; 
	scanf("%d",&T);
	for(ncase = 0; ncase < T; ++ncase){
		scanf("%d%d", &m, &n);
		for(i=0; i<m; ++i){
			for(j=0; j<n; ++j){
				scanf("%d", &value[i][j]);
				group[i][j] = -1;
			}
		}
		for(i=0; i<m; ++i)
			for(j=0; j<n; ++j)
				findMindir(i, j);

		N = 0;
		for(i=0; i<m; ++i)
			for(j=0; j<n; ++j)
				if(group[i][j] == -1)
					DFS(i, j,  N++);

		printf("Case #%d:\n", ncase+1);
		for(i=0; i<m; ++i){
			for(j=0; j<n-1; ++j)
				printf("%c ", group[i][j] + 'a');
			printf("%c\n", group[i][n-1] + 'a');
		}
	}
	return 0;
}

inline bool inside(int x, int y){
	return (0<=x && x<m && 0<=y && y<n);
}

void findMindir(int x, int y){
	int nx, ny, min;
	mindir[x][y] = -1; 
	min = value[x][y]; 
	for(int i=0; i<4; ++i){
		nx = x + dx[i];
		ny = y + dy[i];
		if(inside(nx, ny) && value[nx][ny] < min){
			min = value[nx][ny];
			mindir[x][y] = i;
		}
	}
}

void DFS(int x, int y, int no){
	int nx, ny;
	group[x][y] = no;
	for(int i=0; i<4; ++i){
		nx = x + dx[i];
		ny = y + dy[i];
		if(inside(nx, ny) && group[nx][ny] == -1 && (mindir[x][y] == i || mindir[nx][ny] == 3-i)){
			DFS(nx, ny, no);
		}
	}
}
