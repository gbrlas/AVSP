#include<stdio.h>
#include<string.h>
#define MAXN 10009
#define MAXF 0x7FFFF
bool chg[MAXN],g[MAXN];
bool input[MAXN],si[MAXN];
int m;
int min(int a,int b){return a<b?a:b;}
int get(bool v,int x,bool cd=0)
{
	if(si[x])
	{
		if(input[x]==v)return 0;
		return MAXF;
	}
	if(v)
	{
		int a=get(1,2*x);
		int b=get(1,2*x+1);
		int c=get(0,2*x);
		int d=get(0,2*x+1);
		if(g[x]^cd)
		{
			if(chg[x]&&!cd)return min(a+b,get(v,x,1)+1);
			return a+b;
		}
		else
		{
			if(chg[x]&&!cd)return min(min(a,b),get(v,x,1)+1);
			return min(a,b);
		}
		return a+b;
	}
	else 
	{
		//int a=get(1,2*x);
		//int b=get(1,2*x+1);
		int c=get(0,2*x);
		int d=get(0,2*x+1);
		if(g[x]^cd)
		{
			if(chg[x]&&!cd)return min(min(c,d),get(v,x,1)+1);
			return min(c,d);
		}
		else
		{
			if(chg[x]&&!cd)return min(c+d,get(v,x,1)+1);
			return c+d;
		}
		
	}
}
int main()
{
	int pk;
	freopen("A-large.in","r",stdin);
	freopen("A-large.txt","w",stdout);
	scanf("%d",&pk);
	int k;
	for(k=1;k<=pk;k++)
	{

		
		int n,v;
		scanf("%d %d\n",&m,&v);
		char str[256];
		int i,j;
		memset(si,0,sizeof si);
		for(i=1;i<=m;i++)
		{
			gets(str);
			if(strchr(str,' '))
			{
				sscanf(str,"%d %d",&g[i],&chg[i]);
			}
			else 
			{
				sscanf(str,"%d",&input[i]);
				si[i]=1;
			}
		}
		int tmp=get(v,1,0);
		printf("Case #%d: ",k);
		if(tmp>=MAXF)
			printf("IMPOSSIBLE\n");
		else printf("%d\n",tmp);

	}
	return 0;
}