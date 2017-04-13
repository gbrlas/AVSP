#include<stdio.h>
#include<string.h>
char s[501],t[20]="welcome to code jam";
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	gets(s);
	for(int x=1;x<=n;x++)
	{
		gets(s);
		static int d[501][20];
		memset(d,0,sizeof(d));
		d[0][0]=1;
		for(int i=0;s[i];i++)for(int j=0;j<19;j++)if(d[i][j])
		{
			d[i+1][j]=(d[i+1][j]+d[i][j])%10000;
			if(s[i]==t[j])d[i+1][j+1]=d[i][j];
		}

		int z=0;
		for(int i=0;s[i];i++)z=(z+d[i+1][19])%10000;
		printf("Case #%d: %04d\n",x,z);
	}
}
