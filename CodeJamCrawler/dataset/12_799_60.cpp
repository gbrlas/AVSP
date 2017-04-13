#include <cstdio>
#include <algorithm>

using namespace std;
#define MAXGO 100
int TC, N, S, P;
int scores[MAXGO+10];

int maxSc[31] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4,
                  4, 4, 5, 5, 5, 6, 6, 6, 7, 7,
				  7, 8, 8, 8, 9, 9, 9, 10, 10, 10
			  };
int sup[31] = {0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4,
                  5, 5, 5, 6, 6, 6, 7, 7, 7, 8,
				  8, 8, 9, 9, 9, 10, 10, 10, 10, 10
		      };

int main(int argc, char *argv[])
{
	int more, sc;
	scanf("%d", &TC);
	for (int t = 1; t <= TC; t++) {
		scanf("%d %d %d", &N, &S, &P);
		for (int i = 0; i < N; i++)
			scanf("%d", &scores[i]);
		sort(scores, scores+N);
		more = 0;
		for (int i = N-1; i >= 0; i--) {
			sc = scores[i];
			if (sc == 30 || sc == 29 || sc == 0 || sc == 1) {
				if (sc >= P)
					more++;
			} else {
				if (maxSc[sc] >= P)
					more++;
				else if (sup[sc] >= P && S > 0) {
					S--;
					more++;
				}
			}
		}
		printf("Case #%d: %d\n", t, more);
	}
	return 0;
}
