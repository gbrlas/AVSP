#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[5][5];
float b[5][5];
float h[5],s[5];
float xx[3];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
	
		getchar();
		for(int k=1;k<=n;k++)
		{
			memset(h,0,sizeof(h));
			memset(s,0,sizeof(s));
			memset(b,0,sizeof(b));
			int flag=0;
			for(int i=1;i<=4;i++)
			{
				h[i]=0.0;
				scanf("%s",a[i]);
				for(int j=0;j<4;j++)
				{
					if(a[i][j]=='O')
						b[i][j+1]=-1;
					else if(a[i][j]=='X')
						b[i][j+1]=1;
					else if(a[i][j]=='T')
						b[i][j+1]=0.5;
					else if(a[i][j]=='.')
					{
						b[i][j+1]=0;
						flag=1;
					}
					h[i]+=b[i][j+1];
				}
			}
	//		getchar();
		
			for(int i=1;i<=4;i++)
			{
				s[i]=0;
				for(int j=1;j<=4;j++)
					s[i]+=b[j][i];
			}
	//		printf("h[1]==%.2f\ns[1]==%.2f\n",h[1],s[1]);
			int x=0,o=0;
			for(int i=1;i<=4;i++)
			{
				if(h[i]>=3.5 || s[i]>=3.5)
				{
					x=1;break;
				}
				if(h[i]==-4 || s[i]==-4 || (s[i]==-2.5) || s[i]==-2.5)
				{
					o=1;break;
				}
			}
			xx[1]=b[1][1]+b[2][2]+b[3][3]+b[4][4];
			xx[2]=b[1][4]+b[2][3]+b[3][2]+b[4][1];
			if(xx[1]>=3.5 || xx[2]>=3.5) x=1;
			if(xx[1]==-4 || xx[1]==-2.5 || xx[2]==-4 || xx[2]==-2.5)
				o=1;
			printf("Case #%d: ",k);
			if(x==0 && o==0)
			{
				if(flag==1)
					printf("Game has not completed");
				else 
					printf("Draw");
			}
			if(x==1)
				printf("X won");
			if(o==1)
				printf("O won");
			printf("\n");


		}
	}
}

