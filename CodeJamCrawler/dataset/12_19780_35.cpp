#include <cstdio>
#include <algorithm>
using namespace std;
inline void solve(int tc) {
	int N, S, P;
	scanf("%d %d %d", &N, &S, &P);
	int bisa = 0, surprise = 0;
	int lho1 = max(3*P - 2, P);
	int lho2 = max(3*P - 4, P);
	for (int i = 0; i < N; i++) {
		int bil;
		scanf("%d", &bil);
		if (bil >= lho1)
			bisa++;
		else if (bil >= lho2)
			surprise++;
	}
	int res = bisa + min(surprise, S);
	printf("Case #%d: %d\n", tc, res);
	
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) solve(i);
	return 0;
}
