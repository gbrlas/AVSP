#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
float a[1000], b[1000];

int reverse_play(int N_t) {
	int wins = 0;
	int temp_b_N = N_t;
	float temp_b[1000];
	for (int i = 0; i < N_t; ++i)
		temp_b[i] = b[i];

	bool change_b_N = false;
	for (int i = N_t - 1; i >= 0; --i) {
		change_b_N = false;
		for (int j = temp_b_N - 1; j >= 0; --j) {
			//cout << "temp_b[" << j << "]: " << temp_b[j] << endl;
			if (temp_b[j] < a[i]) {
				if (j == temp_b_N - 1) {
					wins++;
					//cout << "wins: " << wins << endl;
					temp_b_N--;
					change_b_N = true;
					break;
				}
				if (j < temp_b_N - 1)
					j++;
				for (int k = j; k < temp_b_N-1; ++k)
					temp_b[k] = temp_b[k+1];
				temp_b_N--;
				change_b_N = true;
				//wins++;
				//cout << "2wins: " << wins << endl;
				break;
			}
		}
		if (!change_b_N) temp_b_N--;
	}

	return wins;
}

int withdeceit() {
	int wins = 0, temp_N = N;
	wins = reverse_play(temp_N);
	while(temp_N >= 0) {
		//cout << "temp_N: " << temp_N << endl;
		if (a[0] < b[temp_N-1]) {
			// delete a[0]
			for (int i = 0; i < temp_N - 1; ++i)
				a[i] = a[i+1];
			// delete b[temp_N]
			temp_N--;
			wins = max(wins, reverse_play(temp_N));
			//cout << "reverse_play: " << reverse_play(temp_N) << endl;
		} else {
			break;
		}
	}

	return wins;
}

int withoutdeceit() {
	int wins = 0;
	int temp_b_N = N;
	float temp_b[1000];
	for (int i = 0; i < N; ++i)
		temp_b[i] = b[i];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < temp_b_N; ++j) {
			if (temp_b[j] > a[i]) {
				// delete temp_b[j]
				for (int k = j; k < temp_b_N-1; ++k)
					temp_b[k] = temp_b[k+1];
				temp_b_N--;
				break;
			} else {
				if (j == temp_b_N - 1)
					wins++;
			}
		}
	}

	return wins;
}

int main()
{
	int T, iter = 1;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> b[i];
		}
		sort(a, a + N);
		sort(b, b + N);
		printf("Case #%d: %d %d\n", iter++, withdeceit(), withoutdeceit());
	}
	return 0;
}
