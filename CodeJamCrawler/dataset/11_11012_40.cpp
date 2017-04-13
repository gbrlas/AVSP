#include <fstream>
//freopen("a.txt","r",stdin);

#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;


int main()
{
	//freopen("A-small-practice.in","r",stdin);
	freopen("A-large.in","r",stdin);
	
	freopen("b.txt","w",stdout);
	
	int t,z,r,c,i,j,k,can;
	char m[55][55],n[55][55];
	int f[55][55];

	scanf("%d",&t);
	for(z=1;z<=t;z++)
	{
		can=1;
		scanf("%d%d",&r,&c);
		for(i=0;i<r;i++)
		{
			scanf("%s",m[i]);
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				n[i][j]=m[i][j];
				f[i][j]=0;
			}
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(f[i][j]==0&&m[i][j]=='#')
				{
					if(!((i+1<r)&&(j+1)<c
						&&f[i][j+1]==0&&m[i][j+1]=='#'
						&&f[i+1][j]==0&&m[i+1][j]=='#'
						&&f[i+1][j+1]==0&&m[i+1][j+1]=='#'))
					{
						can=0;
						break;
					}
					n[i][j]='/';
					n[i][j+1]='\\';
					n[i+1][j]='\\';
					n[i+1][j+1]='/';

					f[i][j]=1;
					f[i][j+1]=1;
					f[i+1][j]=1;
					f[i+1][j+1]=1;
				}
			}
			if(can==0)
			{
				break;
			}
		}
		printf("Case #%d:\n",z);
		if(can==0)
		{
			printf("Impossible\n");
		}
		else
		{
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					printf("%c",n[i][j]);
				}
				printf("\n");
			}
			
		}
	}
    return 0;
}