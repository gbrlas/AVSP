#include <stdio.h>
#include <string.h>

char map[1000] = {"yhesocvxduiglbkrztnwjpfmaq"};

int main()
{
	int i, T;
	int j, len;
	char str[1000];	
	
	freopen("a.txt", "r", stdin);
	freopen("a_out.txt", "w", stdout);

	scanf("%d\n", &T);

	for (i = 1; i <= T; i++) {
		gets(str);
		len = strlen(str);
		for (j = 0; j < len; j++) {
			if (str[j] >= 'a' && str[j] <= 'z') {
				str[j] = map[str[j] - 'a'];
			}
		}
		printf("Case #%d: %s\n", i, str);
	}
	return 0;
}
