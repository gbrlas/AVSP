#include <stdio.h>

int L, D, N;

char dict[5001][16];
char str[2048];

int go()
{
	int now = 0;
	bool available[16][26] = {0,};
	
	for(char *p = str; *p; ++ p)
	{
		if(*p == '(')
		{
			char *q;
			for(q = p+1; *q != ')'; ++ q)
				available[now][*q - 'a'] = true;
			p = q;
		}
		else
		{
			available[now][*p - 'a'] = true;
		}
		now++;
	}

	int cnt = 0;
	for(int i=1; i<=D; ++i)
	{
		bool err = false;
		for(int j=0; j<L; ++j)
			if(available[ j ][dict[i][j] - 'a' ] == false)
				err = true;
		if(!err) cnt++;
	}
	return cnt;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	scanf("%d %d %d", &L, &D, &N);

	for(int i=1; i<=D; ++i) scanf("%s", dict[i]);
	for(int i=1; i<=N; ++i)
	{
		scanf("%s", str);
		printf("Case #%d: %d\n", i, go());
	}
	return 0;
}