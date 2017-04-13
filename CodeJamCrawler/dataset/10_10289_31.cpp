#include <iostream>
using namespace std;
int now[200][200];
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("ans.out","w",stdout);
	int Ca,C,T;
	scanf("%d",&C);
	for(Ca=1;Ca<=C;Ca++)
	{
		T=0;
		int i,j,p,q;
		int K;
		scanf("%d",&K);
		memset(now,0,sizeof(now));
		int all;
		int Maxx=-1,Maxy=-1;
		for(i=0;i<K;i++)
		{
			int x1,y1,x2,y2,p,q;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			Maxy=Maxy>x2?Maxy:x2;
			Maxx=Maxx>y2?Maxx:y2;
			for(p=x1;p<=x2;p++)
				for(q=y1;q<=y2;q++)
					now[q][p]=1;
		}
		bool flag=1;
		Maxy+=5;
		Maxx+=5;
		for(T=0;flag==1;T++)
		{
			flag=0;
			for(i=Maxx;i>=1;i--)
				for(j=Maxy;j>=1;j--)
				{
					if(now[i][j]==0&&now[i][j-1]==1&&now[i-1][j]==1) { now[i][j]=1; }
					if(now[i][j]==1&&now[i][j-1]==0&&now[i-1][j]==0) { now[i][j]=0; }
				}
			for(i=Maxx;i>=1;i--)
			{		
				for(j=Maxy;j>=1;j--)
				{
					if(now[i][j]==1) { flag=1; break; }
				}
				if(flag==1) break;
			}
		}
		printf("Case #%d: %d\n",Ca,T);
	}
	return 0;
}
