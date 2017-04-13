#include<stdio.h>

char s[5][5];

int main()
{
	int t,p;
	int i,j;
	char cc;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		for (i=0;i<4;i++)
			scanf("%s",s[i]);
		int s1=0;
		int s2=0;
		for (i=0;i<4;i++)
			for (j=0;j<4;j++)
			{
				if (s[i][j]=='X') s1++;
				if (s[i][j]=='O') s2++;
			}
		if (s1>s2) cc='X';
		else cc='O';
		bool flag=false;
		for (i=0;i<4;i++)
		{
			for (j=0;j<4;j++)
				if (s[i][j]!=cc&&s[i][j]!='T') break;
			if (j==4) flag=true;
		}
		for (i=0;i<4;i++)
		{
			for (j=0;j<4;j++)
				if (s[j][i]!=cc&&s[j][i]!='T') break;
			if (j==4) flag=true;
		}
		for (j=0;j<4;j++)
			if (s[j][j]!=cc&&s[j][j]!='T') break;
		if (j==4) flag=true;
		for (j=0;j<4;j++)
			if (s[j][3-j]!=cc&&s[j][3-j]!='T') break;
		if (j==4) flag=true;
		if (flag)
		{
			if (cc=='X') printf("Case #%d: X won\n",p);
			else printf("Case #%d: O won\n",p);
		}
		else
		{
			for (i=0;i<4;i++)
				for (j=0;j<4;j++)
					if (s[i][j]=='.') flag=true;
			if (!flag) printf("Case #%d: Draw\n",p);
			else printf("Case #%d: Game has not completed\n",p);
		}
	}
	return 0;
}

