#include <algorithm>
#include <cstdio>

using namespace std;

int L, D, N;
char words [5000] [16];
char word [1000];
int cnt;
int at;
bool ok;

int main () {
	
	freopen ("A.in", "r", stdin);
	freopen ("A.out", "w", stdout);
	
	scanf ("%d %d %d\n", &L, &D, &N);
	
	for (int i = 0; i < D; i ++) {
		gets (words [i]);
	}
	for (int t = 0; t < N; t ++) {
		cnt = 0;
		gets (word);
		for (int w = 0; w < D; w ++) {
			at = 0;
			ok = true;
			for (int i = 0; i < L; i ++) {
				if (word [at] == words [w] [i]) {
					at ++;
				}
				else if (word [at] == '(') {
					while (true) {
						at ++;
						if (word [at] == ')') {
							ok = false;
							break;
						}
						if (word [at] == words [w] [i]) {
							while (word [at] != ')') {
								at ++;
							}
							break;
						}
					}
					at ++;
				}
				else {
					ok = false;
				}
			}
			cnt += ok;
		}
		printf ("Case #%d: %d\n", t + 1, cnt);
	}
	
	return 0;
}
