#include <stdio.h>
#include <queue>
using namespace std;

int graph[100][100];
int nbrs[100][100][2];
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};
int sinks[100][2];
int fixed_graph[100][100];
char res[100][100];

int main()
{
	FILE* fin = fopen("in.txt", "r");
	FILE* fout = fopen("out.txt", "w");

	int T;
	fscanf(fin, "%d", &T);
	for(int test = 1; test <= T; ++test)
	{
		int H, W;
		fscanf(fin, "%d %d", &H, &W);
		for(int i = 0; i < H; ++i)
			for(int j = 0; j < W; ++j)
				fscanf(fin, "%d", &graph[i][j]);
		int sink_count = 0;
		for(int r = 0; r < H; ++r)
			for(int c = 0; c < W; ++c)
			{
				int nbr = -1, nbc = -1;
				int hi = graph[r][c];
				for(int k = 0; k < 4; ++k)
				{
					int nr = r + dr[k], nc = c + dc[k];
					if(nr < 0 || nr >= H || nc < 0 || nc >= W)
						continue;
					if(graph[nr][nc] < hi)
					{
						hi = graph[nr][nc];
						nbr = nr, nbc = nc;
					}
				}
				if(nbr == -1)
				{
					sinks[sink_count][0] = r;
					sinks[sink_count++][1] = c;
					nbrs[r][c][0] = r;
					nbrs[r][c][1] = c;
				}
				else
				{
					nbrs[r][c][0] = nbr;
					nbrs[r][c][1] = nbc;
				}
			}

		memset(fixed_graph, -1, sizeof(fixed_graph));
		for(int i = 0; i < sink_count; ++i)
		{
			queue< pair<int, int> > q;
			q.push(make_pair(sinks[i][0], sinks[i][1]));
			fixed_graph[sinks[i][0]][sinks[i][1]] = i;
			while(!q.empty())
			{
				pair<int, int> p = q.front();
				q.pop();
				int rcur = p.first, ccur = p.second;
				for(int j = 0; j < 4; ++j)
				{
					int nr = rcur + dr[j], nc = ccur + dc[j];
					if(nr < 0 || nr >= H || nc < 0 || nc >= W)
						continue;
					if(nbrs[nr][nc][0] == rcur && nbrs[nr][nc][1] == ccur)
					{
						fixed_graph[nr][nc] = i;
						q.push(make_pair(nr, nc));
					}
				}
			}
		}
		for(int r = 0; r < H; ++r)
			for(int c = 0; c < W; ++c)
				res[r][c] = 'a' - 1;
		int found = 0;
		for(int r = 0; r < H; ++r)
		{
			for(int c = 0; c < W; ++c)
			{
				if(res[r][c] != 'a' - 1) continue;
				char rep = found + 'a';
				++found;
				int v = fixed_graph[r][c];
				for(int tr = 0; tr < H; ++tr)
					for(int tc = 0; tc < W; ++tc)
						if(fixed_graph[tr][tc] == v)
							res[tr][tc] = rep;
			}
		}
		fprintf(fout, "Case #%d:\n", test);
		for(int r = 0; r < H; ++r)
		{
			for(int c = 0; c < W; ++c)
				fprintf(fout, "%c ", res[r][c]);
			fprintf(fout, "\n");
		}
	}

	return 0;
}
