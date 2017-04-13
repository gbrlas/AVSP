#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<memory.h>
#define N 210
using namespace std;

char s[N];
char a[N]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	
int main()
{
	int t,cas=1;
	int i,j,len;
	char c='a';
	freopen("re.txt","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{	
		printf("Case #%d: ",cas++);	
		while(c!='\n')
		{
			scanf("%s",&s);
			len=strlen(s);
			for(i=0;i<len;i++)
			printf("%c",a[s[i]-'a']);
			printf(" ");
			c=getchar();
		}
		c='a';
		printf("\n");
	}
	return 0;
}
		
