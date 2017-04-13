#include<iostream>
using namespace std;
int N,L,H;
int ot[105];
int main()
{
	//freopen("C-small-attempt0.in","r",stdin);
	//freopen("C-small-attempt0.out","w",stdout);
	int T,Case=0;
	int i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&N,&L,&H);
		for(i=1;i<=N;i++)
			scanf("%d",&ot[i]);
		for(i=L;i<=H;i++)
		{
			for(j=1;j<=N;j++)
			{
				if(i%ot[j]!=0&&ot[j]%i!=0)
					break;
			}
			if(j>N)
				break;
		}
		if(i>H)
			printf("Case #%d: NO\n",++Case);
		else
			printf("Case #%d: %d\n",++Case,i);
	}
	return 0;
}
