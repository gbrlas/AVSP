#include <stdio.h>
#include <string.h>

#define NMAX 110
#define INFI 0x3f3f3f3f

int a[NMAX][NMAX];
int lab[NMAX][NMAX];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int n, m;
int counter;

char toChar(int x)
{
	return (char)x+'a';
}

int down(int i, int j)
{
	if(lab[i][j] != -1)
		return lab[i][j];

	int k, min = a[i][j], poz = 0, nr = 0, val;
	for(k = 0; k < 4; ++k)
	{
		val = a[ i+dx[k] ][ j+dy[k] ];
		if(val == -1)
			continue;
	
		if(val < min)
			min = val, poz = k;
	}

	if(min == a[i][j])
	{
		lab[i][j] = counter++;
	}
	else
		lab[i][j] = down(i+dx[poz], j+dy[poz]);
		
	return lab[i][j];
		
}			
	


int main()
{
	freopen("w.in", "r", stdin);
	freopen("w.out", "w", stdout);

	int i, z, t, j;

	scanf("%d", &t);
	for(z = 1; z <= t; ++z)
	{
		for(i = 0; i < NMAX; ++i)
			for(j = 0; j < NMAX; ++j)
			{
				a[i][j] = 0;
				lab[i][j] = -1;
			}
		scanf("%d %d", &n, &m);
		for(i = 0; i <= n+1; ++i)
			a[i][0] = a[i][m+1] = -1;
		for(i = 0; i <= m+1; ++i)
			a[0][i] = a[n+1][i] = -1; 		

                for(i = 1; i <= n; ++i)
                {
                        for(j = 1; j <= m; ++j)
                                scanf("%d", &a[i][j]);
                }


		/*for(i = 0; i <= n+1; ++i)
		{
			for(j = 0; j <= m+1; ++j)
				printf("%d ", a[i][j]);
			printf("\n");
		}
		*/
		counter = 0;
		for(i = 1; i <= n; ++i)
			for(j = 1; j <= m; ++j)
				if(lab[i][j] == -1)
					lab[i][j] = down(i, j);

	
		printf("Case #%d:\n", z);
		for(i = 1; i <= n; ++i)
		{
			for(j = 1; j <= m; ++j)
				printf("%c ", toChar(lab[i][j]));
			printf("\n");
		} 			
	}
return 0;
}


