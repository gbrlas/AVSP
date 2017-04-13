#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		double x, s, r, t;
		int n;
		cin >> x >> s >> r >> t >> n;
		vector<double> w(n);
		vector<pair<double, double> > pos(n);
		for (int i = 0; i < n; ++i) {
			cin >> pos[i].first >> pos[i].second >> w[i];
		}
		sort(pos.begin(), pos.end());
		vector<pair<double, double> > d;
		double prev = 0;
		for (int i = 0; i < n; ++i) {
			if (pos[i].first > prev) {
				d.push_back(make_pair(s, pos[i].first - prev));
			}
			d.push_back(make_pair(s + w[i], pos[i].second - pos[i].first));
			prev = pos[i].second;
		}
		if (prev < x) {
			d.push_back(make_pair(s, x - prev));
		}
		sort(d.begin(), d.end());
		double time = 0;
		for (int i = 0; i < d.size(); ++i) {
			double dt = min(t - time, d[i].second / (d[i].first + r - s));
			if (dt > 0) {
				time += dt;
				d[i].second -= dt * (d[i].first + r - s);
			}
			if (d[i].second > 0) {
				time += d[i].second / d[i].first;
			}
		}
		
		cout.precision(15);
		cout << "Case #" << test << ": " << time << endl;
	}
}
