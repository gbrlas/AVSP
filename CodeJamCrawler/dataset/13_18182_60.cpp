#include <iostream>
#include <math.h>

using namespace std;

typedef unsigned long long uint64_t;

bool palindrome(uint64_t v) {
	char digits[100];
	int i, c;
	for (i = 0; v ;i++) {
		digits[i] = v % 10;
		v /= 10;
	}
	c = i;
	for (i = 0; i < c / 2; i++) {
		if (digits[i] != digits[c - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main()
{
    int N;
	uint64_t A, B;
    cin >> N;
    for (uint64_t i = 0; i < N; i++) {
		int count = 0;
        cout << "Case #" << (i + 1) << ": ";
		cin >> A >> B;
		for (uint64_t j = A; j <= B; j++) {
			if ((uint64_t)sqrt(j) * (uint64_t)sqrt(j) != j) {
				continue;
			}
			if (palindrome(j) && palindrome(sqrt(j))) {
				count++;
			}
		}
		cout << count << endl;
	}
    return 0;
}
