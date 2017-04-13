//A 65 a 97

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char abc[28]={'y','h','e','s','o','c','v','x','d','u','i','g','l',
				  'b','k','r','z','t','n','w','j','p','f','m','a','q'};
	char frase[150];
	int cant,i,j,tope;
	scanf("%d",&cant);
	getc(stdin);
	for(i=0;i<cant;i++)
	{
		gets(frase);
		tope=strlen(frase);
		printf("Case #%d: ",i+1);
		for(j=0;j<tope;j++)
		{
			if(frase[j]==' ')
				printf(" ");
			else
				printf("%c",abc[frase[j]-97]);
		}
		if(i!=cant-1)
			printf("\n");
	}
	return 0;
}