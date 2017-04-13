#include<stdio.h>
#include<string.h>

int a[26]={24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
char s[200];

int main()
{
	int t,p;
	int i,l;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	gets(s);
	for (p=1;p<=t;p++)
	{
		gets(s);
		l=strlen(s);
		printf("Case #%d: ",p);
		for (i=0;i<l;i++)
			if (s[i]==' ') printf(" ");
			else printf("%c",a[s[i]-'a']+'a');
		printf("\n");
	}
	return 0;
}
