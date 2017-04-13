#include <cstdio>
#include <algorithm>
typedef struct {
	int pos;
	bool orange;
}Tseq;
Tseq seq[105];
int tc = 0;
void solve () {
	tc++;
	int i;
	int N;
	scanf("%d%*c", &N);
	for (i = 0; i < N; i++) {
		char tmp;
		scanf("%c %d%*c", &tmp, &seq[i].pos);
		//printf("%c %d\n", tmp, seq[i].pos);
		seq[i].orange = tmp == 'O' ? true : false;
	}
	int lposO, lposB, ltimeO, ltimeB;
	lposO = 1;
	lposB = 1;
	ltimeO = 0;
	ltimeB = 0;
	int res = 0;
	for (i = 0; i < N; i++) {
		if (seq[i].orange) {
			int d = abs(lposO - seq[i].pos);
			d -= res - ltimeO;
			if (d > 0)
				res += d;
			lposO = seq[i].pos;
			ltimeO = res + 1;
		}
		else {
			int d = abs(lposB - seq[i].pos);
			d -= res - ltimeB;
			if (d > 0)
				res += d;
			lposB = seq[i].pos;
			ltimeB = res + 1;
		}
		res++;
	}
	printf("Case #%d: %d\n", tc, res);
}

int main() {
	int jtc;
	scanf("%d", &jtc);
	while (jtc--) solve();
	return 0;
}
