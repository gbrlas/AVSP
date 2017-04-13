#include <cstdio>

char tr[]="yhesocvxduiglbkrztnwjpfmaq";
char str[255];
int main()
{
	int T;
	scanf("%d",&T);
	gets(str);
	for(int test=1;test<=T;test++)
	{
		gets(str);
		printf("Case #%d: ",test);
		for(int i=0;str[i];i++)
			if(str[i]==' ')
				putchar(' ');
			else 
				putchar(tr[str[i]-'a']);
		puts("");
	}
}
