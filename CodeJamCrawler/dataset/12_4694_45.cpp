#include<stdio.h>
#include<string.h>
#define max 2000000
bool vis[max];
int main()
{
	int T = 0;
	int t = 0;
	char mapping[130];
	char s[110];
	int i = 0;
	memcpy(&mapping['a'], "yhesocvxduiglbkrztnwjpfmaq", sizeof(char)*26);
	mapping[' '] = ' ';
	scanf("%d", &T);
	getchar();
	while(t++ < T)
	{
		gets(s);
		printf("Case #%d: ", t);
		for(i = 0; s[i] != '\0'; i++)
			putchar(mapping[s[i]]);
		printf("\n");
	}
	return 0;
}