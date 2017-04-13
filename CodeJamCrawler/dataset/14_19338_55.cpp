#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int T = 0;

	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w+", stdout);
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		double C = 0.0, F = 0.0, X = 0.0;
		cin >> C >> F >> X;

		double res = X / 2.0;
		double cost = 0.0;
		
		int farm = 0;
		while (true) {
			cost += C / (farm * F + 2.0);
			farm++;

			double newres = X / (farm * F + 2.0) + cost;
			if (newres > res) {
				break;
			} else {
				res = newres;
			}
		}

		printf("Case #%d: %.8lf\n", cas, res);
	}
    return 0;
}
