#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int T;
	freopen("aaa.in","r",stdin);
	freopen("aaa.out","w",stdout);
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		int R,C;
		scanf("%d%d",&R,&C);
		char map[55][55];
		char c;
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
			{
				c=getchar();
				while(c!='#'&&c!='.')c=getchar();
				map[i][j]=c;
			}
		bool flag=true;
		for(int i=0;i<R-1;i++)
			for(int j=0;j<C-1;j++)
				if(map[i][j]=='#')
				{
					if(map[i+1][j]!='#'||map[i][j+1]!='#'||map[i+1][j+1]!='#')
						flag=false;
					else
					{
						map[i][j]='/';map[i][j+1]='\\';map[i+1][j]='\\';map[i+1][j+1]='/';
					}
				}
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				if(map[i][j]=='#')
					flag=false;
		printf("Case #%d:\n",tt);
		if(flag)
		{
			for(int i=0;i<R;i++)
			{
				for(int j=0;j<C;j++)
					putchar(map[i][j]);
				putchar(10);
			}
		}
		else
			puts("Impossible");
	}
	return 0;
}
