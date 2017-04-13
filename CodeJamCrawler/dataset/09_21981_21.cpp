/*
TASK: 
ID: marijon1
LANG: C++
*/

#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#define FOR(i,n) for(int i=0;i<(n);i++)
#define FORO(i,n) for(int i=1;i<=(n);i++)
#define FORS(i,a,n) for(int i=(a);i<(n);i++)
#define FORB(i,a,n) for(int i=(a);i>=(n);i--)

using namespace std;

char matrix[40][40];
int minpos[40];
int n;

void test_case(int ncase) {
	scanf("%d ", &n);
	FOR(r, n) {
		FOR(c, n) {
			scanf("%c", &matrix[r][c]);
			matrix[r][c] -= 48;
		}
		scanf("\n");
	}
	/*FOR(r, n) {
		FOR(c, n) printf("%2d", matrix[r][c]);
		printf("\n");
	}*/
	FOR(r, n) {
		int last = -1;
		FOR(c, n)
			if (matrix[r][c])
				last = c;
		minpos[r] = last;
	}
	int swaps = 0;
	for (int r = 0; r < n; r++) {
		if (minpos[r] > r) {
			// need to move
			for (int i = r+1; i < n; i++) {
				if (minpos[i] <= r) {
					// move this up
					for (int j = i; j > r; j--) {
						swap(minpos[j], minpos[j-1]);
						swaps++;
					}
					r = -1;
					break;
				}
			}
		}
	}
	printf("Case #%d: %d\n", ncase, swaps);
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
	int n;
	scanf("%d ", &n);
	FORO(i, n) test_case(i);
	return 0;
}
