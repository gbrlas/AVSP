#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int T = 0, TC, A, B;
	int mached[10], nmached, result, ten, temp;
	scanf("%d", &TC);
	while (T++ < TC) {
		scanf("%d %d", &A, &B);
		result = 0;
		for (temp = A/10, ten = 1; temp; ten *= 10, temp /= 10);
		for (int i = A + 1, j, k; i <= B; i++) {
			nmached = 0;
			j = i;
			do {
				j = (j%10)*ten + (j /= 10);
				if (j < i && j >= A) {
					for (k = 0; k < nmached; k++)
						if (j == mached[k])
							break;
					if (k == nmached) {
						mached[nmached++] = j;
						result++;
					}
				}
			} while (j != i);
		}
		printf("Case #%d: %d\n", T, result);
	}
}

