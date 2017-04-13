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

int base[20] = { 0 };

char buffer[200];


map <int, bool> m;

bool isHappy (int base, int num)
{
	if (num == 1) return true;

	if (m.count(num) == 0) {
		m[num] = true;
	} else {
		return false;
	}

	int t = 0;
	int r = 0;
	while (num > 0) {
		r = num % base;
		num /= base;
		t += (r * r);
	}
	return isHappy(base, t);
}

int f ()
{
	int n = 2;
	while (1) {
		for (int i = 0; i < 20; i++) {
			if (base[i] == 0) {
				return n;
			}
			m.clear();
			if (isHappy (base[i], n)) {
				continue;
			} else {
				n++;
				break;
			}
		}
	}
}

int main ()
{
	int T = 0;
	scanf ("%d\n", &T);
	for (int t = 0; t < T; t++) {
		memset (base, 0, sizeof(base));
		fgets (buffer, 200, stdin);
		int index = 0;
		string temp = string(buffer);
		stringstream ss;
		ss<<temp;
		while (ss>>base[index]) {
			index++;
		}

		int res = f ();
		printf ("Case #%d: %d\n", t + 1, res);
	}
}