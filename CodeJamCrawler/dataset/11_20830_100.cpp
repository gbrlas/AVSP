#include<stdio.h>

char s1[40][4];
char s2[40][4];
char s[200];

int main()
{
	int t,p;
	int n,m;
	int i,j;
	int tt,pp;
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&m);
		for (i=1;i<=m;i++)
			scanf("%s",s1[i]);
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%s",s2[i]);
		scanf("%d",&tt);
		scanf("%s",s);
		for (pp=1;pp<tt;pp++)
		{
			for (i=1;i<=m;i++)
				if ((s1[i][0]==s[pp-1]&&s1[i][1]==s[pp])||(s1[i][0]==s[pp]&&s1[i][1]==s[pp-1])) break;
			if (i<=m)
			{
				s[pp]=s1[i][2];
				s[pp-1]=' ';
				continue;
			}
			bool flag=false;
			for (j=pp-1;j>=0&&s[j]!='a';j--)
			{
				for (i=1;i<=n;i++)
					if ((s2[i][0]==s[j]&&s2[i][1]==s[pp])||(s2[i][0]==s[pp]&&s2[i][1]==s[j])) 
					{
						flag=true;
						break;
					}
				if (i<=n) break;
			}
			if (flag) s[pp]='a';
		}
		for (pp=tt-1;pp>=0;pp--)
			if (s[pp]=='a') break;
		printf("Case #%d: [",p);
		for (pp=pp+1;pp<tt-1;pp++)
			if (s[pp]!=' ') printf("%c, ",s[pp]);
		if (pp==tt-1) printf("%c]\n",s[pp]);
		else printf("]\n");
	}
	return 0;
}
