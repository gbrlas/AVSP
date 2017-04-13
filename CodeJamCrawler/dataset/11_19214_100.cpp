#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		int n;
		cin >> n;
		int arr[1001];
		int in_place = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
			if (i == arr[i]) {
				++in_place;
			}
		}
		cout << "Case #" << test << ": " << n - in_place << endl;
	}
}
