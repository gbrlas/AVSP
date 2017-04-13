#include <cstdio>
#include <vector>

const int MAXN = 1010;

__int64 x[100100],y[100100];
__int64 num[3][3];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t,it;
	scanf("%d",&t);
	for (it=0;it<t;it++)
	{		
		int n;
		__int64 a,b,c,d,xx,yy,m;
		scanf("%d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&c,&d,&xx,&yy,&m);
		x[0]=xx;
		y[0]=yy;
		for (int i=1;i<n;i++)
		{
			xx=(a*xx+b)%m;
			yy=(c*yy+d)%m;
			x[i]=xx;
			y[i]=yy;
		}

		/*scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d%d",&x[i],&y[i]);*/

		memset(num,0,sizeof(num));
		for (int i=0;i<n;i++)
			num[x[i]%3][y[i]%3]++;
		__int64 ans=0;
		for (int i=0;i<9;i++)
			for (int j=i+1;j<9;j++)
				for (int k=j+1;k<9;k++)
				{
					if ((i/3+j/3+k/3)%3==0 && (i%3+j%3+k%3)%3==0)
						ans+=num[i/3][i%3]*num[j/3][j%3]*num[k/3][k%3];
				}
		for (int i=0;i<9;i++)
			if (num[i/3][i%3]>2)
				ans+=num[i/3][i%3]*(num[i/3][i%3]-1)*(num[i/3][i%3]-2)/6;
		printf("Case #%d: %d\n",it+1,ans);
	}
	return 0;
}