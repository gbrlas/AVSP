#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
	int ncases;
	cin >> ncases;
	for (int n = 1; n <= ncases; n++) {
		cout << "Case #" << n << ": ";
		int p, k, l, tmp;
		vector <int> freq;
		cin >> p >> k >> l;
		for (int i = 0; i < l; i++) {
			cin >> tmp;
			freq.push_back(tmp);
		}

		if (p*k < l) {
			cout << "Impossible";
			continue;
		}

		sort(freq.begin(), freq.end());

		//cout << freq[0];
		
		assert(freq.size() == l);

		long long presses = 0;
		for (int i = 0; i < freq.size(); i++) {
			presses += freq[l-1-i]*(i/k+1);
		}

		cout << presses;


		cout << endl;
	}
	return 0;
}