//#include<stdafx.h>

#include<iostream>
#include<cstring>
using namespace std;
char codef[]={"welcome to code jam"};
char map[510];
int vist[510];
int total=0;
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("ccc.out","w",stdout);
	int N,i,j,k,xx,len,xlen;
	xlen=strlen(codef);
	scanf("%d",&N);
	getchar();
	for(xx=1;xx<=N;xx++)
	{
		gets(map);
		memset(vist,0,sizeof(vist));
		len=strlen(map);
		total=0;
		for(i=0;i<len;i++)
		{
			if(map[i]==codef[xlen-1])
				vist[i]=1;
		}
		for(i=xlen-2;i>=0;i--)
		{
			for(j=0;j<len;j++)
			{
				if(map[j]==codef[i])
				{
					total=0;
					for(k=j+1;k<len;k++)
					{
						if(map[k]==codef[i+1])
							total=(total+vist[k])%10000;
					}
					vist[j]=total;
				}
			}
		}
		total=0;
		for(i=0;i<len;i++)
		{
			if(map[i]==codef[0])
				total=(total+vist[i])%10000;
		}
		printf("Case #%d: %04d\n",xx,total%10000);
	}
	return 0;
}