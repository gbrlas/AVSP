#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char kal[105];

int main()
{
	
	int kamus[]= {24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 19, 13, 22, 9, 15, 5, 12, 0, 16};
	int t;
	scanf("%d\n",&t);
	for(int it=0;it<t;it++)
	{
		gets(kal);
		int p = strlen(kal);
		printf("Case #%d: ",it+1);
		for(int i=0;i<p;i++)
		{
			if(kal[i]==' ')printf(" ");
			else printf("%c",kamus[kal[i]-'a']+'a');
		}
		puts("");
	}
	
	//system("pause");
	return 0;
}
