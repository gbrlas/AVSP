#include<stdio.h>
#include<string.h>

char s[501];
char ss[19];
int f[20];

int main()
{
	int t,p;
	int l;
	int i,j;
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	strcpy(ss,"welcome to code jam");
	scanf("%d",&t);
	gets(s);
	for (p=1;p<=t;p++)
	{
		gets(s);
		l=strlen(s);
		memset(f,0,sizeof(f));
		f[19]=1;
		for (j=l-1;j>=0;j--)
			for (i=0;i<19;i++)
				if (s[j]==ss[i]) f[i]=(f[i]+f[i+1])%10000;
		printf("Case #%d: ",p);
		if (f[0]<10) printf("000%d\n",f[0]);
		else if (f[0]<100) printf("00%d\n",f[0]);
		else if (f[0]<1000) printf("0%d\n",f[0]);
		else printf("%d\n",f[0]);
	}
	return 0;
}

