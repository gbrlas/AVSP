#include <iostream>
using namespace std;
const int maxn=510;
long long a[maxn][maxn],sum[maxn][maxn],sumx[maxn][maxn],sumy[maxn][maxn],i,j,k,n,m,t,d,ans,t1,t2;
char x;
long long getsum(long long sum[][maxn],long long x0,long long y0,long long x1,long long y1)
{
	return sum[x1][y1]+sum[x0-1][y0-1]-sum[x1][y0-1]-sum[x0-1][y1];
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for (long long count_t=1;count_t<=t;count_t++)
	{
		cin>>n>>m>>d;
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				cin>>x;
				a[i][j]=sum[i][j]=sumx[i][j]=sumy[i][j]=x;
			}
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
				sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
				sumx[i][j]=sumx[i-1][j]+getsum(sum,i,1,i,j)*i;
		for (j=1;j<=m;j++)
			for (i=1;i<=n;i++)
				sumy[i][j]=sumy[i][j-1]+getsum(sum,1,j,i,j)*j;
		ans=-1;
		for (i=2;i<n;i++)
			for (j=2;j<m;j++)
				for (k=1;k<=n;k++)
				{
					if ((i-k<1)||(i+k>n)||(j-k<1)||(j+k>m)) break;
					d=(t1=getsum(sumx,i-k,j-k,i+k,j+k))-i*(t2=getsum(sum,i-k,j-k,i+k,j+k));
					d=d+(a[i-k][j-k]+a[i-k][j+k]-a[i+k][j-k]-a[i+k][j+k])*k;
					if (d!=0) continue;
					d=getsum(sumy,i-k,j-k,i+k,j+k)-j*getsum(sum,i-k,j-k,i+k,j+k);
					d=d+(a[i-k][j-k]+a[i+k][j-k]-a[i-k][j+k]-a[i+k][j+k])*k;
					if (d!=0) continue;
					if (k+k+1>ans) ans=k+k+1;
				}
		for (i=2;i<n;i++)
			for (j=2;j<m;j++)
				for (k=1;k<=n;k++)
				{
					if ((i-k<1)||(i+k+1>n)||(j-k<1)||(j+k+1>m)) break;
					d=2*getsum(sumx,i-k,j-k,i+k+1,j+k+1)-(2*i+1)*getsum(sum,i-k,j-k,i+k+1,j+k+1);
					d=d+(a[i-k][j-k]+a[i-k][j+k+1]-a[i+k+1][j-k]-a[i+k+1][j+k+1])*(2*k+1);
					if (d!=0) continue;
					d=2*getsum(sumy,i-k,j-k,i+k+1,j+k+1)-(2*j+1)*getsum(sum,i-k,j-k,i+k+1,j+k+1);
					d=d+(a[i-k][j-k]+a[i+k+1][j-k]-a[i-k][j+k+1]-a[i+k+1][j+k+1])*(2*k+1);
					if (d!=0) continue;
					if (k+k+2>ans) ans=k+k+2;
				}
		cout<<"Case #"<<count_t<<": ";
		if (ans<0) cout<<"IMPOSSIBLE"<<endl;
		else cout<<ans<<endl;
	}
}