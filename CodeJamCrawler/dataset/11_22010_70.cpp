#include <assert.h>

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define MAX_INT	0x7FFFFFFF

int main()
{
	int T;
	cin >> T;
	assert(T > 0);

	for (int testCaseCount = 0; testCaseCount < T; testCaseCount++) {
		cout << "Case #" << testCaseCount+1 << ": ";

		int N;
		cin >> N;
		assert(N > 0);

		int candy_value;

		int xor_result = 0;
		int sum = 0;
		int min_value = MAX_INT;

		for (int i = 0; i < N; i++) {
			cin >> candy_value;
			assert(candy_value > 0);

			xor_result ^= candy_value;
			sum += candy_value;
			if (candy_value < min_value)
				min_value = candy_value;
		}

		if (xor_result != 0) {
			cout << "NO" << endl;
		} else {
			cout << sum - min_value << endl;
		}
	}
	return 0;
}
