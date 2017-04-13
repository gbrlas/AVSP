#include<cstdio>
#include<algorithm>
using namespace std;

char p[81][81];
bool d[81][81],kolor[81][81];
int skoj[81][81];
int n,m;

bool go(int i, int j)
{
//	    printf("%d %d\n",i,j);
    if(kolor[i][j]==false) return false;
    kolor[i][j]=false;
    for(int a=max(0,i-1); a<=min(n-1,i+1); a++)
    {
	if(j-1>=0)
	{
    	    if(p[a][j-1]=='.' && (skoj[a][j-1]==-1 || go(skoj[a][j-1]/m, skoj[a][j-1]%m)))
	    {
		d[i][j]=false;
		skoj[a][j-1]=i*m+j;
		return true;
	    }
	}
	if(j+1<m)
	{
    	    if(p[a][j+1]=='.' && (skoj[a][j+1]==-1 || go(skoj[a][j+1]/m, skoj[a][j+1]%m)))
	    {
		d[i][j]=false;
		skoj[a][j+1]=i*m+j;
		return true;
	    }
	}
    }
    return false;
}

bool sciezka()
{
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) kolor[i][j]=true;
    
    for(int j=0; j<m; j+=2)
    for(int i=0; i<n; i++)
    if(d[i][j] && kolor[i][j])
    {
	if(go(i,j)) return true;
    }
    return false;
}

main()
{
    int c;
    scanf("%d",&c);
    for(int test=1; test<=c; test++)
    {
	int res=0;
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++) scanf("%s",&p[i]);
	
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
	    if(p[i][j]=='.') {d[i][j]=true; res++;}
	    else d[i][j]=false;
	    skoj[i][j]=-1;
	}
	
	while(sciezka())res--;
	
	printf("Case #%d: %d\n",test,res);
    }
}
