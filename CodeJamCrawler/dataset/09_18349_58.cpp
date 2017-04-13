#define X 501
#define Y 501
#include<stdio.h>
#include<string.h>
bool p[X][Y],pd[X];
int x[X],y[Y];
int q[X][2];
int hungary(int n,int m)
{
	memset(x,-1,sizeof(x));
	memset(y,-1,sizeof(y));
	int r=0;
	for(int i=1;i<=n;i++)if(x[i]<0)
	{
		memset(pd,0,sizeof(pd));
		pd[i]=true;
		q[0][0]=i,q[0][1]=-1;
		int j=0,k=1,l;
		bool flag=false;
		while(j<k)
		{
			l=1;
			for(;l<=m;l++)if(p[q[j][0]][l])
			{
				if(y[l]<0)
				{
					flag=true;
					break;
				}
				if(!pd[y[l]])q[k][0]=y[l],q[k][1]=j,pd[y[l]]=true,k++;
			}
			if(flag)break;
			j++;
		}
		if(flag)
		{
			while(j>=0)
			{
				y[l]=q[j][0],k=x[q[j][0]],x[q[j][0]]=l,l=k,j=q[j][1];
			}
			r++;
		}
	}
	return r;
}
int pr[100][25];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	int tt=0;
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)for(int j=0;j<k;j++)scanf("%d",pr[i]+j);
		memset(p,0,sizeof(p));
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		{
			bool pp=true;
			for(int l=0;pp&&l<k;l++)if(pr[i][l]>=pr[j][l])pp=false;
			if(pp)p[i+1][j+1]=true;
		}
		printf("Case #%d: %d\n",++tt,n-hungary(n,n));
	}
}
