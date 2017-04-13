#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

char result[256];
char temp[1000];

int main()
{
	int T = 0, TC;
	result[' '] = ' ';
	result['a'] = 'y';
	result['b'] = 'h';
	result['c'] = 'e';
	result['d'] = 's';
	result['e'] = 'o';
	result['f'] = 'c';
	result['g'] = 'v';
	result['h'] = 'x';
	result['i'] = 'd';
	result['j'] = 'u';
	result['k'] = 'i';
	result['l'] = 'g';
	result['m'] = 'l';
	result['n'] = 'b';
	result['o'] = 'k';
	result['p'] = 'r';
	result['q'] = 'z';
	result['r'] = 't';
	result['s'] = 'n';
	result['t'] = 'w';
	result['u'] = 'j';
	result['v'] = 'p';
	result['w'] = 'f';
	result['x'] = 'm';
	result['y'] = 'a';
	result['z'] = 'q';
	scanf("%d", &TC); gets(temp);
	while (T++ < TC) {
		gets(temp);
		for (int i = 0, len = strlen(temp); i < len; i++) {
			temp[i] = result[temp[i]];
		}
		printf("Case #%d: %s\n", T, temp);
	}
	return 0;
}

