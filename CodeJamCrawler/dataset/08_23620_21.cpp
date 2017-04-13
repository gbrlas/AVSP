#define _CRT_SECURE_NO_WARNINGS
/*
#ifdef SPOJ
#define SCANF(s1,s2) scanf(s1, s2)
#define SCANF2(s1,s2,s3) scanf(s1, s2, s3)
#define SCANF3(s1,s2,s3,s4) scanf(s1, s2, s3, s4)
#define SCANF4(s1,s2,s3,s4,s5) scanf(s1, s2, s3, s4, s5)
#define SCANF5(s1,s2,s3,s4,s5, s6) scanf(s1, s2, s3, s4, s5, s6)
#define GETS(s1) gets(s1)
#else
#define SCANF(s1,s2) fscanf(in, s1, s2)
#define SCANF2(s1,s2,s3) fscanf(in, s1, s2, s3)
#define SCANF3(s1,s2,s3,s4) fscanf(in, s1, s2, s3, s4)
#define SCANF4(s1,s2,s3,s4,s5) fscanf(in, s1, s2, s3, s4, s5)
#define SCANF5(s1,s2,s3,s4,s5, s6) fscanf(in, s1, s2, s3, s4, s5, s6)
#define GETS(s1) fgets(s1, 1000000, in)
#endif
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<list>
#include<deque>
#include<vector>
#include<algorithm>
#include<queue>
#include<time.h>
#include<map>
#include<set>
//#include<iterator>

using namespace std;

char buffer [20];
int r, c;

int hit [2000000];
bool res [2000000];
int expIn, expOut, tCase;

bool win (int b, int kr, int kc) {
	int bAux = b + kr * (1 << 16) + kc * (1 << 18);
	if (hit [bAux] == tCase)
		return res [bAux];
	bool result = false;
	b |= 1 << (4 * kr + kc);
	if (!result && kr > 0 && kc > 0 && !(b & (1 << (4 * (kr - 1) + (kc - 1))))) {
		if (!win (b, kr - 1, kc - 1))
			result = true;
	}
	if (!result && kr > 0 && !(b & (1 << (4 * (kr - 1) + (kc))))) {
		if (!win (b, kr - 1, kc))
			result = true;
	}
	if (!result && kr > 0 && kc < c - 1 && !(b & (1 << (4 * (kr - 1) + (kc + 1))))) {
		if (!win (b, kr - 1, kc + 1))
			result = true;
	}
	if (!result && kc > 0 && !(b & (1 << (4 * (kr) + (kc - 1))))) {
		if (!win (b, kr, kc - 1))
			result = true;
	}
	if (!result && kc < c - 1 && !(b & (1 << (4 * (kr) + (kc + 1))))) {
		if (!win (b, kr, kc + 1))
			result = true;
	}
	if (!result && kr < r - 1 && kc > 0 && !(b & (1 << (4 * (kr + 1) + (kc - 1))))) {
		if (!win (b, kr + 1, kc - 1))
			result = true;
	}
	if (!result && kr < r - 1 && !(b & (1 << (4 * (kr + 1) + (kc))))) {
		if (!win (b, kr + 1, kc))
			result = true;
	}
	if (!result && kr < r - 1 && kc < c - 1 && !(b & (1 << (4 * (kr + 1) + (kc + 1))))) {
		if (!win (b, kr + 1, kc + 1))
			result = true;
	}
	hit [bAux] = tCase;
	res [bAux] = result;
	return result;
}

int main (void) {
	FILE *in, *out;
	in = fopen ("test.in", "r");
	out = fopen ("test.out", "w");
	int n, i, j, b, sr, sc;
	fscanf (in, "%d", &n);
	for (tCase = 1; tCase <= n; tCase++) {
		fscanf (in, "%d %d", &r, &c);
		b = 0;
		for (i = 0; i < r; i++) {
			fscanf (in, "%s", buffer);
			for (j = 0; j < c; j++) {
				if (buffer [j] == 'K') {
					sr = i;
					sc = j;
				}
				else if (buffer [j] == '#')
					b |= 1 << (4 * i + j);
			}
		}
		if (win (b, sr, sc))
			fprintf (out, "Case #%d: A\n", tCase);
		else
			fprintf (out, "Case #%d: B\n", tCase);
	}
}



