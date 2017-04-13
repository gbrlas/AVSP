#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T, A, B, K;
	cin >> T;
	for (int qq = 0; qq < T; qq++) {
		cin >> A >> B >> K;
		int count = 0;
		for (int a = 0; a < A; a++) {
			for (int b = 0; b < B; b++) {
				if ((a & b) < K) {
					count++;
				}
			}
		}
		printf("Case #%d: %d\n", qq+1, count);
	}
	return 0;
}
