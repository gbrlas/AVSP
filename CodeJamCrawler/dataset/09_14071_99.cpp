#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};
int a[110][110],n,m,cnt;
char s[110][110],ch;
void show()
{
	int i,j;
	for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				putchar(s[i][j]);
				putchar(j<m-1?' ':'\n');
			}
		}
}
void move(int x,int y,int type)
{
	int i,j,k,px=x,py=y;
	int now=a[x][y];
	for (i=0;i<4;i++)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if (tx>=0&&ty>=0&&tx<n&&ty<m)
		{
			if (a[tx][ty]<now)
			{
				px=tx;
				py=ty;
				now=a[tx][ty];
			}
		}
	}
	//printf("%d - %d\n",x,y);
	if (px==x&&py==y)
	{
		if (!type)
		{
			s[px][py]='a';
			return;
		}
		if (!s[px][py])
		{
			s[px][py]=cnt+'a';
			cnt++;
		}
		ch=s[px][py];
	}
	else 
	{
		move(px,py,type);
	}
}
int main()
{
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k,cas=0,cc;
	scanf("%d",&cc);
	while (cc--)
	{
		cnt=1;
		memset(s,0,sizeof(s));
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				scanf("%d",a[i]+j);
			}
		}
		s[0][0]='a';
		move(0,0,0);
		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (i+j)
				{
			 		if (!s[i][j])
			 		{
			 			move(i,j,1);
			 			s[i][j]=ch;
			 			//show();
			 			//system("pause");
			 		}
				}
			}
		}
		printf("Case #%d:\n",++cas);
		show();
	}
}
