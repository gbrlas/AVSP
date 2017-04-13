#include<stdio.h>

int n;
bool u[16][16];
int a[16][26];
int mm;
int l;
int v[16][16];
int len[16];

void dfs(int x)
{
	if (x==n) 
	{
		mm=l;
		return;
	}
	int i,j;
	for (i=1;i<=l;i++)
	{
		for (j=1;j<=len[i];j++)
			if (!u[v[i][j]][x]) break;
		if (j==len[i]+1)
		{
			len[i]++;
			v[i][len[i]]=x;
			dfs(x+1);
			len[i]--;
		}
	}
	if (l+1<mm)
	{
		l++;
		len[l]=1;
		v[l][1]=x;
		dfs(x+1);
		l--;
	}
}

int main()
{
	int t,p;
	int k;
	int i,j,kk;
	bool flag;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d",&n,&k);
		for (i=0;i<n;i++)
			for (j=0;j<k;j++)
				scanf("%d",&a[i][j]);
		for (i=0;i<n;i++)
			for (j=i+1;j<n;j++)
			{
				flag=true;
				for (kk=0;kk<k-1;kk++)
				{
					if (a[i][kk]==a[j][kk])
					{
						flag=false;
						break;
					}
					if (a[i][kk]<a[j][kk])
					{
						if (a[i][kk+1]>=a[j][kk+1])
						{
							flag=false;
							break;
						}
					}
					else
					{
						if (a[i][kk+1]<=a[j][kk+1])
						{
							flag=false;
							break;
						}
					}
				}
				u[i][j]=flag;
				u[j][i]=flag;
			}
		mm=n;
		l=0;
		dfs(0);
		printf("Case #%d: %d\n",p,mm);
	}
	return 0;
}

