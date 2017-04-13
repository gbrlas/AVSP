//I dreamed it!
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("C-small-attemp0.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		int N;
		scanf("%d",&N);
		int cdy[1001];
		for(int i=0;i<N;i++)
			scanf("%d",&cdy[i]);

		int up=1<<N;
		int ans=-1;
		for(int i=1;i<up-1;i++)
		{
			int t=1,pos=0;
			int suma=0,sumb=0;
			int xa=0,xb=0;
			while(t<up)
			{
				if(t&i)
				{
					suma+=cdy[pos];
					xa^=cdy[pos];
				}
				else
				{
					sumb+=cdy[pos];
					xb^=cdy[pos];
				}
				t=t<<1;
				pos++;
			}
			if(xa==xb)
			{
				int tmp=suma>sumb?suma:sumb;
				ans=ans>tmp?ans:tmp;
			}
		}
		printf("Case #%d: ",tt);
		if(ans==-1)
			printf("NO\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}



