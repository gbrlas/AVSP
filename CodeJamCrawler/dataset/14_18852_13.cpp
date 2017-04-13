#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int ix=0;ix<T;ix++)
	{
		printf("Case #%d: ",ix+1);
		int n,d,size[10020];
		scanf("%d %d",&n,&d);
		for(int i=0;i<n;i++)
			scanf("%d",&size[i]);
		int num=0;
		int taken[10020];
		memset(taken,0,sizeof(taken));
		sort(size,size+n);
		for(int i=0;i<n;i++)
		{
			int best=0,bestn=-1;
			if(!taken[i])
			{
			for(int j=0;j<n;j++)
			{
				if(i==j or taken[j])
					continue;
				if(d-(size[i]+size[j])<d-best and d-(size[i]+size[j])>=0)
				{
					best=size[i]+size[j];
					bestn=j;
				}
			}
			num++;
			}
			if(bestn!=-1)
				taken[bestn] = 1;
			taken[i]=1;
		}
		printf("%d\n",num);
	}
	return 0;
}