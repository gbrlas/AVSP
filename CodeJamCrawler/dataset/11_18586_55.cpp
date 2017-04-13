#include <iostream>
#include <cstdio>
using namespace std;

struct order
{
	int NO,pos;
};

inline int ABS(int x)
{
	return x<0?-x:x;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		int N,idxa,idxb;
		order oa[101],ob[101];
		idxa=idxb=0;
		scanf("%d",&N);
		char rob[10];
		int pos;
		for(int i=0;i<N;i++)
		{
			scanf("%s %d",rob,&pos);
			if(rob[0]=='O')
			{
				oa[idxa].NO=i;
				oa[idxa++].pos=pos;
			}
			else
			{	
				ob[idxb].NO=i;
				ob[idxb++].pos=pos;
			}
		}
		int nexta=0,nextb=0,posa=1,posb=1;
		int ans=0;
		while(nexta<idxa||nextb<idxb)
		{
			if(nexta==idxa)
			{
				ans+=ABS(posb-ob[nextb].pos)+1;
				posb=ob[nextb].pos;
				nextb++;
				continue;
			}
			if(nextb==idxb)
			{
				ans+=ABS(posa-oa[nexta].pos)+1;
				posa=oa[nexta].pos;
				nexta++;
				continue;
			}
			if(oa[nexta].NO<ob[nextb].NO)
			{
				int t=ABS(posa-oa[nexta].pos)+1;
				ans+=t;
				posa=oa[nexta++].pos;
				int d=ABS(posb-ob[nextb].pos);
				if(t<d)d=t;
				if(ob[nextb].pos>posb)posb+=d;
				else posb-=d;
			}
			else
			{
				int t=ABS(posb-ob[nextb].pos)+1;
				ans+=t;
				posb=ob[nextb++].pos;
				int d=ABS(posa-oa[nexta].pos);
				if(t<d)d=t;
				if(oa[nexta].pos>posa)posa+=d;
				else posa-=d;
			}
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}

