#include <stdio.h>
#include <string.h>

int counts[33];
char board[32][32];

int main()
{
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; c++)
	{
		int m,n;
		scanf("%d %d", &m, &n);
		for (int i=0; i<m; i++)
		{
			char buf[129];
			
			scanf("%s", buf);
			for (int j=0; j<n; j += 4)
			{
				int v;
				if (buf[j/4] < 'A')
					v = buf[j/4] - '0';
				else
					v = buf[j/4] - 'A' + 10;
				board[i][j+0] = (v>>3)&1;
				board[i][j+1] = (v>>2)&1;
				board[i][j+2] = (v>>1)&1;
				board[i][j+3] = (v>>0)&1;
			}
		}

		memset(counts, 0, sizeof(counts));
		for (int s = m; s >= 1; s--)
			for (int r=0; r+s <= m; r++)
				for (int c=0; c+s <= n; c++)
				{
					int v = board[r][c];
					if (v == 2)
						continue;
					for (int a=0; a<s; a++)
						for (int b=0; b<s; b++)
							if (board[r+a][c+b] == 2 || board[r+a][c+b] != v^((a+b)&1))
								goto nope;
					for (int a=0; a<s; a++)
						for (int b=0; b<s; b++)
							board[r+a][c+b] = 2;
					counts[s]++;

nope:;
				}

		int nzero = 0;
		for (int i=1; i<=32; i++)
			if (counts[i] > 0)
				nzero++;
		printf("Case #%d: %d\n", c, nzero);
		for (int i=32; i>=1; i--)
			if (counts[i] > 0)
				printf("%d %d\n", i, counts[i]);
	}
}
