#include <stdio.h>
#include <memory.h>

char word[5005][20];

int len, d;
bool vis[20][30];

void read( int i )
{
	char c;
	while( true )
	{
		c = getchar();
		if( c == '(' || c>='a' &&c<='z' ) break;
	}
	if( c != '(' )
	{
		vis[i][ c-'a' ] = true;
		return;
	}
	while( true )
	{
		c = getchar();
		if( c == ')' ) break;
		vis[i][ c-'a' ] = true;
	}
}

int match()
{
	int i, j, sum = 0;
	for(i=0; i<d; ++i)
	{
		for(j=0; j<len; ++j)
		{
			if( !vis[j][ word[i][j]-'a' ] ) break;
		}
		if( j == len ) sum++;
	}
	return sum;
}

int main()
{
	int n, i, j;
	
	scanf("%d %d %d", &len, &d, &n);
	for(i=0; i<d; ++i) scanf("%s", word[i]);
	for(i=0; i<n; ++i)
	{
		//memset(tag, 0, sizeof(tag));
		memset(vis,0,sizeof(vis));
		for(j=0; j<len; ++j) read(j);
		printf("Case #%d: %d\n", i+1, match());
	}
	return 0;
}
 

