#include <stdio.h>
#include <string>
#include <algorithm>
#define INF 999999999
using namespace std;

int n,N;
int S,Q;

char s[500];
string a[110];
int ind[110];

int memo[110];

bool cmp(int i,int j)
{
	return a[i]<a[j];
}



int main()
{
	freopen("A-large(2).in","r",stdin);
	freopen("A-large(2).out","w",stdout);

	scanf("%d",&N);
	for (n=1;n<=N;n++)
	{
		scanf("%d",&S);
		getchar();
		for (int i=1;i<=S;i++)
		{
			gets(s);
			a[i]=s;
			ind[i]=i;
		}
		sort(ind+1,ind+S+1,cmp);
		scanf("%d",&Q);
		getchar();
		memset(memo,0,sizeof(memo));
		for (int i=1;i<=Q;i++)
		{
			gets(s);
			a[S+1]=s;
			int j=(*lower_bound(ind+1,ind+S+1,S+1,cmp));
			for (int k=1;k<=S;k++)
			{
				memo[k]=min(memo[j]+1,memo[k]);
			}
			memo[j]=INF;
		}
		int res=INF;
		for (int i=1;i<=S;i++)
			res=min(res,memo[i]);
		printf("Case #%d: %d\n",n,res);
	}


	return 0;
}