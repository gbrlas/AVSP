#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cassert>

typedef long long int64;
typedef double real;

const int inf = 0x3f3f3f3f;

#define Eo(x) { std::cerr << #x << " = " << x << std::endl; }

using namespace std;
#define maxn (1 << 7)


int di[4] = {-1, 0, 0, 1};
int dj[4] = {0, -1, 1, 0};

int who[maxn][maxn];
int h[maxn][maxn];
char ans[maxn][maxn];
int n, m;

inline bool onbrd(int i, int j){
	return i >= 0 && i < n && j >= 0 && j < m;
}

char c;

void dfs(int i, int j){
	if (ans[i][j] != 0) return;
	ans[i][j] = c;
	for (int d = 0; d < 4; d++){
		int ni = i + di[d];
		int nj = j + dj[d];
		if (onbrd(ni, nj) && (who[i][j] == d || (who[ni][nj] != -1 && ni + di[who[ni][nj]] == i && nj + dj[who[ni][nj]] == j))) dfs(ni, nj); 
	}
}
int main(){
	int ferlon;
	scanf("%d", &ferlon);
	for (int _ = 0; _ < ferlon; ++_){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &h[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				who[i][j] = -1;
				int lh = h[i][j];
				for (int d = 0; d < 4; d++)
					if (onbrd(i + di[d], j + dj[d]) && h[i + di[d]][j + dj[d]] < lh){
						lh = h[i + di[d]][j + dj[d]];
						who[i][j] = d;
					}
			}
		printf("Case #%d:\n", _ + 1);
		memset(ans, 0, sizeof(ans));
		c = 'a';
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) if (ans[i][j] == 0){
				dfs(i, j);
				++c;
			}

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				printf("%c ", ans[i][j]);
			}
			puts("");
		}
	}

	return 0;
}
