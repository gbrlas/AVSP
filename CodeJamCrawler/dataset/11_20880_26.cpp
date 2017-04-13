#include<stdio.h>
#include<string.h>

char a[501][501];
int x[501][501];
int y[501][501];
int q[501][501];

int main()
{
	int t,p;
	int n,m,dd;
	int rr;
	int i,j,k;
	int res;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d%d",&n,&m,&dd);
		for (i=0;i<n;i++)
			scanf("%s",a[i]);
		x[0][0]=0;
		y[0][0]=0;
		q[0][0]=a[0][0]-'0';
		for (j=1;j<m;j++)
		{
			x[0][j]=0;
			y[0][j]=y[0][j-1]+(a[0][j]-'0')*j;
			q[0][j]=q[0][j-1]+a[0][j]-'0';
		}
		for (i=1;i<n;i++)
		{
			x[i][0]=x[i-1][0]+(a[i][0]-'0')*i;
			y[i][0]=y[i-1][0];
			q[i][0]=q[i-1][0]+a[i][0]-'0';
			int sx=(a[i][0]-'0')*i;
			int sy=0;
			int sq=a[i][0]-'0';
			for (j=1;j<m;j++)
			{
				sx=sx+(a[i][j]-'0')*i;
				sy=sy+(a[i][j]-'0')*j;
				sq=sq+a[i][j]-'0';
				x[i][j]=x[i-1][j]+sx;
				y[i][j]=y[i-1][j]+sy;
				q[i][j]=q[i-1][j]+sq;
			}
		}
		if (n<m) rr=n;
		else rr=m;
		res=1;
		for (k=1;k<=(rr-1)/2;k++)
		{
			for (i=k;i+k<n;i++)
				for (j=k;j+k<m;j++)
				{
					int s1=x[i+k][j+k]-x[i-k-1][j+k]-x[i+k][j-k-1]+x[i-k-1][j-k-1]-i*(q[i+k][j+k]-q[i-k-1][j+k]-q[i+k][j-k-1]+q[i-k-1][j-k-1]);
					s1=s1-k*(a[i+k][j+k]-'0')+k*(a[i-k][j+k]-'0')-k*(a[i+k][j-k]-'0')+k*(a[i-k][j-k]-'0');
					if (s1==0)
					{
						int s2=y[i+k][j+k]-y[i-k-1][j+k]-y[i+k][j-k-1]+y[i-k-1][j-k-1]-j*(q[i+k][j+k]-q[i-k-1][j+k]-q[i+k][j-k-1]+q[i-k-1][j-k-1]);
						s2=s2-k*(a[i+k][j+k]-'0')-k*(a[i-k][j+k]-'0')+k*(a[i+k][j-k]-'0')+k*(a[i-k][j-k]-'0');
						if (s2==0)
						{
							res=2*k+1;
						}
					}
				}
		}
		for (k=res/2+1;k<=rr/2;k++)
		{
			for (i=k;i+k-1<n;i++)
				for (j=k;j+k-1<m;j++)
				{
					int s1=2*(x[i+k-1][j+k-1]-x[i-k-1][j+k-1]-x[i+k-1][j-k-1]+x[i-k-1][j-k-1])-(2*i-1)*(q[i+k-1][j+k-1]-q[i-k-1][j+k-1]-q[i+k-1][j-k-1]+q[i-k-1][j-k-1]);
					s1=s1-(a[i+k-1][j+k-1]-'0')*(2*k-1)+(a[i-k][j+k-1]-'0')*(2*k-1)-(a[i+k-1][j-k]-'0')*(2*k-1)+(a[i-k][j-k]-'0')*(2*k-1);
					if (s1==0)
					{
						int s2=2*(y[i+k-1][j+k-1]-y[i-k-1][j+k-1]-y[i+k-1][j-k-1]+y[i-k-1][j-k-1])-(2*j-1)*(q[i+k-1][j+k-1]-q[i-k-1][j+k-1]-q[i+k-1][j-k-1]+q[i-k-1][j-k-1]);
						s2=s2-(a[i+k-1][j+k-1]-'0')*(2*k-1)-(a[i-k][j+k-1]-'0')*(2*k-1)+(a[i+k-1][j-k]-'0')*(2*k-1)+(a[i-k][j-k]-'0')*(2*k-1);
						if (s2==0)
						{
							res=2*k;
						}
					}
				}
		}
		if (res>=3) printf("Case #%d: %d\n",p,res);
		else printf("Case #%d: IMPOSSIBLE\n",p);
	}
	return 0;
}

