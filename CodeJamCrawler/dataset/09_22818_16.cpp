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
#include <assert.h>

using namespace std;

char input[41][400];

int N;

int d[41];

void getInput ()
{
	scanf ("%d", &N);
	for (int i = 0; i < N;i ++) {
		scanf ("%s", input[i]);
	}

	for (int i = 0; i < N; i++) {
		d[i] = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (input[i][j] == '1') {
				d[i] = j;
				break;
			}
		}
	}
}

int f ()
{
	int res = 0;
	int temp = 0;

	vector <int> p(0, 41);

	for (int i = N - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			p.clear();
			for (int k = i; k >= 0; k--) {
				if (k != j) {
					p.push_back(d[k]);
				}
			}
			::sort(p.begin(), p.end());
			bool isOk = true;
			for (int k = 0; k < i; k++) {
				if (p[k] > k) {
					isOk = false;
					break;
				}
			}
			if (isOk == true) {
				res += (i - j);
				temp = d[j];
				for (int k = j; k < i; k++) {
					d[k] = d[k+1];
				}
				d[i] = temp;
				break;
			}
		}
	}
	return res;
}

int main ()
{
	int T = 0;
	scanf ("%d\n", &T);
	for (int t = 0; t < T; t++) {
		memset (input, 0, sizeof(input));

		getInput ();

		int res = f ();

		printf ("Case #%d: %d\n", t + 1, res);
	}
}