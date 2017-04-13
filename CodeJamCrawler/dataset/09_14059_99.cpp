#include<stdio.h>
#include<string.h>
#include<ctype.h>
int l,d,n;
char s[6000][20],tmp[1100];
int equal(char*s1,char*s2)
{
	char *p=s2;
	int i=0;
	while (*p)
	{
		if (isalpha(*p))
		{
			if (*p!=s1[i])
			{
				return 0;
			}
			i++;
			p++;
		}
		else if (*p=='(')
		{
			char q[30]={0},*tt=p+1;
			p++;
			int tl=0;
			while (*p!=')')
			{
				++tl;
				++p;
			}
			strncpy(q,tt,tl);
			if (!strchr(q,s1[i]))
			{
				return 0;
			}
			i++;
			p++;
		}
	}
	return 1;
}
int main()
{
	int i,j,k,cas=0;
	scanf("%d%d%d",&l,&d,&n);
	for (i=0;i<d;i++)
	{
		scanf("%s",s[i]);
	}
	while (n--)
	{
		scanf("%s",tmp);
		int ans=0;
		if (!strchr(tmp,'('))
		{
			for (i=0;i<d;i++)
			{
				if (strcmp(s[i],tmp)==0)
				{
					++ans;
				}
			}
		}
		else 
		{
			for (i=0;i<d;i++)
			{
				if (equal(s[i],tmp))
				{
					++ans;
				}
			}
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
}
