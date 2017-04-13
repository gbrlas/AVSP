#include <iostream>
#include <cstdio>
#include <cstring>

char dic[5001][16];

using namespace std;

int main(void)
{
	int i, j, k;
	int L, D, N;
	scanf("%d%d%d", &L, &D, &N);

	for(i = 0; i < D; ++i) {
		scanf("%s", &dic[i]);
	}
	getchar();
	
	for(i = 0; i < N; ++i) {
		char pat[80];;
		int c, p, cnt, table[15][26];

		for(j = 0; j < 15; ++j) {
			for(k = 0; k < 26; ++k) {
				table[j][k] = 0;
			}
		}
		
		p = 0;
		while((c = getchar()) != '\n') {
			if(c == '(') {
				while((c = getchar()) != ')') {
					table[p][c - 'a'] = 1;
				}
			} else {
				table[p][c - 'a'] = 1;
			}
			++p;
		}
		
		cnt = 0;
		for(j = 0; j < D; ++j) {
			bool f = true;
			
			for(k = 0; k < L; ++k) {
				if(!table[k][dic[j][k] - 'a']) {
					f = false;
					break;
				}
			}
			
			if(f) {
				++cnt;
			}
		}
		
		printf("Case #%d: %d\n", i + 1, cnt);
	}
	
	return 0;
}
