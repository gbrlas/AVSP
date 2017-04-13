#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const char f[] = "yhesocvxduiglbkrztnwjpfmaq";

char s[110];

int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("a.out", "w", stdout);

/*	char f[27];
	memset(f, 0, sizeof(f));
	f['y' - 'a'] = 'a';
	f['e' - 'a'] = 'o';
	f['q' - 'a'] = 'z';

	char s[100], t[100];
	for (int T = 0; T < 3; ++T) {
		gets(s);
		gets(t);
		for (int i = 0; i < strlen(s); ++i) {
			if (t[i] == ' ') continue;
			if (f[s[i] - 'a'] == 0) f[s[i] - 'a'] = t[i];
			else if (f[s[i] - 'a'] != t[i]) puts("!!");
		}
	}

	printf("%s\n", f);*/

	int T;
	scanf("%d", &T);
	gets(s);
	for (int nCase = 1; nCase <= T; ++nCase) {
		gets(s);
		int n = strlen(s);
		for (int i = 0; i < n; ++i)
			if (s[i] != ' ') s[i] = f[s[i] - 'a'];
		printf("Case #%d: %s\n", nCase, s);
	}

	return 0;
}

