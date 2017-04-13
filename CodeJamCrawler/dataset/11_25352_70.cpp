#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int N, pos[110], P, b[110], o[110];
char s[110][110];

int main () {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int ooo = 0, bbb = 0;
		scanf("%d", &P);
		for (int j = 0; j < P; ++j)
			scanf("%s%d", s[j], &pos[j]);
		
		for (int j = 0; j < P; ++j) {
			if (s[j][0] == 'B')
				b[bbb++] = pos[j];
			if (s[j][0] == 'O')
				o[ooo++] = pos[j];
		}
		
		int ans = 0, idx = 0, O = 1, B = 1, oo = 0, bb = 0;
		
		while (idx < P) {
			bool ketemu = false;
			ans++;
			if (s[idx][0] == 'B' && B == pos[idx]) {
				idx++;
				bb++;
				ketemu = true;
				if (oo < ooo && o[oo] < O) O--;
				else if (oo < ooo && o[oo] > O) O++;
			}
			
			if (s[idx][0] == 'O' && O == pos[idx] && !ketemu) {
				idx++;
				oo++;
				ketemu = true;
				if (bb < bbb && b[bb] < B) B--;
				else if (bb < bbb && b[bb] > B) B++;
			}
			
			if (!ketemu) {
				if (bb < bbb && b[bb] < B) B--;
				else if (bb < bbb && b[bb] > B) B++;
				if (oo < ooo && o[oo] < O) O--;
				else if (oo < ooo && o[oo] > O) O++;
			}
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
}
