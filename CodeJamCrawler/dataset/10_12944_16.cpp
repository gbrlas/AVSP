#include <stdio.h>
#include <string.h>

int c[1000][1000];
int t[1000][1000];
int r=100;

int find()
{
	int cc=0;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<r;j++)
			if(c[i][j]==1)
				cc++;
	}
	return cc;
}

int get(int x,int y)
{
	if(x<0 || x>=r)
		return 0;
	if(y<0 || y>=r)
		return 0;
	return c[x][y];
}

void adjust()
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
		{
			if(c[i][j]==1 && get(i-1,j)==0 && get(i,j-1)==0)
				t[i][j]=0;
			else if(c[i][j]==0 && get(i-1,j)==1 && get(i,j-1)==1)
				t[i][j]=1;
			else 
				t[i][j]=c[i][j];
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
			c[i][j]=t[i][j];
	}

}

int main()
{

	freopen("C-small-attempt0.in","r",stdin);
	freopen("c_small.out","w",stdout);

	int cases;
	int icases=1;
	int ans=0;
	int i,x1,y1,cc,x2,y2;
	int j,k;
	int rr;

	scanf("%d",&cases);

	while(icases<=cases)
	{
		scanf("%d",&rr);
		memset(c,0,sizeof(c));
		
		for(i=0;i<rr;i++)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			x1--;y1--;
			x2--;y2--;
			for(j=x1;j<=x2;j++)
			{
				for(k=y1;k<=y2;k++)
					c[j][k]=1;
			}
		}

		ans=0;
		while(1)
		{
			cc=find();
			if(cc==0)
				break;
			adjust();
			ans++;
		}
		printf("Case #%d: %d\n",icases++,ans);
	}
	return 0;
}


