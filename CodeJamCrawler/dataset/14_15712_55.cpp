#include<cstdio>
#include<cstring>
int cnt[20];
int main()
{
	int i,j,tt,t,s,x;
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	for(scanf("%d",&tt),t=1;t<=tt;++t)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&s);
		for(i=1;i<s;++i)
			for(j=1;j<=4;++j)
				scanf("%d",&x);
		for(i=1;i<=4;++i)
		{
			scanf("%d",&x);
			++cnt[x];
		}
		for(i=s+1;i<=4;++i)
			for(j=1;j<=4;++j)
				scanf("%d",&x);
		scanf("%d",&s);
		for(i=1;i<s;++i)
			for(j=1;j<=4;++j)
				scanf("%d",&x);
		for(i=1;i<=4;++i)
		{
			scanf("%d",&x);
			++cnt[x];
		}
		for(i=s+1;i<=4;++i)
			for(j=1;j<=4;++j)
				scanf("%d",&x);
		x=0;
		for(i=1;i<=16;++i)
			if(cnt[i]>=2)
				if(x)
					x=-1;
				else
					x=i;
		if(x==0)
			printf("Case #%d: Volunteer cheated!\n",t);
		if(x==-1)
			printf("Case #%d: Bad magician!\n",t);
		if(x>0)
			printf("Case #%d: %d\n",t,x);
	}
	return 0;
}
