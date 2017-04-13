#include <stdio.h>
#include <string.h>
struct TTrip
{
	int b,e;
};
TTrip trip[2][1010];
int used[2][1010];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int nt,it;
	int ans[2];
	scanf("%d",&nt);
	
	for (it=0;it<nt;it++)
	{
		int t,n[2];
		scanf("%d%d%d",&t,&n[0],&n[1]);
		memset(used,0,sizeof(used));
		for (int j=0;j<2;j++)
			for (int i=0;i<n[j];i++)
			{
				int h1,m1,h2,m2;
				scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
				trip[j][i].b=h1*60+m1;
				trip[j][i].e=h2*60+m2;
			}
		memset(ans,0,sizeof(ans));

		for(;;)
		{
			int mintime = 60*60,jj=-1,ii=-1;
			for (int j=0;j<2;j++)
				for (int i=0;i<n[j];i++)
				{
					if (!used[j][i] && trip[j][i].b < mintime)
					{
						mintime=trip[j][i].b;
						jj=j;
						ii=i;
					}
				}
			if (jj==-1)
				break;
			ans[jj]++;
			int curj=jj;
			int curi=ii;
			used[curj][curi]=1;
			for(;;)
			{
				int mintime = 60*60,ii=-1;
				for (int i=0;i<n[1-curj];i++)
				{
					if (!used[1-curj][i] && trip[1-curj][i].b < mintime && trip[1-curj][i].b >= trip[curj][curi].e+t)
					{
						mintime=trip[1-curj][i].b;
						ii=i;
					}
				}
				if (ii==-1)
					break;
				curj=1-curj;
				curi=ii;
				used[curj][curi]=1;
			}
		}

		printf("Case #%d: %d %d\n",it+1,ans[0],ans[1]);
	}
	return 0;
}