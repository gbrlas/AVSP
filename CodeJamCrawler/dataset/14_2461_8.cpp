#include <iostream>

using namespace std;

int solve(unsigned int A, unsigned int B, unsigned int K) {
	int pairs = 0;

	for(unsigned int a = 0; a < A; a++) {
		for(unsigned int b = 0; b < B; b++) {
			if((a & b) < K) pairs++;
		}
	}

	return pairs;
}

int main() {
    int cases;
    cin >> cases;

    for(int current_case = 1; current_case <= cases; current_case++) {
        unsigned int A, B, K;
        cin >> A >> B >> K;

        int solution = solve(A, B, K);

        cout << "Case #" << current_case << ": " << solution << endl;
    }

    return 0;
}