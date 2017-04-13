#include<cstdio>
#include<algorithm>
using namespace std;

int X0,Y0,X,Y,X2,Y2;
int n,m,a;
void go()
{
    for(int x1=0; x1<=n; x1++)
    for(int y1=0; y1<=m; y1++)
    for(int x2=0; x2<=n; x2++)
    for(int y2=0; y2<=m; y2++)
    {
	if(abs(x1*y2-x2*y1)==a) {X=x1;Y=y1;Y2=y2;X2=x2; return;}
    }
}

main()
{
    int c;
    scanf("%d",&c);
    for(int cs=1; cs<=c; cs++)
    {
	scanf("%d %d %d",&n,&m,&a);
	X=-1;
	X0=Y0=0;
	go();
	printf("Case #%d: ",cs);
	if(X==-1) printf("IMPOSSIBLE\n",n,m,a);
	else printf("%d %d %d %d %d %d\n",X0,Y0,X,Y,X2,Y2);
    }
}