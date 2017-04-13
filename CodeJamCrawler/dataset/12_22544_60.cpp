#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int p10floor(int n) {
    int result = 1;
	while (n >= result) result *= 10;
	return result / 10;
}

int rotate(int n, int powerOfTen) {
	int ones = n % 10;
	return n / 10 + ones*powerOfTen;
}

int main() {
	map<int, vector<int> > recycled;
	for (int n = 11; n <= 2000000; n++) {
		recycled[n] = vector<int>();

		int p10 = p10floor(n);
		int rotated = rotate(n, p10);
		while (rotated != n) {
			if (p10floor(rotated) == p10 && rotated > n) 
				recycled[n].push_back(rotated);
			rotated = rotate(rotated, p10);
		}
	}

	int T;
	cin >> T;

	for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
		int A, B;
		cin >> A >> B;
		int count = 0;
		for (int n = A; n <= B; n++) {
			for (vector<int>::iterator i = recycled[n].begin();
				 i != recycled[n].end(); i++) {
				int m = *i;
				if (m <= B) count++;
			}
		}
		cout << "Case #" << caseNumber << ": " << count << endl;
	}
}
