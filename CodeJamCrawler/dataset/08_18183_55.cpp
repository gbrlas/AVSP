#define X 201
#define Y 201
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
int zh(char *x)
{
	return ((x[0]-'0')*10+x[1]-'0')*60+(x[3]-'0')*10+x[4]-'0';
}
int ti[X][2];
int main()
{
	int n;
	scanf("%d",&n);
	for(int tt=1;tt<=n;tt++)
	{
		int t,na,nb;
		scanf("%d%d%d",&t,&na,&nb);
		for(int i=1;i<=na+nb;i++)
		{
			char z[6];
			scanf("%s",z);
			ti[i][0]=zh(z);
			scanf("%s",z);
			ti[i][1]=zh(z);
		}
		memset(p,0,sizeof(p));
		for(int i=1;i<=na;i++)for(int j=1;j<=nb;j++)if(ti[i][1]+t<=ti[j+na][0])p[i][j+na]=true;
		for(int i=1;i<=nb;i++)for(int j=1;j<=na;j++)if(ti[i+na][1]+t<=ti[j][0])p[i+na][j]=true;
		hungary(na+nb,na+nb);
		int xa=0,xb=0;
		for(int i=1;i<=na;i++)if(y[i]<0)xa++;
		for(int i=1;i<=nb;i++)if(y[i+na]<0)xb++;
		printf("Case #%d: %d %d\n",tt,xa,xb);
	}
}
