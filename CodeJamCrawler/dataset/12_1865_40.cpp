#include <stdio.h>
#include <string.h>
using namespace std;

int recycled[2000001][6];
int mached[2000001];

int main()
{
	int T = 0, TC, A, B;
	int result, ten, temp;
	ten = 10;
	for (int i = 10, j, k; i < 100; i++) {
		j = i;
		do {
			while (j && j%10 == 0)
				j /= 10;
			j = (j%10)*ten + (j /= 10);
			if (j < i) {
				for (k = 0; k < mached[i]; k++)
					if (j == recycled[i][k])
						break;
				if (k == mached[i])
					recycled[i][mached[i]++] = j;
			}
		} while (j != i);
	}
	ten = 100;
	for (int i = 100, j, k; i < 1000; i++) {
		j = i;
		do {
			while (j && j%10 == 0)
				j /= 10;
			j = (j%10)*ten + (j /= 10);
			if (j < i) {
				for (k = 0; k < mached[i]; k++)
					if (j == recycled[i][k])
						break;
				if (k == mached[i])
					recycled[i][mached[i]++] = j;
			}
		} while (j != i);
	}
	ten = 1000;
	for (int i = 1000, j, k; i < 10000; i++) {
		j = i;
		do {
			while (j && j%10 == 0)
				j /= 10;
			j = (j%10)*ten + (j /= 10);
			if (j < i) {
				for (k = 0; k < mached[i]; k++)
					if (j == recycled[i][k])
						break;
				if (k == mached[i])
					recycled[i][mached[i]++] = j;
			}
		} while (j != i);
	}
	ten = 10000;
	for (int i = 10000, j, k; i < 100000; i++) {
		j = i;
		do {
			while (j && j%10 == 0)
				j /= 10;
			j = (j%10)*ten + (j /= 10);
			if (j < i) {
				for (k = 0; k < mached[i]; k++)
					if (j == recycled[i][k])
						break;
				if (k == mached[i])
					recycled[i][mached[i]++] = j;
			}
		} while (j != i);
	}
	ten = 100000;
	for (int i = 100000, j, k; i < 1000000; i++) {
		j = i;
		do {
			if (j%10) {
				j = (j%10)*ten + (j /= 10);
				if (j < i) {
					for (k = 0; k < mached[i]; k++)
						if (j == recycled[i][k])
							break;
					if (k == mached[i])
						recycled[i][mached[i]++] = j;
				}
			} else
				j /= 10;
		} while (j != i);
	}
	ten = 1000000;
	for (int i = 1000000, j, k; i <= 2000000; i++) {
		j = i;
		do {
			if (j%10) {
				j = (j%10)*ten + (j /= 10);
				if (j < i) {
					for (k = 0; k < mached[i]; k++)
						if (j == recycled[i][k])
							break;
					if (k == mached[i])
						recycled[i][mached[i]++] = j;
				}
			} else
				j /= 10;
		} while (j != i);
	}
	scanf("%d", &TC);
	while (T++ < TC) {
		scanf("%d %d", &A, &B);
		result = 0;
		for (int i = A + 1, j; i <= B; i++)
			for (j = 0; j < mached[i]; j++)
				if (recycled[i][j] >= A)
					result++;
		printf("Case #%d: %d\n", T, result);
	}
}

