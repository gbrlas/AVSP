#include <cstdio>
char s[111], t[30] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int main() {
	int testnum;
	scanf("%d", &testnum); gets(s);
	
	for (int test = 1; test <= testnum; test++) {
		gets(s);
		printf("Case #%d: ", test);
		for (int i = 0; s[i]; i++)
			if (s[i] == ' ') putchar(' ');
			else putchar(t[s[i] - 'a']);
		puts("");
	}
	return 0;
}