#include<stdio.h>
#include<string.h>
int main()
{
	int n6,n5=1;
	scanf("%d%*c",&n6);
	while(n5<=n6)
	{
		char ch[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
		char c='s';
		printf("Case #%d: ",n5);
		scanf("%c",&c);
		while(c!='\n')
		{
			if(c!=' ')
			{
				printf("%c",ch[c-97]);
			}
			else
			{
				printf(" ");
			}
			scanf("%c",&c);
		}
		printf("\n");
		n5++;
	}
	return 0;
}
