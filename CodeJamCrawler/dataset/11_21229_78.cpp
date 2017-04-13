#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

#define N 555
char a[N][N];
int s[N][N];
int sx[N][N];
int sy[N][N];

int main()
{
	freopen("b1.in","r",stdin);
	freopen("b1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		int n,m,i,j,k;
		scanf("%d%d%*d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%s",a[i]+1);
			for(j=1;j<=m;j++)
			{
				a[i][j]-='0';
				s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
				sx[i][j]=i*a[i][j]+sx[i-1][j]+sx[i][j-1]-sx[i-1][j-1];
				sy[i][j]=j*a[i][j]+sy[i-1][j]+sy[i][j-1]-sy[i-1][j-1];
			}
		}
		int ans=0;
		for(k=min(n,m);k>=3 && !ans;k--)
		{
			for(i=0;i<=n-k && !ans;i++)
				for(j=0;j<=m-k && !ans;j++)
					if( 2*(sx[i+k][j+k]-sx[i][j+k]-sx[i+k][j]+sx[i][j])-
						(2*i+k+1)*(s[i+k][j+k]-s[i][j+k]-s[i+k][j]+s[i][j])==
						(1-k)*(a[i+1][j+1]+a[i+1][j+k]-a[i+k][j+1]-a[i+k][j+k]) &&
						2*(sy[i+k][j+k]-sy[i][j+k]-sy[i+k][j]+sy[i][j])-
						(2*j+k+1)*(s[i+k][j+k]-s[i][j+k]-s[i+k][j]+s[i][j])==
						(1-k)*(a[i+1][j+1]-a[i+1][j+k]+a[i+k][j+1]-a[i+k][j+k]) )
					{
						/*printf("\n");
						for(int x=i+1;x<=i+k;x++,printf("\n"))
							for(int y=j+1;y<=j+k;y++)
								printf("%d",int(a[x][y]));*/
						ans=k;
					}
		}
		if(!ans) puts("IMPOSSIBLE"); else printf("%d\n",ans);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
