#include <cstdio>
#include <map>

using namespace std;
typedef pair<int, int> ii;
#define MAXN 2000000
int TC, a, b;
map<int, bool> M[MAXN+10];
map<ii, int> R;

int main(int argc, char *argv[])
{
	int cut = 1;
	int tenpow = 10, tmppow, mpow;
	int num, count;
	map<int, bool>::iterator it;
	for (int i = 11; i <= MAXN; i++) {
		if (i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
			// compute new power
			tenpow*=10;
			cut++;
			continue;
		}
		tmppow = tenpow;
		mpow = 10;
		for (int k = 0; k < cut; k++) {
			num = (i / tmppow) + (i%tmppow) * mpow;
			if (num > i && num <= MAXN) {
				M[i][num] = true;
				//printf("%d to %d\n", i, num);
			}
			tmppow /= 10;
			mpow *= 10;
		}
	}
	scanf("%d", &TC);
	for (int t = 1; t <= TC; t++) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: ", t);
		if (a == b) {
			printf("0\n");
		} else {
			ii ip = ii(a, b);
			if (R.find(ip) != R.end()) {
				printf("%d\n", R[ip]);
			} else {
				count = 0;
				for (int i = a; i <= b; i++) {
					for (it = M[i].begin(); it != M[i].end(); it++) {
						if(it->first <= b) {
							count++;
						}
					}
				}
				R[ip] = count;
				printf("%d\n", count);
			}
		}
	}
	return 0;
}
