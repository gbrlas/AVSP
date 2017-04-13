#include <stdio.h>
#define NUMBER 128

void init(int array[][NUMBER], int n) {
	int i, j;

	for(i = 0; i < NUMBER; i++) {
		for(j = 0; j < NUMBER; j++) {
			array[i][j] = n;
		}
	}
}

int main() {
	int T;
	int M, N;
	int input[NUMBER][NUMBER];

	int height;
	int flag[NUMBER][NUMBER];
	int flag2[2][NUMBER];
	int flag3;
	int temp;

	int i, j, k;

	scanf("%d", &T);

	for(k = 0; k < T; k++) {
		init(input, 100);
		init(flag, 0);
		flag3 = 1;

		scanf("%d %d", &M, &N);
		for(i = 0; i < M; i++)
			for(j = 0; j < N; j++)
				scanf("%d", &input[i][j]);

		for(i = 0; i < 2; i++) {
			for(j = 0; j < NUMBER; j++) {
				flag2[i][j] = 0;
			}
		}

		for(height = 100; height; height--) {
			for(i = 0; i < M; i++) {
				for(j = 0; j < N; j++) {
					flag2[0][i] += input[i][j] > height ? 1 : 0;
					flag2[1][j] += input[i][j] > height ? 1 : 0;
				}
			}

			for(i = 0; i < M; i++) {
				for(j = 0; j < N; j++) {
					if(!(flag2[0][i] && flag2[1][j])) {
						if(input[i][j] == height) {
							flag[i][j] = 1;
						}
					}
				}
			}
		}

		for(i = 0; i < M; i++) {
			for(j = 0; j < N; j++) {
				if(!flag[i][j])
					flag3 = 0;
			}
		}

		if(flag3)
			printf("Case #%d: YES\n", k + 1);
		else
			printf("Case #%d: NO\n", k + 1);
	}

	return 0;
}

