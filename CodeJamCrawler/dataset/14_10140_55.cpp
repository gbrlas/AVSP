#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct rev {
	bool operator() (double i, double j) {return i > j;}
} drev;

bool all_max(vector<double>& v1, vector<double>& v2) {
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] < v2[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		vector<double> w1;
		vector<double> w2;
		vector<double> dw1;
		vector<double> dw2;
		for (int i = 0; i < n; i++) {
			double d;
			cin >> d;
			w1.push_back(d);
		}
		for (int i = 0; i < n; i++) {
			double d;
			cin >> d;
			w2.push_back(d);
		}
		sort(w1.begin(), w1.end(), drev);
		sort(w2.begin(), w2.end(), drev);
		for (int i = 0; i < w1.size(); i++) {
			dw1.push_back(w1[i]);
		}
		for (int i = 0; i < w2.size(); i++) {
			dw2.push_back(w2[i]);
		}
		int p1 = 0;
		while (w1.size() > 0) {
			if (w1.front() > w2.front()) {
				p1++;
				w1.erase(w1.begin());
				w2.pop_back();
			} else {
				int lg = 0;
				for (int i = 0; i < w2.size(); i++) {
					if (w1.front() < w2[i]) {
						lg++;
					} else {
						break;
					}
				}
				w2.erase(w2.begin() + (lg - 1));
				w1.erase(w1.begin());
			}
		}
		int p2 = 0;
		while (dw1.size() > 0) {
			if (all_max(dw1, dw2)) {
				dw1.erase(dw1.begin());
				dw2.erase(dw2.begin());
				p2++;
			} else {
				dw1.pop_back();
				dw2.erase(dw2.begin());
			}
		}
		cout << "Case #" << t << ": ";
		cout << p2 << " " << p1;
		cout << endl;
	}
}
