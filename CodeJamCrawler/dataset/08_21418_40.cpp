#include<cstdio>
#include<vector>
using namespace std;

vector<long long>X,Y;
long long f[3][3];

void zeruj(long long t[3][3])
{
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++) t[i][j]=0;
}

int t[9][2];
long long ile[9];

bool ok (int a, int b, int c)
{
    return (t[a][0]+t[b][0]+t[c][0])%3==0 && (t[a][1]+t[b][1]+t[c][1])%3==0;
}

main()
{
    int cs=0;
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    {t[3*i+j][0]=i; t[3*i+j][1]=j;}
    long long t,n,a,b,c,d,x,y,m;
    scanf("%lld",&t);
    while(t--)
    {
	X.clear(); Y.clear();
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld\n",&n,&a,&b,&c,&d,&x,&y,&m);
        X.push_back(x); Y.push_back(y);
	for(int i=1; i<=n-1; i++)
        {
    	    x=(a*x+b)%m;
	    y=(c*y+d)%m;
	    X.push_back(x);
	    Y.push_back(y);
	}
	zeruj(f);
	for(int i=0; i<9; i++) ile[i]=0;
	for(int i=0; i<n; i++)
	{
	    int a=X[i]%3, b=Y[i]%3;
	    ile[3*a+b]++;
	}
	long long res=0;
	for(int a=0; a<9; a++)
	for(int b=a+1; b<9; b++)
	for(int c=b+1; c<9; c++)
	if(ok(a,b,c)) res+=ile[a]*ile[b]*ile[c];

	for(int a=0; a<9; a++)
	for(int b=a+1; b<9; b++)
	{
	     if(ok(a,b,b)) res+=(ile[b]*(ile[b]-1))/2 * ile[a];
	     if(ok(a,a,b)) res+=(ile[a]*(ile[a]-1))/2 * ile[b];
	}
	
	for(int a=0; a<9; a++)
	{
	    if(ok(a,a,a)) res+= ile[a]*(ile[a]-1)*(ile[a]-2)/6;
	}
	printf("Case #%d: %lld\n",++cs,res);
    }
}
