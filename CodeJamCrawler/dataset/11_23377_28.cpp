#include<stdio.h>
#include<string.h>

int R, C;
char str[55][55];


int chk(int i, int j)
{
	return (str[i][j] == '#' && str[i][j+1]=='#' && str[i+1][j]=='#' && str[i+1][j+1]=='#');
}

int solve()
{
	int i, j;
	for(i=0; i<R-1; i++){
		for(j=0; j<C-1; j++){
			if( chk(i, j) )
			{
				str[i][j] = '/';
				str[i][j+1] = '\\';
				str[i+1][j] = '\\';
				str[i+1][j+1] = '/';
			}
		}
	}
	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
			if(str[i][j] == '#')return 0;
	return 1;
}

void output()
{
	int i;
	for(i=0; i<R; i++)
		puts(str[i]);
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int cs, t;
	int r;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++)
	{
		scanf("%d%d", &R, &C);
		for(r=0; r<R; r++)
			scanf("%s", str[r]);

		printf("Case #%d:\n", cs);

		if( solve() )
			output();
		else
			puts("Impossible");
			
	}
	return 0;
}