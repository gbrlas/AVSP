#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <functional>
#include <ctype.h>
#include <numeric>
#include <sstream>
#include <queue>

using namespace std;

#define MAX_L 16
#define MAX_D 5000

int L, D, N;

char words[MAX_D][MAX_L];
bool pattern[MAX_L][26];
char p[MAX_L * 26] = { 0 };

int main ()
{
	scanf("%d %d %d", &L, &D, &N);

	for (int i = 0; i < D; i++) {
		scanf ("%s", words[i]);
		for (int j = 0; j < L; j++) {
			words[i][j] -= 'a';
		}
	}

	for (int c = 0; c < N; c++) {
		int res = 0;
		memset (pattern, 0, sizeof(pattern));
		scanf ("%s", p);
		int j = 0;
		int k = 0;
		bool token = false;
		while (p[j]) {
			if (p[j] == '(') {
				token = true;
				j++;
			} else if (p[j] == ')') {
				token = false;
				j++;
				k++;
			} else if (token == true) {
				pattern[k][p[j]-'a'] = true;
				j++;
			} else {
				pattern[k][p[j]-'a'] = true;
				j++;
				k++;
			}
		}
		for (int t = 0; t < D; t++) {
			int f = 0;
			for (; f < L; f++) {
				if (pattern[f][words[t][f]] == false) {
					break;
				}
			}
			if (f == L) {
				res++;
			}
		}
		printf ("Case #%d: %d\n", c+1, res);
	}
	return 0;
}