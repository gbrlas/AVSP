#include <cstdio>
char a[30] = {"yhesocvxduiglbkr tnwjpfma "};
char s[111];

int main() {
	freopen("ans_for_A.txt", "w", stdout);
	int task; scanf("%d ", &task);
	a['q' - 'a'] = 'z';
	a['z' - 'a'] = 'q';
	for (int cas = 1; cas <= task; ++cas){ 
		gets(s);
		printf("Case #%d: ",cas);
		for (int i = 0; s[i]; ++i) if (s[i] != ' ')
			putchar(a[s[i] - 'a']); else putchar(' ');
		puts("");
	}
}
