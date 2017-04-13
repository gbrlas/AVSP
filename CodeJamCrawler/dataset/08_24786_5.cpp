#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int ncases;
	cin >> ncases;
	for (int n = 1; n <= ncases; n++) {
		cout << "Case #" << n << ": ";
		vector <int> a, b;
		int d;
		cin >> d;

		for (int i = 0; i < d; i++) {
			int tmp;
			cin >> tmp;
			a.push_back(tmp);
		}

		for (int i = 0; i < d; i++) {
			int tmp;
			cin >> tmp;
			b.push_back(tmp);
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		//for (int i = 0; i < d; i++) 
		//	cout << b[i] << " ";

		int p = 0;

		if (d != a.size()) cout << "\n******shit******\n";

		for (int i = 0; i < d; i++)
			p += a[i]*b[d-i-1];


		cout << p;


		cout << endl;
	}
	return 0;
}