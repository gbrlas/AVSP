#include<stdio.h>
#include<string.h>

char s[1001];
int l;
int n;
char ss[101][51];
int ll[101];
int tt[27];
int sum;
int limit;

void cal()
{
	int tot;
	int i;
	tot=1;
	for (i=0;i<l;i++)
		if (s[i]=='+') 
		{
			sum=(sum+tot)%10009;
			tot=1;
		}
		else tot=(tot*tt[s[i]-'a'])%10009;
	sum=(sum+tot)%10009;
}

void dfs(int x)
{
	if (x==limit+1) cal();
	else
	{
		int i,j;
		for (i=1;i<=n;i++)
		{
			for (j=0;j<ll[i];j++)
				tt[ss[i][j]-'a']++;
			dfs(x+1);
			for (j=0;j<ll[i];j++)
				tt[ss[i][j]-'a']--;
		}
	}
}

int main()
{
	int t,p;
	int i,k;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%s",s);
		l=strlen(s);
		scanf("%d",&k);
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%s",ss[i]);
			ll[i]=strlen(ss[i]);
		}
		printf("Case #%d:",p);
		for (limit=1;limit<=k;limit++)
		{
			sum=0;
			memset(tt,0,sizeof(tt));
			dfs(1);
			printf(" %d",sum);
		}
		printf("\n");
	}
	return 0;
}
