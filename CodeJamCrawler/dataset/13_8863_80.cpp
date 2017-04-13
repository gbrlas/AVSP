#include <stdio.h>

int h[200][200],maxr[200],maxc[200];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n,m,i,j,k;
	bool possible;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d%d",&n,&m);
		for(j=0;j<m;j++)
			maxc[j]=0;
		for(i=0;i<n;i++)
		{
			maxr[i]=0;
			for(j=0;j<m;j++)
			{
				scanf("%d",&h[i][j]);
				maxr[i]=maxr[i]>h[i][j]?maxr[i]:h[i][j];
				maxc[j]=maxc[j]>h[i][j]?maxc[j]:h[i][j];
			}
		}
		possible=true;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(h[i][j]!=maxr[i] && h[i][j]!=maxc[j])
					possible=false;
		printf("Case #%d: %s\n",k+1,possible?"YES":"NO");
	}
}