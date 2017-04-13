#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

int N;
int cisla[1000];
int zpet_cisla[1000];
int permutace[1000];
int zpet_permutace[1000];
int pomocne[1000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &cisla[i]);
			permutace[i] = cisla[i];
		}
		sort(permutace, permutace + N);
		// printf("#");
		for (int i = 0; i < N; i++) {
			cisla[i] = lower_bound(permutace, permutace + N, cisla[i]) - permutace;
			zpet_cisla[cisla[i]] = i;
			// printf(" %d", cisla[i]);
		}
		// printf("\n");
		// printf("#");
		for (int i = 0; i < N; i++) {
			// printf(" %d", zpet_cisla[i]);
			permutace[i] = i;
		}
		// printf("\n");
		int vysledek = 1000000000;
		do {
			bool je_v_poradku = true;
			int m = -1;
			for (int i = 1; i < N; i++) {
				if (m == -1) {
					if (permutace[i] < permutace[i-1]) {
						m = i-1;
					}
				} else {
					if (permutace[i] > permutace[i-1]) {
						je_v_poradku = false;
						break;
					}
				}
			}

			if (je_v_poradku) {
				for (int i = 0; i < N; i++) {
					zpet_permutace[i] = zpet_cisla[permutace[i]];
				}
				int inverzi = 0;
				for (int i = 0; i < N; i++) {
					pomocne[i] = 0;
				}
				for (int i = 0; i < N; i++) {
					int z = zpet_permutace[i];
					for (int j = z + 1; j < N; j++) {
						inverzi += pomocne[j];
					}
					pomocne[z]++;
				}
				vysledek = min(vysledek, inverzi);
			}

		} while (next_permutation(permutace, permutace + N));
		printf("Case #%d: %d\n", t, vysledek);
	}
	return 0;
}
