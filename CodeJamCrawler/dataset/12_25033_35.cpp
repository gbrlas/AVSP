#include<cstdio>
#include<cstring>
char a[27]={' ','y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
	int t;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("haha.out","w",stdout);
	scanf("%d",&t);
	char c;
	c=getchar();
	for(int cas=1;cas<=t;cas++)
	{
		printf("Case #%d: ",cas);
		//scanf("%s",s);
		while(c=getchar(),c!='\n')
		if(c>='a'&&c<='z')
				printf("%c",a[c-'a'+1]);
		else printf(" ");
		if(i<cas)printf("\n");
	}
	return 0;
}
