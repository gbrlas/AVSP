#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int a[2010],b[2010];
int res[2010];
int mm[2010];
int le[2010],ri[2010];
int f[2010];
int n;

void dfs(int i)
{
	int j,l;
	if (i==n+1)
	{
		for (j=1;j<=n;j++)
			if (res[j]!=mm[j]) break;
		if (j<=n&&res[j]<mm[j])
		{
			for (j=1;j<=n;j++)
				mm[j]=res[j];
		}
		return;
	}
	le[0]=0;
	f[0]=0;
	l=0;
	for (j=1;j<=n;j++)
	{
		if (res[j]==-1) le[j]=l;
		else
		{
			int high=l;
			int low=0;
			int mid;
			while (high>low)
			{
				mid=(high+low+1)/2;
				if (res[f[mid]]<res[j]) low=mid;
				else high=mid-1;
			}
			le[j]=le[f[low]]+1;
			if (low==l) l++;
			f[low+1]=j;
		}
	}
	ri[n+1]=0;
	f[0]=n+1;
	l=0;
	for (j=n;j>=1;j--)
	{
		if (res[j]==-1) ri[j]=l;
		else
		{
			int high=l;
			int low=0;
			int mid;
			while (high>low)
			{
				mid=(high+low+1)/2;
				if (res[f[mid]]<res[j]) low=mid;
				else high=mid-1;
			}
			ri[j]=ri[f[low]]+1;
			if (low==l) l++;
			f[low+1]=j;
		}
	}
	vector <int> tt;
	tt.clear();
	for (j=1;j<=n;j++)
		if (res[j]==-1&&a[j]==le[j]+1&&b[j]==ri[j]+1) tt.push_back(j);
	for (j=0;j<tt.size();j++)
	{
		res[tt[j]]=i;
		dfs(i+1);
		res[tt[j]]=-1;
	}
}

int main()
{
	int t,p;
	int i;
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-small-attempt2.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for (i=1;i<=n;i++)
			scanf("%d",&b[i]);
		memset(res,-1,sizeof(res));
		for (i=1;i<=n;i++)
			mm[i]=n+1;
		dfs(1);
		printf("Case #%d:",p);
		for (i=1;i<=n;i++)
			printf(" %d",mm[i]);
		printf("\n");
	}
	return 0;
}

