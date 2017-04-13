#include<stdio.h>
#include<string.h>
#define SZ 150

char rep[SZ][3], clr[SZ][2], str[SZ], res[SZ];
int C, N, D, cs, pos;
int repFlag[275], clrFlag[275];

void print_ans(char s[])
{

	int i, n=strlen(s);
	printf("Case #%d: [", cs);
	for(i=0; i<n; i++)
	{
		if(i==n-1)printf("%c", s[i]);
		else printf("%c, ", s[i]);
	}
	printf("]\n");
}


int chkRep(char a, char b)
{
	int i;
	for(i=0; i<C; i++)
		if( (rep[i][0]==a && rep[i][1]==b) || (rep[i][0]==b && rep[i][1]==a) )
			return rep[i][2];
	return -1;
}

int chkClr(int sz)
{
	int i, j;
	for(i=0; i<sz; i++)
	{
		for(j=0; j<D; j++)
		{
			if( (clr[j][0]==res[sz] && clr[j][1]==res[i]) || (clr[j][1]==res[sz] && clr[j][0]==res[i]) )
				return 1;
		}
	}
	return 0;
}

void genAns()
{
	int i, con;
	pos = 0;
	res[0] = str[0];
	for(i=1; i<N; i++)
	{
		res[++pos] = str[i];
		if(!pos)continue;
		con = 0;
		con = chkRep(res[pos-1], res[pos]);
		if( con >= 0)
		{
			res[--pos] = con;
			continue;
		}
		if(chkClr(pos))
		{
			pos = -1;
			continue;
		}
	}
	res[++pos] = '\0';
}

void init()
{
	int i;
	for(i=0; i<270; i++)
		repFlag[i] = clrFlag[i] = 1;
}

int main()
{
	freopen("B-small-attempt6.in", "r", stdin);
	freopen("B3.out", "w", stdout);
	int t, i;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++)
	{
		scanf("%d", &C);
		init();
		for(i=0; i<C; i++)
		{
			scanf("%s", rep[i]);
			repFlag[rep[i][0]] = 0;
			repFlag[rep[i][1]] = 0;
		}
		scanf("%d", &D);
		for(i=0; i<D; i++)
		{
			scanf("%s", clr[i]);
			clrFlag[clr[i][0]] = 0;
			clrFlag[clr[i][1]] = 0;
		}
		scanf("%d%s", &N, str);
		if(!C && !D)
		{
			print_ans(str);
			continue;
		}
		genAns();
		print_ans(res);
	}
	return 0;
}