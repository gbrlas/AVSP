#include <iostream>
using namespace std;

char s[5500][20];

bool vis[1000][27];

void f(char *str)
{
	int ls = 0;
	memset(vis, 0, sizeof(vis));
	int i, j, k;
	for(i=0; str[i]; )
	{
		if( str[i] == '(' )
		{
			for(k=0, j=i+1; str[j] != ')'; j++, k++)
			{
				vis[ls][str[j] - 'a' ] = true;
			}
			i = j + 1;
		}
		else
		{
			vis[ls][str[i] - 'a' ] = true;
			i++;
		}
		ls ++;
	}
}

int main()
{
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);
	int L, D, N, i, j, k, t;
	scanf("%d%d%d", &L, &D, &N);
	for(i=0; i<D; i++)
		scanf("%s", s[i]);
	char a[1000];
	for(i=1; i<=N; i++)
	{
		scanf("%s", a);
		f(a);
		k = 0;
		for(j=0; j<D; j++)
		{
			for(t =0; t<L; t++)
				if( !vis[t][ s[j][t]-'a' ] ) break;
			if( t == L ) k++;
		}
		printf("Case #%d: %d\n", i, k);
	}
}