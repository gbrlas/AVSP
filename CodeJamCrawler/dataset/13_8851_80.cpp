#include <stdio.h>

int pan[4][4];

int check(int x,int y,int dx,int dy)
{
	int i,c[4]={0,};
	for(i=0;i<4;i++)
	{
		c[pan[x][y]]++;
		x+=dx;
		y+=dy;
	}
	if(c[1]==4)
		return 1;
	if(c[2]==4)
		return 2;
	if(c[1]==3 && c[3]==1)
		return 1;
	if(c[2]==3 && c[3]==1)
		return 2;
	return 0;

}

bool print(int k,int res)
{
	if(res==1)
	{
		printf("Case #%d: X won\n",k);
		return true;
	}
	else if(res==2)
	{
		printf("Case #%d: O won\n",k);
		return true;
	}
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,i,j,k,res,draw;
	char tmp[10];
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		draw=1;
		for(i=0;i<4;i++)
		{
			scanf("%s",tmp);
			for(j=0;j<4;j++)
			{
				switch(tmp[j])
				{
					case 'X': pan[i][j]=1; break;
					case 'O': pan[i][j]=2; break;
					case 'T': pan[i][j]=3; break;
					case '.': pan[i][j]=0; draw=0; break;	
				}
			}
		}
		for(i=0;i<4;i++)
			if(print(k+1,check(0,i,1,0)))
				break;
		if(i<4)
			continue;
		for(i=0;i<4;i++)
			if(print(k+1,check(i,0,0,1)))
				break;
		if(i<4)
			continue;
		if(print(k+1,check(0,0,1,1)))
			continue;
		if(print(k+1,check(3,0,-1,1)))
			continue;
		if(draw)
			printf("Case #%d: Draw\n",k+1);
		else
			printf("Case #%d: Game has not completed\n",k+1);
	}
	return 0;
}