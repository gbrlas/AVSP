#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<list>
using namespace std;
#define clr(u) memset(u, 0, sizeof u)
FILE* in; FILE* out;
int t;
int h, w;
int map[101][101];
int now;
int tnow;
int res[101][101];
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
void dfs(int i, int j) {
	if(res[i][j] != 0) {
		tnow = res[i][j];
		return;
	}
	int chx = -1, chy = -1;
	for(int k = 0; k < 4; k++) {
		int ii = i + dir[k][0], jj = j + dir[k][1];
		if(ii < 0 || ii >= h || jj < 0 || jj >= w)
			continue;
		if(chx == -1 && map[ii][jj] < map[i][j]) {
			chx = ii;
			chy = jj;
		} else if(chx != -1 && map[chx][chy] > map[ii][jj]) {
			chx = ii;
			chy = jj;
		}
	}
	if(chx == -1) {
		tnow = now;
		now++;
	} else if(res[chx][chy] == 0)
		dfs(chx, chy);
	else if(res[chx][chy] != 0)
		tnow = res[chx][chy];
	res[i][j] = tnow;
}
void solve(int k) {
	fscanf(in, "%d%d", &h, &w);
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++) 
			fscanf(in, "%d", &map[i][j]);
	now = 'a';
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++) {
			if(res[i][j] == 0)
				dfs(i, j);
		}
	fprintf(out, "Case #%d:\n", k);
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++)
			fprintf(out, "%c ", (char)res[i][j]);
		fprintf(out, "\n");
	}
}
int main() {
	in = fopen("B-large.in", "r");
	out = fopen("B-large.out", "w");
	fscanf(in, "%d", &t);
	for(int k = 1; k <= t; k++) {
		clr(map);
		clr(res);
		solve(k);
	}
}