#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int map[1000];

int main()
{
	freopen("B-small-attempt0.out","w",stdout);
	memset(map,0,sizeof(map));
	map['Q']=1;map['W']=2;map['E']=3;map['R']=4;
	map['A']=5;map['S']=6;map['D']=7;map['F']=8;
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		char com[10][10];
		memset(com,0,sizeof(com));
		int C;
		scanf("%d",&C);
		while(C--)
		{
			char tmp[10];
			scanf("%s",tmp);
			int a=map[tmp[0]],b=map[tmp[1]];
			com[a][b]=com[b][a]=tmp[2];
		}

		int D;
		scanf("%d",&D);
		bool op[10][10];
		memset(op,false,sizeof(op));

		while(D--)
		{
			char tmp[5];
			scanf("%s",tmp);
			int a=map[tmp[0]],b=map[tmp[1]];
			op[a][b]=op[b][a]=true;
		}

		int N;
		scanf("%d",&N);
		char buf[200];
		scanf("%s",buf);

		char ans[200];
		int idx=0;
		for(int i=0;i<N;i++)
		{
			if(idx==0)
			{
				ans[idx++]=buf[i];
				continue;
			}
			int cur=map[buf[i]];
			int pre=map[ans[idx-1]];
			if(pre&&com[pre][cur])
			{
				ans[idx-1]=com[pre][cur];
				continue;
			}
			bool flag=false;
			for(int j=idx-1;j>=0;j--)
			{
				int t=map[ans[j]];
				if(t&&op[cur][t])
				{
					flag=true;
					break;
				}
			}
			if(flag)
			{
				idx=0;
				continue;
			}
			ans[idx++]=buf[i];
		}
		printf("Case #%d: [",tt);
		if(idx!=0)
		{
			printf("%c",ans[0]);
			for(int i=1;i<idx;i++)
				printf(", %c",ans[i]);
		}
		printf("]\n");
	}
	return 0;
}
