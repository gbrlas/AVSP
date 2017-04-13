#include <iostream>
#include <cstdio>
#include <cstring>

#define SIZE 1000

using namespace std;

int T;
char map[SIZE];

int main(int argc, char *argv[]) {
	int I;
	char aux;
	
	memset(map, '?', sizeof(char) * SIZE);
	map['y'] = 'a';
	map['n'] = 'b';
	map['f'] = 'c';
	map['i'] = 'd';
	map['c'] = 'e';
	map['w'] = 'f';
	map['l'] = 'g';
	map['b'] = 'h';
	map['k'] = 'i';
	map['u'] = 'j';
	map['o'] = 'k';
	map['m'] = 'l';
	map['x'] = 'm';
	map['s'] = 'n';
	map['e'] = 'o';
	map['v'] = 'p';
	map['z'] = 'q';
	map['p'] = 'r';
	map['d'] = 's';
	map['r'] = 't';
	map['j'] = 'u';
	map['g'] = 'v';
	map['t'] = 'w';
	map['h'] = 'x';
	map['a'] = 'y';
	map['q'] = 'z';
	
	scanf("%d", &T);
	scanf("%c", &aux); // for the \n of the first line
	for (I = 1; I <= T; ++I) {
		printf("Case #%d: ", I);
		
		do {
			scanf("%c", &aux);
			if (aux == ' ')
				printf(" ");
			else if (aux != '\n')
				printf("%c", map[(int) aux]);
		} while (aux != '\n');
		printf("\n");
	}
	
	return 0;
}
