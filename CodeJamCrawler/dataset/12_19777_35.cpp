#include <cstdio>
char map[26] = { 121, 104, 101, 115, 111, 99, 118, 120, 100, 117, 105, 103, 108, 98, 107, 114, 122, 116, 110, 119, 106, 112, 102, 109, 97, 113};

char S[200];
inline void solve(int tc) {
	gets(S);
	printf("Case #%d: ", tc);
	for (int i = 0; S[i]; i++)
		if (S[i] != ' ')
			printf("%c", map[(int)(S[i] - 'a')]);
		else
			printf(" ");
	puts("");
}

int main() {
	int T;
	sscanf(gets(S), "%d", &T);
	for (int i = 1; i <= T; i++) solve(i);
	return 0;
}
