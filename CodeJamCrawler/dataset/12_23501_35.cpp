#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

double dst[10001];
int d[10001];
int l[10001];

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		int N;
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
			dst[i]=-1;
		for(int i=0;i<N;i++)
		{
			scanf("%d%d",&d[i],&l[i]);
		}
		scanf("%d",&d[N]);
		l[N]=0;
		dst[0]=d[0];
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<=N;j++)
			{
				if(d[j]-d[i]>dst[i]) break;
				double td=d[j]-d[i];
				dst[j]=max(dst[j],sqrt(dst[i]*dst[i]-td*td));
				dst[j]=max(dst[j],td);
				dst[j]=min(dst[j],double(l[j]));
			}
		}
		printf("Case #%d: %s\n",test,dst[N]<-0.5?"NO":"YES");
	}
	return 0;
}
