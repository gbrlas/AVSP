#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

int T;
vector <int> bases;
char buff [128];
int tmp;
int exp [] = {0, 0, 30, 19, 15, 13, 11, 11, 10, 9, 9};
set <int> seen;
int at;
bool ok;

int pow (int a, int b) {
	int ret = 1;
	for (int i = 0; i < b; i ++) {
		ret *= a;
	}
	return ret;
}
bool happy (int n, int b) {
	seen.clear ();
	int sum = n;
	while (true) {
		if (n == 91 && b == 7) {
			//printf ("%d\n", sum);
		}
		if (sum == 1) {
			return true;
		}
		if (seen.count (sum)) {
			
			return false;
		}
		seen.insert (sum);
		tmp = sum;
		sum = 0;
		for (int i = exp [b]; i >= 0; i --) {
			sum += pow (tmp / pow (b, i), 2);
			tmp = tmp % pow (b, i);
		}
	}
}

int main () {
	
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);
	
	scanf ("%d\n", &T);
	
	for (int t = 0; t < T; t ++) {
		bases.clear ();
		gets (buff);
		istringstream sin (string (buff) + " ", istringstream::in);
		while (sin >> tmp) {
			bases.push_back (tmp);
			//printf ("%d ", tmp);
		}
		//printf ("\n");
		
		at = 2;
		while (true) {
			ok = true;
			for (int i = 0; i < bases.size (); i ++) {
				if (!happy (at, bases [i])) {
					if (at == 91) {
						//printf ("%d %d\n", at, bases [i]);
					}
					ok = false;
					break;
				}
			}
			if (ok) {
				break;
			}
			at ++;
		}
		
		printf ("Case #%d: %d\n", t + 1, at);
	}
	
}
