#include <cstdio>

int T;
int S;
int p;
int N;

int t[105];

int ok_nosurprise = 0;
int ok_surprise = 0;

int nsupr[40];
int supr[40];

int main () {

	nsupr[0] = 0;
	nsupr[1] = 1;
	nsupr[2] = 1;
	nsupr[3] = 1;
	nsupr[4] = 2;
	nsupr[5] = 2;
	nsupr[6] = 2;
	nsupr[7] = 3;
	nsupr[8] = 3;
	nsupr[9] = 3;
	nsupr[10] = 4;
	nsupr[11] = 4;
	nsupr[12] = 4;
	nsupr[13] = 5;
	nsupr[14] = 5;
	nsupr[15] = 5;
	nsupr[16] = 6;
	nsupr[17] = 6;
	nsupr[18] = 6;
	nsupr[19] = 7;
	nsupr[20] = 7;
	nsupr[21] = 7;
	nsupr[22] = 8;
	nsupr[23] = 8;
	nsupr[24] = 8;
	nsupr[25] = 9;
	nsupr[26] = 9;
	nsupr[27] = 9;
	nsupr[28] = 10;
	nsupr[29] = 10;
	nsupr[30] = 10;

	supr[0] = 0;
	supr[1] = 1;
	supr[2] = 2;
	supr[3] = 2;
	supr[4] = 2;
	supr[5] = 3;
	supr[6] = 3;
	supr[7] = 3;
	supr[8] = 4;
	supr[9] = 4;
	supr[10] = 4;
	supr[11] = 5;
	supr[12] = 5;
	supr[13] = 5;
	supr[14] = 6;
	supr[15] = 6;
	supr[16] = 6;
	supr[17] = 7;
	supr[18] = 7;
	supr[19] = 7;
	supr[20] = 8;
	supr[21] = 8;
	supr[22] = 8;
	supr[23] = 9;
	supr[24] = 9;
	supr[25] = 9;
	supr[26] = 10;
	supr[27] = 10;
	supr[28] = 10;
	supr[29] = 10;
	supr[30] = 10;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		scanf("%d", &S);
		scanf("%d", &p);
		ok_nosurprise = 0;
		ok_surprise = 0;
		for (int n = 0; n < N; n++) {
			scanf("%d", &t[n]);
			if (nsupr[t[n]] >= p) {
				ok_nosurprise++;
			}
			else if (supr[t[n]] >= p) {
				ok_surprise++;
			}
		}
		
		if (ok_surprise > S)
			ok_surprise = S;
		
		printf("Case #%d: %d\n", (i+1), (ok_nosurprise + ok_surprise));
		
	}
	
}