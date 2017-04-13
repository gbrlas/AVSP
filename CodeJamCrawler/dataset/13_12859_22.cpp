#include <stdio.h>

//input
int T;
int A, N;
int in[128];

void sort() {
	int i;
	int sorted;
	int last;

	sorted = N;

	while(sorted) {
		last = 0;
		for(i = 1; i < sorted; i++) {
			if(in[i - 1] > in[i]) {
				int temp = in[i];
				in[i] = in[i - 1];
				in[i - 1] = temp;

				last = i;
			}
		}

		sorted = last;
	}
}
				

int main() {
	int i, j, k;
	int cur_mote;
	int ans;

	scanf("%d", &T);

	for(i = 0; i < T; i++) {
		ans = 0;
		scanf("%d %d", &A, &N);
		cur_mote = A;

		for(j = 0; j < N; j++)
			scanf("%d", &in[j]);

		sort();
		
		for(j = 0; j < N; j++) {
			if(cur_mote > in[j]) {
				cur_mote += in[j];
			}

			else {
				for(k = 0; k < N - j && cur_mote <= in[j] ; k++) {
					cur_mote = cur_mote * 2 - 1;
				}

				ans += k;

				if(cur_mote > in[j])
					cur_mote += in[j];
				else
					break;
			}
		}

		if(ans > N)
			ans = N;

		printf("Case #%d: %d\n", i + 1, ans);
		fflush(stdout);
	}

	return 0;
}

