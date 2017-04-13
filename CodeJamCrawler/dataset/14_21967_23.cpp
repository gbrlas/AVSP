#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char a[100][101];

int solve(int n) {
	char str[100];
	int min[100];
	int max[100];
	int ret[100];

	for (int i = 0; i < 100; i++) {
		min[i] = 100;
		max[i] = 0;
		ret[i] = 10000;
	}

	int p = 0;
	str[0] = a[0][0];
	for (unsigned int i = 1; i < strlen(a[0]); i++)
		if (str[p] != a[0][i])
			str[++p] = a[0][i];

	int v;
	for (int i = 0; i < n; i++) {
		v = 0;
		unsigned int k = 0;
		int pp = 0;
		while (k < strlen(a[i])) {
			if (a[i][k] == str[pp])
				v++;
			else {
				if (pp < p && a[i][k] == str[pp+1]) {
					if (v == 0) {
						return -1;
					}
					if (min[pp] > v)
						min[pp] = v;
					if (max[pp] < v)
						max[pp] = v;
					v = 1;
					pp++;
				} else
					return -1;
			}
			k++;
		}
		if (pp != p)
			return -1;
		if (min[pp] > v)
			min[pp] = v;
		if (max[pp] < v)
			max[pp] = v;
	}

	for (int i = 0; i <= p; i++) {
		v = 0;
		for (int j = min[i]; j <= max[i]; j++) {
			for (int l = 0; l < n; l++) {
				int k = 0;
				unsigned int pp = 0;
				if (i)
					pp++;
				while (pp < strlen(a[l]) && k < i) {
					if (a[l][pp] != a[l][pp-1])
						k++;
					pp++;
				}
				if (pp)
					pp--;
				int r = 1;
				for (unsigned int ii = pp; ii < strlen(a[l]) - 1; ii++) {
					if (a[l][ii] == a[l][ii+1])
						r++;
					else
						break;
				}
				if (r > j)
					v += r - j;
				else
					v += j - r;
			}
			if (ret[i] > v)
				ret[i] = v;

			v = 0;
		}
	}

	int val = 0;

	for (int i = 0; i <= p; i++)
		val += ret[i];

	return val;
}

int main() {
  FILE* in = fopen("A-small-attempt1.in", "r");
  FILE* out = fopen("A-small-attempt1.out", "w");
  int tests;
  fscanf(in, "%d", &tests);
  for (int i = 1; i <= tests; i++) {
	  int n;
	  fscanf(in, "%d", &n);
	  for (int j = 0; j < n; j++) {
		  fscanf(in, "%s", a[j]);
	  }
	  fprintf(out, "Case #%d: ", i);
	  int val = solve(n);
	  if (val < 0)
		  fprintf(out, "Fegla Won\n");
	  else
		  fprintf(out, "%d\n", val);
  }
  
  fclose(in);
  fclose(out);
  
  return 0;
}
