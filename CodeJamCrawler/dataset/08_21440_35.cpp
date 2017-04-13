#include<cstdio>
using namespace std;

const int mod=10007;
int d[103][103];
bool rock[103][103];
int w,h;
int f(int i, int j)
{
    if(i>h || j>w) return 0;
    return d[i][j];
}

main()
{
    int n,r,a,b;
    scanf("%d",&n);
    for(int test=1;test<=n;test++)
    {
	scanf("%d %d %d",&h,&w,&r);
	for(int i=0; i<h; i++) for(int j=0; j<w; j++) rock[i][j]=false;
	while(r--)
	{
	    scanf("%d %d",&a,&b); a--; b--;
	    rock[a][b]=true;
	}
	h--; w--;
	d[h][w]=1;
	for(int i=h; i>=0; i--)
	for(int j=0; j<=w; j++)
	if(i!=h || j!=w)
	{
	    if(rock[i][j]) d[i][j]=0;
	    else d[i][j]=(f(i+1,j+2)+f(i+2,j+1))%mod;
	}
	printf("Case #%d: %d\n",test,d[0][0]);
    }
}
