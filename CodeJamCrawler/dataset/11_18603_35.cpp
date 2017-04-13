#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	freopen("a.in","r",stdin);
	freopen("a.txt","w",stdout);
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		int N;
		scanf("%d",&N);
		int op[101][101];
		bool re[101][101];
		int comp[101][101];
		int win[101];
		int nop[101];
		char t;
		memset(win,0,sizeof(win));
		memset(nop,0,sizeof(nop));
		memset(comp,0xff,sizeof(comp));
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
			{
				t=getchar();
				while(t!='.'&&t!='1'&&t!='0')t=getchar();
				if(t=='1')
				{
					win[i]++;
					op[i][nop[i]++]=j;
					comp[i][j]=1;
				}
				else if(t=='0')
				{	op[i][nop[i]++]=j;
					comp[i][j]=0;
				}
			}
		double WP[101],OWP[101],OOWP[101];
		for(int i=1;i<=N;i++)
			WP[i]=win[i]*1.0/nop[i];
		for(int i=1;i<=N;i++)
		{
			double sum=0;
			for(int j=1;j<=N;j++)	
			{
				if(j==i||comp[j][i]==-1)continue;
				int w=win[j],n=nop[j];
				if(comp[j][i]==1)
				{
					w--;
					n--;
				}
				else if(comp[j][i]==0)
					n--;
				sum+=w*1.0/n;
			}
			OWP[i]=sum/nop[i];
		}
		for(int i=1;i<=N;i++)
		{
			double sum=0;
			for(int j=0;j<nop[i];j++)
				sum+=OWP[op[i][j]];
			OOWP[i]=sum/nop[i];
		}
		printf("Case #%d:\n",tt);
		for(int i=1;i<=N;i++)
			printf("%.7lf\n",0.25*WP[i]+0.5*OWP[i]+0.25*OOWP[i]);
	}
	return 0;
}
			

