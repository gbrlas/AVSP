#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;
int TC;
char buf[10000];
char M[300];

int main(int argc, char *argv[])
{
	M['a'] = 'y';
	M['b'] = 'h';
	M['c'] = 'e';
	M['d'] = 's';
	M['e'] = 'o';
	M['f'] = 'c';
	M['g'] = 'v';
	M['h'] = 'x';
	M['i'] = 'd';
	M['j'] = 'u';
	M['k'] = 'i';
	M['l'] = 'g';
	M['m'] = 'l';
	M['n'] = 'b';
	M['o'] = 'k';
	M['p'] = 'r';
	M['q'] = 'z';
	M['r'] = 't';
	M['s'] = 'n';
	M['t'] = 'w';
	M['u'] = 'j';
	M['v'] = 'p';
	M['w'] = 'f';
	M['x'] = 'm';
	M['y'] = 'a';
	M['z'] = 'q';
	fgets(buf, sizeof buf, stdin);
	sscanf(buf, "%d", &TC);
	for (int t = 1; t <= TC; t++) {
		fgets(buf, sizeof buf, stdin);
		buf[strlen(buf)-1] = 0;
		printf("Case #%d: ", t);
		for (int i = 0; buf[i]; i++) {
			if (isalpha(buf[i])) {
				putchar(M[buf[i]]);
			} else
				putchar(buf[i]);
		}
		putchar('\n');
	}
	return 0;
}
