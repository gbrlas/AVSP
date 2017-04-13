#include <stdio.h>

static char f[32];

void discover () {
	char *q[3][2];
	int got[32] = {0};
	q[0][0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	q[1][0] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	q[2][0] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	q[0][1] = "our language is impossible to understand";
	q[1][1] = "there are twenty six factorial possibilities";
	q[2][1] = "so it is okay if you want to just give up";
	int i, j;
	for (i = 0; i != 3; ++i) 
		for(j = 0; q[i][0][j]; ++j) 
			if (q[i][0][j] != ' ') {
				f[q[i][0][j]-'a'] = q[i][1][j];
				got[q[i][1][j]-'a'] = 1;
			}
/*	for(i = 0; i != 26; i++)
		if (!got[i]) printf("%d:[%c]\n", i, i+'a');
*/		
	f['z'-'a'] = 'q';
	f['q'-'a'] = 'z';
}

int main (void) {
	char str[127], ans[127];
	int i, n, j;
	discover();
	scanf("%d", &n);
	for (i = 0; i != n; i++) {
		scanf(" %[^\n]", str);
		for (j = 0; str[j]; ++j) {
			if (str[j] == ' ') ans[j] = str[j];
			else ans[j] = f[str[j]-'a'];
		}
		ans[j] = '\0';
		printf("Case #%d: %s\n", i+1, ans);
	}
	return 0;
}
