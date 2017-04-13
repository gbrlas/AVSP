#include <algorithm>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <iostream>

#define foreach(i,s,w) for(int i=s;i<w.size();++i)
#define forX(i,m) for(typeof(m.begin())i=m.begin();i!=m.end();++i)

using namespace std;

long long sqr(long long a) {
	return a * a;
}

vector <pair <int, int> > v;

bool makes_triangle(long long A, long long B, long long C) {
	long long x1 = 4 * A * B;
	long long x2 = (C - A - B) * (C - A - B);
	cout << A << " " << B << " " << C << ": " << x1 << " " << x2 << endl;
	return x1 != x2;
}
	
int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		v.clear();
		long long n, A, B, C, D, x0, y0, M;
		cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
		v.push_back(make_pair(x0, y0));
		for(int i = 1; i < n; ++i) {
			x0 = (A * x0 + B) % M;
			y0 = (C * y0 + D) % M;
			v.push_back(make_pair(x0, y0));
		}
		int res = 0;
		foreach(i, 0, v)
			foreach(j, i + 1, v)
				foreach(k, j + 1, v) {
					if((v[i].first + v[j].first + v[k].first) % 3 != 0)
						continue;
					if((v[i].second + v[j].second + v[k].second) % 3 != 0)
						continue;
					long long A = sqr(v[i].first - v[j].first) + sqr(v[i].second - v[j].second);
					long long B = sqr(v[i].first - v[k].first) + sqr(v[i].second - v[k].second);
					long long C = sqr(v[k].first - v[j].first) + sqr(v[k].second - v[j].second);
					++res;
					/*cout << v[i].first << ", " << v[i].second << "; ";
					cout << v[j].first << ", " << v[j].second << "; ";
					cout << v[k].first << ", " << v[k].second << "; ";
					cout << endl;
					if(v[i] == v[j] || v[i] == v[k] || v[j] == v[k] || makes_triangle(A, B, C))
						++res;
					cout << endl;*/
				}
		printf("Case #%d: %d\n", t + 1, res);
	}
	return 0;
}
