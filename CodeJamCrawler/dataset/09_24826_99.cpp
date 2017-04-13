// gcj qual b

#include <memory.h>
#include <stdio.h>

int n, m;
int h[101][101];
char ret[101][101];

int getVertex(int x, int y) { return ( x - 1 ) * m + y;}
int V;
int uf[10101];

int uf_find(int x) { 
	if(x == uf[x]) return x;
	else return uf[x] = uf_find(uf[x]);
}
void uf_merge(int x, int y)
{
	x = uf_find(x); y = uf_find(y);
	uf[x] = y;
}

void go()
{
	V = n * m;
	for(int i=1;i<=V; ++i) uf[i] = i;

	const static int dx[4] = {-1, 0, 0, 1};
	const static int dy[4] = {0, -1, 1, 0};

	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
	{
		int tok = -1;
		int lowest = 987654321;

		for(int k=0; k<4; ++k)
		{
			int ii = i + dx[k], jj = j + dy[k];
			if(ii < 1 || jj < 1 || ii > n || jj > m) continue;
			if(h[i][j] > h[ii][jj]); else continue;

			if(lowest > h[ii][jj])
			{
				lowest = h[ii][jj];
				tok = k;
			}
		}

		if(tok == -1) continue;
		int ii = i + dx[tok], jj = j + dy[tok];
		uf_merge( getVertex(i, j), getVertex(ii, jj) );
	}
	
	char label = 'a' - 1;
	memset(ret, 0, sizeof(ret));
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
	{
		if(ret[i][j] == 0)
		{
			ret[i][j] = ++ label;
			int base = uf_find( getVertex(i, j) );

			for(int x=1; x<=n; ++x) for(int y=1; y<=m; ++y)
				if(base == uf_find( getVertex(x, y) ))
					ret[x][y] = label;
		}
	}
}

int main()
{
	freopen("b-small.in","r",stdin);
	freopen("b-small.out","w",stdout);
	int T, t;
	scanf("%d", &T);
	for(t=1; t<=T; ++t) {
		scanf("%d %d",&n, &m);
		for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
		{
			scanf("%d", &h[i][j]);
		}
		go();
		printf("Case #%d:\n", t);
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=m; ++j)
				printf("%c ", ret[i][j]);
			putchar('\n');
		}
	}
	return 0;
}
