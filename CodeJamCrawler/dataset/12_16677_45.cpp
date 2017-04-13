#include <cstdio>
#include <map>

int T;
char arr[100];
std::map<char, char> mapping;

int main () {

	mapping['a'] = 'y';
	mapping['b'] = 'h';
	mapping['c'] = 'e';
	mapping['d'] = 's';
	mapping['e'] = 'o';
	mapping['f'] = 'c';
	mapping['g'] = 'v';
	mapping['h'] = 'x';
	mapping['i'] = 'd';
	mapping['j'] = 'u';
	mapping['k'] = 'i';
	mapping['l'] = 'g';
	mapping['m'] = 'l';
	mapping['n'] = 'b';
	mapping['o'] = 'k';
	mapping['p'] = 'r';
	mapping['q'] = 'z';
	mapping['r'] = 't';
	mapping['s'] = 'n';
	mapping['t'] = 'w';
	mapping['u'] = 'j';
	mapping['v'] = 'p';
	mapping['w'] = 'f';
	mapping['x'] = 'm';
	mapping['y'] = 'a';
	mapping['z'] = 'q';

	scanf("%d", &T);
	getchar();
	getchar();
	for (int t = 1; t <= T; t++) {
		gets(arr);
		printf("Case #%d: ", t);
		for (int i = 0; i < 105; i++) {
			if (arr[i] == ' ')
				printf(" ");
			else {
				if (mapping[arr[i]] == 0)
					break;
				printf("%c", mapping[arr[i]]);
			}
		}
		printf("\n");
	}
}