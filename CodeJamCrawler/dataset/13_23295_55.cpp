/*
 * A.cpp
 *
 *  Created on: Apr 12, 2013
 *      Author: Goodwine
 *       whut?: Random solution that is probably not what most
 *       		think of, bad IK, but I wanted it to be weird,
 *       		And I ended up condensing it at the end, when I
 *       		wanted it to be all spread out and look ugly :(
 */

#include<iostream>

using namespace std;

char checkChar(char * c, char l, int i);

int main() {
	int t, i, j, cc;
	int rw = 0, c = 1, d1 = 5, d2 = 6;
	char line[5], r;
	cin >> t;
	for (int _ = 1; _ <= t; _++) {
		char tracker[] = { 0, 0, 0, 0, 0, 0, 0 }; //rw,c1,c2,c3,c4,d1,d2
		r = 0;
		cc = 0;
		for (i = 0; i < 4; i++) {
			cin >> line;
			for (j = 0; j < 4 && r == 0; j++) {
				if (line[j] != '.')
					cc++;
				r = checkChar(&tracker[rw], line[j], j);
				if (r)
					break;
				r = checkChar(&tracker[c + j], line[j], i);
				if (r)
					break;
				if (i == j) {
					r = checkChar(&tracker[d1], line[j], i);
				} else if (3 - i == j) {
					r = checkChar(&tracker[d2], line[j], i);
				}
			}
		}
		cout << "Case #" << _ << ": ";
		if (r != 0) {
			cout << r << " won" << endl;
		} else if (cc == 16) {
			cout << "Draw" << endl;
		} else
			cout << "Game has not completed" << endl;
	}
	return 0;
}

char checkChar(char * c, char l, int i) {
	if (i == 0) {
		*c = l != '.' ? l : 0;
	} else if (*c == 0)
		return 0;
	else if (*c && l != 'T' && *c != l) {
		*c = 0;
	} else if (*c == 'T') {
		*c = l;
	}
	if (i == 3 && *c) {
		return *c;
	}
	return 0;
}
