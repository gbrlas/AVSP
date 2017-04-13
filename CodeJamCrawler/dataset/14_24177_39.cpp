#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

struct hrana_t {
	int a, b;
	int tok;
	int kapacita;
	int zpetna_hrana;

	hrana_t(int a = 0, int b = 0, int tok = 0, int kapacita = 0, int zpetna_hrana = 0)
	{
		this->a = a;
		this->b = b;
		this->tok = tok;
		this->kapacita = kapacita;
		this->zpetna_hrana = zpetna_hrana;
	}
};

int R, S, B, N, M, Zdroj, Stok;
bool mapa[505][105];
int vstupy_vrcholu[505][105];
int vystupy_vrcholu[505][105];
hrana_t hrany[2000000];
vector<int> sousedni_hrany[2000000];
bool dead[2000000];
bool navstiveny[2000000];

bool zlepsi(int v)
{
	if (v == Stok) return true;
	if (dead[v] || navstiveny[v]) return false;

	navstiveny[v] = true;

	for (int i = 0; i < (int) sousedni_hrany[v].size(); i++) {
		int hrana = sousedni_hrany[v][i];
		int zpetna_hrana = hrany[hrana].zpetna_hrana;
		if (hrany[hrana].tok < hrany[hrana].kapacita && zlepsi(hrany[hrana].b)) {
			hrany[hrana].tok++;
			hrany[zpetna_hrana].tok--;
			navstiveny[v] = false;
			return true;
		}
	}

	for (int i = 0; i < (int) sousedni_hrany[v].size(); i++) {
		int hrana = sousedni_hrany[v][i];
		int zpetna_hrana = hrany[hrana].zpetna_hrana;
		if (hrany[zpetna_hrana].tok > 0 && zlepsi(hrany[hrana].b)) {
			hrany[zpetna_hrana].tok--;
			hrany[hrana].tok++;
			navstiveny[v] = false;
			return true;
		}
	}

	navstiveny[v] = false;
	dead[v] = true;
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &S, &R, &B);
		for (int r = 0; r < R; r++) {
			for (int s = 0; s < S; s++) {
				mapa[r][s] = true;
			}
		}
		for (int i = 0; i < B; i++) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (int r = y1; r <= y2; r++) {
				for (int s = x1; s <= x2; s++) {
					mapa[r][s] = false;
				}
			}
		}
		// for (int r = R-1; r >= 0; r--) {
		// 	for (int s = 0; s < S; s++) {
		// 		printf("%c", mapa[r][s] ? '.' : 'X');
		// 	}
		// 	printf("\n");
		// }
		
		N = 0;
		Zdroj = N++;
		Stok = N++;
		for (int r = 0; r < R; r++) {
			for (int s = 0; s < S; s++) {
				if (mapa[r][s]) {
					vstupy_vrcholu[r][s] = N++;
					vystupy_vrcholu[r][s] = N++;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			sousedni_hrany[i].clear();
		}

		M = 0;
		for (int r = 0; r < R; r++) {
			for (int s = 0; s < S; s++) {
				if (mapa[r][s]) {
					int vstup = vstupy_vrcholu[r][s];
					int vystup = vystupy_vrcholu[r][s];
					hrany[M] = hrana_t(vstup, vystup, 0, 1, M+1);
					hrany[M+1] = hrana_t(vystup, vstup, 0, 1, M);
					sousedni_hrany[vstup].push_back(M);
					sousedni_hrany[vystup].push_back(M+1);
					M += 2;

					if (r == 0) {
						hrany[M] = hrana_t(Zdroj, vstup, 0, 1, M+1);
						hrany[M+1] = hrana_t(vstup, Zdroj, 0, 0, M);
						sousedni_hrany[Zdroj].push_back(M);
						sousedni_hrany[vstup].push_back(M+1);
						M += 2;
					}
					if (r == R-1) {
						hrany[M] = hrana_t(vystup, Stok, 0, 1, M+1);
						hrany[M+1] = hrana_t(Stok, vystup, 0, 0, M);
						sousedni_hrany[vystup].push_back(M);
						sousedni_hrany[Stok].push_back(M+1);
						M += 2;
					}
					const int dr[2] = { 0, 1 };
					const int ds[2] = { 1, 0 };
					for (int i = 0; i < 2; i++) {
						int soused_r = r + dr[i], soused_s = s + ds[i];
						if (soused_r < R && soused_s < S && mapa[soused_r][soused_s]) {
							int soused_vstup = vstupy_vrcholu[soused_r][soused_s];
							int soused_vystup = vystupy_vrcholu[soused_r][soused_s];
							hrany[M] = hrana_t(vystup, soused_vstup, 0, 1, M+1);
							hrany[M+1] = hrana_t(soused_vstup, vystup, 0, 0, M);
							sousedni_hrany[vystup].push_back(M);
							sousedni_hrany[soused_vstup].push_back(M+1);
							M += 2;

							hrany[M] = hrana_t(soused_vystup, vstup, 0, 1, M+1);
							hrany[M+1] = hrana_t(vstup, soused_vystup, 0, 0, M);
							sousedni_hrany[soused_vystup].push_back(M);
							sousedni_hrany[vstup].push_back(M+1);
							M += 2;							
						}
					}
				}
			}
		}

		do {
			for (int i = 0; i < N; i++) {
				dead[i] = false;
				navstiveny[i] = false;
			}
		} while (zlepsi(Zdroj));

		// printf("%d %d\n", N, M);
		// for (int i = 0; i < M; i++) {
		// 	printf("%d %d %d/%d\n", hrany[i].a, hrany[i].b, hrany[i].tok, hrany[i].kapacita);
		// }

		int vysledek = 0;
		for (int i = 0; i < (int) sousedni_hrany[Zdroj].size(); i++) {
			// printf("# %d\n", hrany[sousedni_hrany[Zdroj][i]].tok);
			vysledek += hrany[sousedni_hrany[Zdroj][i]].tok;
		}
		printf("Case #%d: %d\n", t, vysledek);
	}
	return 0;
}
