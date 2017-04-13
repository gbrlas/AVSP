#include<stdio.h>
#include<string.h>
#define maxn 110
#define inf  10000000

char engines[maxn][maxn];
char query[maxn];
int seq[maxn*10];
int ans[maxn*10][maxn];
int n,m;

int my_min(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small-attempt2.out","w",stdout);

	int cases;
	int cas=1;
	int i,j,k;
    int cc;

	scanf("%d",&cases);

	while(cases--)
	{
		scanf("%d",&n);
		getchar();
		for(i=0;i<n;i++) gets(engines[i]);
		scanf("%d",&m);
        getchar();
		if(m==0)
		{
			cc=0;
			printf("Case #%d: %d\n",cas++,cc);
			continue;
		}

		for(i=0;i<m;i++)
		{
			gets(query);
			for(j=0;j<n;j++)
			{
				if(strcmp(engines[j],query)==0) break;
			}
			seq[i]=j;
		}

		for(i=0;i<m;i++)
			for(j=0;j<n;j++) ans[i][j]=inf;

		for(i=0;i<n;i++)
		{
			if(seq[0]==i) continue;
			ans[0][i]=0;
		}

		for(i=1;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(seq[i]==j) continue;
				for(k=0;k<n;k++)
				{
					if(j==k) ans[i][j]=my_min(ans[i][j],ans[i-1][j]);
					else ans[i][j]=my_min(ans[i][j],ans[i-1][k]+1);
				}
				
			}
		}

		cc=inf;
		for(i=0;i<n;i++) cc=my_min(cc,ans[m-1][i]);

		printf("Case #%d: %d\n",cas++,cc);
	}

	

	return 0;
}