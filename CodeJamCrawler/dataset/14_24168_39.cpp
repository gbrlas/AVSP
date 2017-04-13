#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int N, X;
int pocty[701];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &N, &X);
		for (int i = 1; i <= X; i++) {
			pocty[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			int S;
			scanf("%d", &S);
			pocty[S]++;
		}
		int vysledek = 0;
		for (int i = X; i >= 1; i--) {
			while (pocty[i]) {
				vysledek++;
				pocty[i]--;
				for (int j = min(i, X - i); j >= 1; j--) {
					if (pocty[j]) {
						pocty[j]--;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n", t, vysledek);
	}
	return 0;
}
