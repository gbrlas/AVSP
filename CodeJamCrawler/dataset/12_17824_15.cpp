#include<stdio.h>


int main()
{
	char mapping[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	
	char c;
	int i, n;
	scanf("%d", &n);
	for(i=1 ; i <= n ; i++)
	{
		printf("Case #%d: ", i);
		scanf(" %c", &c);
		while((c >= 'a' && c <= 'z') || c == ' ')
		{
			/*if(s < 150)
				s++;
			else 
				break;*/
			if(c >= 'a' && c <= 'z')
				printf("%c", mapping[(int)(c-'a')]);
			else
				printf(" ");
				
			scanf("%c", &c);
		}
		
		printf("\n");
	}
	
	return 0;
}
