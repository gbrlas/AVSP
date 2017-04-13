#include <algorithm>
#include <cstdio>

#define MSG "welcome to code jam"
#define LEN 19

using namespace std;

int N;
char line [501];
int len;
int dp [19] [500];
int sum;

int main () {
	
	freopen ("C.in", "r", stdin);
	freopen ("C.out", "w", stdout);
	
	scanf ("%d\n", &N);
	
	for (int t = 0; t < N; t ++) {
		gets (line);
		len = 0;
		while (line [len] != '\0') {
			len ++;
		}
		
		for (int i = 0; i < len; i ++) {
			dp [0] [i] = 0;
			if (line [i] == MSG [0]) {
				dp [0] [i] = 1;
			}
		}
		
		for (int i = 1; i < LEN; i ++) {
			for (int j = 0; j < len; j ++) {
				dp [i] [j] = 0;
				if (line [j] == MSG [i]) {
					for (int k = 0; k < j; k ++) {
						dp [i] [j] += dp [i - 1] [k];
						dp [i] [j] %= 10000;
					}
				}
				//printf ("%d\t", dp [i] [j]);
			}
			//printf ("\n");
		}
		
		sum = 0;
		for (int i = 0; i < len; i ++) {
			sum += dp [LEN - 1] [i];
			sum %= 10000;
		}
		
		printf ("Case #%d: %d%d%d%d\n", t + 1, sum / 1000, sum % 1000 / 100, sum % 100 / 10, sum % 10);
	}
	
	return 0;
}
