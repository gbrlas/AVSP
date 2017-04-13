#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

void insertionSort(int arr[], int length) {
      int i, j, tmp;
      for (i = 1; i < length; i++) {
            j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {
                  tmp = arr[j];
                  arr[j] = arr[j - 1];
                  arr[j - 1] = tmp;
                  j--;
            }
      }
}

int best(int A, int motes[], int i, int len) {
	if (i >= len) return 0;

	if (motes[i] < A) {
		// just consume and move on
		A += motes[i];
		return best(A, motes, i+1, len);
	}

	// special case when we must delete
	if (A-1 <= 0) {
		return 1+best(A, motes, i, len-1);
	}

	// try adding smaller mote and deleting the last one, pick the best outcome
	int a = 1+best(A+A-1, motes, i, len);
	int b = 1+best(A, motes, i, len-1);
	return min(a,b);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t=0; t < T; t++) {
		int A,N;
		scanf("%d %d", &A, &N);

		int motes[110];
		for (int n=0; n < N; n++) {
			scanf("%d", &motes[n]);
		}

		insertionSort(motes, N);

		printf("Case #%d: %d\n", t+1, best(A, motes, 0, N));
	}

}
