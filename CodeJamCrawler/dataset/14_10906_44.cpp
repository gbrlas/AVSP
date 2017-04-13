#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

double C, F, X;

int main()
{
	int T, iter = 0;

	cin >> T;
	while (T--) {
		cin >> C >> F >> X;
		cout << "Case #" << ++iter << ": ";
		if (X <= C)
			cout << X / 2. << endl;
		else {
			int f_max = ceil(X / (min(2., F)));
			double time = 0;
			for (int i = 0; i < f_max; ++i)
				time += (C / (2. + (i * F)));
			time += (X / (2. + (f_max * F)));

			for (int i = 0; i < ceil(X); ++i) {
				double time_f = 0;
				for (int j = 0; j < i; ++j)
					time_f += (C / (2. + (j * F)));
				time_f += (X / (2. + (i * F)));
				time = min(time, time_f);
				//printf("f: %d; time: %.7f\n", i, time_f);
			}

			printf("%.7f\n", time);
			//printf("%.7f\n", solve(f_max, time, f_max / 2));
			//cout << setprecision(8) << solve(f_max, time, f_max / 2) << endl;
		}
	}

	return 0;
}
