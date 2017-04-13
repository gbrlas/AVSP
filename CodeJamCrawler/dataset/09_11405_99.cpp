#include <iostream>
#include <cstdio>
using namespace std;
bool is[20][500];
char a[5005][20];
char p[100000000];
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("Aout.txt","wt",stdout);
	int l,n,d,i,j,k,m;
	scanf("%d %d %d ",&l,&d,&n);
	for(i=0;i<d;i++)
		gets(a[i]);
	p[0] = ')';
	for(k=0;k<n;++k)
	{
		gets(p+1);
		m = (int)strlen(p);
		memset(is,0,sizeof(is) );
		j = 0;
		for(i=1;i<m;i++)
		{
			if(p[i]=='(' )
				while(p[i]!=')')
					is[j][p[i++]] = 1;
			else is[j][p[i]] = 1;
			j++;
		}
		int ans = 0;
		for(i=0;i<d;i++)
		{
			for(j=0;j<l;j++)
				if(!is[j][a[i][j]])
					break;
			if(j<l) continue;
			ans++;
		}
		printf("Case #%d: %d\n",k+1,ans);
	}
	return 0;
}