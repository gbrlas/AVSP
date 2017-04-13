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
		int mem[4][4];
		memset(mem, 0, sizeof(mem));
		foreach(i, 0, v)
			++mem[v[i].first % 3][v[i].second % 3];
		long long result = 0;
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < 3; ++j)
				for(int i2 = 0; i2 < 3; ++i2)
					for(int j2 = 0; j2 < 3; ++j2) {
						int need_i = (3 - (i + i2) % 3) % 3;
						int need_j = (3 - (j + j2) % 3) % 3;
						long long a = mem[i][j];
						long long b = mem[i2][j2];
						long long c = mem[need_i][need_j];
						if(i == i2 && j == j2)
							--b;
						if(i == need_i && j == need_j)
							--c;
						if(i2 == need_i && j2 == need_j)
							--c;
						if(a <= 0 || b <= 0 || c <= 0)
							continue;
						result += a * b * c;
					}
		result /= 6;
		cout << "Case #" << (t + 1) << ": " << result << endl;
	}
	return 0;
}
