/*
 * A.c
 *
 *  Created on: Apr 13, 2012
 *      Author: goodwine
 */

#include<stdio.h>

char c[256];

int main() {
	c['a'] = 'y';
	c['b'] = 'h';
	c['c'] = 'e';
	c['d'] = 's';
	c['e'] = 'o';
	c['f'] = 'c';
	c['g'] = 'v';
	c['h'] = 'x';
	c['i'] = 'd';
	c['j'] = 'u';
	c['k'] = 'i';
	c['l'] = 'g';
	c['m'] = 'l';
	c['n'] = 'b';
	c['o'] = 'k';
	c['p'] = 'r';
	c['q'] = 'z';
	c['r'] = 't';
	c['s'] = 'n';
	c['t'] = 'w';
	c['u'] = 'j';
	c['v'] = 'p';
	c['w'] = 'f';
	c['x'] = 'm';
	c['y'] = 'a';
	c['z'] = 'q';
	c[' '] = ' ';
	c['\n'] = '\n';
	c[0] = 0;
	int _;
	int __;
	int i;
	char str[200];
	scanf("%i ", &_);
	for (__ = 1; __ <= _; __++) {
		fgets(str, 200, stdin);
		for (i = 0; str[i] != 0; i++) {
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = c[(int)str[i]];
		}
		printf("Case #%i: %s", __, str);
	}
	return 0;
}
