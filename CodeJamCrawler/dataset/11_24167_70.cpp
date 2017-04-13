#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void main() {
	ifstream cin("A-small.in");
	ofstream cout("output.txt");
	int t;
	cin >> t;
	for (int tc = 0; tc < t; ++tc) {
		int n;
		cin >> n;
		vector<int> p, o, b;
		for (int i = 0; i < n; ++i) {
			string r;
			int p_;
			cin >> r >> p_;
			p.push_back(p_);
			if (r == "O") {
				o.push_back(i);
			} else {
				b.push_back(i);
			}
		}
		int ob = 1, bb = 1;
		int oi = 0, bi = 0;
		int time = 0;
		while(oi < o.size() || bi < b.size()) {
			++time;
			bool ot = oi < o.size() && (bi == b.size() || o[oi] < b[bi]);
			if (oi < o.size()) {
				if (ob < p[o[oi]]) {
					++ob;
				} else if (ob > p[o[oi]]) {
					--ob;
				} else if (ot) {
					++oi;
				}
			}
			if (bi < b.size()) {
				if (bb < p[b[bi]]) {
					++bb;
				} else if (bb > p[b[bi]]) {
					--bb;
				} else if (!ot) {
					++bi;
				}
			}
		}
		cout << "Case #" << tc + 1 << ": " << time << endl;
	}
}