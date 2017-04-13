//abcdefghijklmnopqrstuvwxyz
//ynescwlbkuomxsevzpdrjgthap
#include <stdio.h>
#include <string.h>
void main()
{
	int t;
	char a[] = "yhesocvxduiglbkrztnwjpfmaq";
	char b[] = "abcdefghijklmnopqrstuvwxyz";
	char g[200];
	while (scanf("%d\n", &t) != EOF) {
		for (int i = 1; i <= t; i++) {
			gets(g);
			printf("Case #%d: ", i);
			for (int j = 0; g[j] != '\0'; j++) {
				if (g[j] <= 'z' && g[j] >= 'a') {
					for (int k = 0; k < 26; k++) {
						if (b[k] == g[j]) 
							printf("%c", a[k]);
					}
				}
				else 
					printf("%c", g[j]);
			}
			
			printf("\n");
		}
	}
}
