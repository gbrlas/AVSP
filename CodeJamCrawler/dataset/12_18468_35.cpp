#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <iostream>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

int N, W, H;
int radius[11000];
int x[11000], y[11000];

void verify() {
	for(int i = 0; i < N; ++i) {
		if(x[i] < 0 || x[i] > W || y[i] < 0 || y[i] > H) {
			cerr << "ERROR 0 " << i << ": " << x[i] << " " << y[i] << endl;
		}
	}
	for(int i = 0; i < N; ++i) {
		for(int j = i + 1; j < N; ++j) {
			long long d1 = x[i] - x[j];
			long long d2 = y[i] - y[j];
			long long d3 = d1 * d1 + d2 * d2;
			long long r2 = radius[i] + radius[j];
			r2 *= r2;
			if(d3 < r2)
				cerr << "ERROR 1 " << i << "," << j << " too close: " << d3 << " vs " << r2 << "; " << x[i] << "," << y[i] << " " << x[j] << "," << y[j] << endl;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t) {
		scanf("%d%d%d", &N, &W, &H);
		for(int i = 0; i < N; ++i)
			scanf("%d", &radius[i]);
		//sort(radius, radius + N);
		//reverse(radius, radius + N);
		
		int xx = 0, yy = 0;
		int widest = 0;
		int largest = 0;
		for(int i = 0; i < N; ++i) {
			//cout << "at " << i << " " << xx << "," << yy << ": " << "r" << radius[i] << " (widest " << widest << ")" << endl;
			int need_h = 2 * radius[i];
			if(yy == 0)
				need_h -= radius[i];
			//cout << "need_h " << need_h << endl;
			if(H + radius[i] < yy + need_h) {
				xx += widest;
				yy = 0;
				widest = 0;
				--i;
				continue;
			}
			int need_w = radius[i];
			if(xx == 0)
				need_w = 0;
			//cout << "need_w " << need_w << endl;
			widest = max(widest, need_w + radius[i]);
			x[i] = xx + need_w;
			largest = max(largest, x[i]);
			y[i] = yy + need_h - radius[i];
			yy += need_h;
			//cout << endl;
		}
		
		verify();

		printf("Case #%d:", t + 1);
		for(int i = 0; i < N; ++i)
			printf(" %d %d", x[i], y[i]);
		printf("\n");
	}
	return 0;
}
