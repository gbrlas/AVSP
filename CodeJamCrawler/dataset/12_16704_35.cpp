#include<stdio.h>

int main()
{
	int t,cnt=1,i;
	char arr[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	char input[110];

	scanf("%d\n",&t);
		
	while(t--)
	{
		gets(input);
		for(i=0; input[i] != '\0';i++)
		{
			if(input[i] >= 97 && input[i] <= 122)
				input[i] = arr[(int)input[i] - 97];
		}
		
		printf("Case #%d: %s\n",cnt,input);
		cnt++;
	}

	return 0;
}