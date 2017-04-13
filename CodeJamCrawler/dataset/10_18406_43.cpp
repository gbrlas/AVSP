#include <stdio.h>

#define NUM_N 31

int main(void)
{
	int n;
	int i, j;

	int T;
	int N, K;

	int flg_Power;  // 0:OFF 1:ON

	struct tag_Snapper {
		int Power;  // 0:OFF 1:ON
		int State;  // 0:OFF 1:ON
	} Snapper[NUM_N];

	scanf("%d", &T);

	for(n=0 ; n<T; ++n) {

		scanf("%d %d", &N, &K);

		for(i=0; i<N+1; ++i) {
			Snapper[i].Power = 0;
			Snapper[i].State = 0;
		}
		Snapper[0].Power = 1;

		for(i=0; i<K; ++i) {
			for(j=0; j<N+1; ++j) {
				if(Snapper[j].Power == 1) {
					Snapper[j].State = 1 - Snapper[j].State;
				}
			}
			flg_Power = 1;
			for(j=0; j<N+1; ++j) {
				if(Snapper[j].Power == 1 && Snapper[j].State == 1 && flg_Power == 1) {
					Snapper[j+1].Power = 1;
				} else {
					Snapper[j+1].Power = 0;
					flg_Power = 0;
				}
			}
		}

		printf("Case #%d: %s\n", n+1, Snapper[N].Power?"ON":"OFF");

	}

	return 0;
}
