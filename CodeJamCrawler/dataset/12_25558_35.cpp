#include <stdio.h>
#include <string.h>
int main() {
	char sa[3][100] = {
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv",
	};
	char sb[3][100] = {
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up",
	};

	int map[26];
	for (int i = 0; i < 26; i++)
		map[i] = -1;

	for (int i = 0; i < 3; i++) {
		int len = strlen(sa[i]);
		for (int j = 0; j < len; j++) {
			int ta = sa[i][j] - 'a';
			int tb = sb[i][j] - 'a';
			map[ta] = tb;
		}
	}
/*
	for (int i = 0; i < 26; i++) {
		printf("%d\t%c", i, i+'a');
		if (map[i] != -1)
			printf("\t%c\t%d", map[i]+'a', map[i]);
		printf("\n");
	}

	for (int i = 0; i < 26; i++) {
		bool found = false;
		for (int j = 0; j < 26; j++)
			if (map[j] == i)
				found = true;
		if (found == false)
			printf("miss %d\n", i);
	}
*/	

	map[16] = 25;
	map[25] = 16;

	int ecase;
	char input[1000];
	
	scanf("%d", &ecase);
	gets(input);

	for (int ecount = 1; ecount <= ecase; ecount++) {
		gets(input);
		int len = strlen(input);
		printf("Case #%d: ", ecount);
		for (int i = 0; i < len; i++) {
			if ('a' <= input[i] && input[i] <= 'z')
				printf("%c", map[ input[i] - 'a' ] + 'a');
			else
				printf("%c", input[i]);
		}
		printf("\n");
	}

	return 0;
}
