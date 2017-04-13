#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int T;
char buff [100];
string num;

int main () {
	
	freopen ("B.in", "r", stdin);
	freopen ("B.out", "w", stdout);
	scanf ("%d\n", &T);
	
	for (int t = 0; t < T; t ++) {
		gets (buff);
		num = string (buff);
		
		next_permutation (num.begin (), num.end ());
		
		if (string (buff) >= num) {
			num = "0" + num;
			for (int i = 0; i < num.length (); i ++) {
				if (num [i] != '0') {
					swap (num [0], num [i]);
					break;
				}
			}
			//num += "0";
		}
		
		printf ("Case #%d: %s\n", t + 1, num.c_str ());
	}
}
