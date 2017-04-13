#include <cstdio>
#include <cstring>

char name[111][111],str[111];
int f[1111][111];

int main()
{
	freopen("tt.txt","w",stdout);
	int T,s,q;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("\n%d\n",&s);
		memset(f,0,sizeof(f));
		for(int i=1;i<=s;++i) gets(name[i]);
		scanf("%d\n",&q);
		for(int i=1;i<=q;++i)
		{
			gets(str);
			int id=1;
			while(strcmp(str,name[id])!=0) ++id;
			for(int j=1;j<=s;++j)
			{
				f[i][j]=100000000;
				if(j==id) f[i][j]=-1;
				else
					for(int k=1;k<=s;++k)
						if(f[i-1][k]>-1)
							f[i][j]<?=f[i-1][k]+(j!=k);
			}
		}
		int ans=100000000;
		for(int i=1;i<=s;++i)
			if(f[q][i]>-1)
				ans<?=f[q][i];
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
