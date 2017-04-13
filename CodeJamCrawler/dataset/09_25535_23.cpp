#include <algorithm>
#include <cstdio>

using namespace std;

int T;
char num [128];
bool used [256];
int dig [128];
int at;
long long b;
int len;
long long tmp;
long long val;

int main () {
	
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);
	
	scanf ("%d\n", &T);
	for (int t = 0; t < T; t ++) {
		fill (used, used + 256, false);
		fill (dig, dig + 128, 0);
		gets (num);
		dig [0] = 1;
		used [0] = true;
		
//		printf ("%s\n", num);
		
		for (int i = 1; num [i] != '\0'; i ++) {
			if (num [i] == num [0]) {
				used [i] = true;
				dig [i] = 1;
			}
		}
//		for (int i = 0; num [i] != '\0'; i ++) {
//			printf ("%d", dig [i]);
//		}
//		printf ("\n");
		for (int i = 0; num [i] != '\0'; i ++) {
			if (!used [i]) {
				dig [i] = 0;
				used [i] = true;
				for (int j = 0; num [j] != '\0'; j ++) {
					if (num [i] == num [j]) {
						used [j] = true;
						dig [j] = 0;
					}
				}
				break;
			}
		}
//		for (int i = 0; num [i] != '\0'; i ++) {
//			printf ("%d", dig [i]);
//		}
//		printf ("\n");
		at = 2;
		for (int i = 0; num [i] != '\0'; i ++) {
			if (!used [i]) {
				dig [i] = at;
				used [i] = true;
				for (int j = 0; num [j] != '\0'; j ++) {
					if (num [i] == num [j]) {
						used [j] = true;
						dig [j] = at;
					}
				}
				at ++;
			}
		}
		
//		for (int i = 0; num [i] != '\0'; i ++) {
//			printf ("%d", dig [i]);
//		}
//		printf ("\n");

		
		b = 0;
		for (int i = 0; num [i] != '\0'; i ++) {
			if (b < dig [i]) b = dig [i];
		}
		b ++;
		if (b < 2) b = 2;
		
		val = 0;
		tmp = 1;
		len = strlen (num);
		for (int i = len - 1; i >= 0; i --) {
			val += tmp * dig [i];
			tmp *= b;
		}
		
		printf ("Case #%d: %lld\n", t + 1, val);
	}
}
