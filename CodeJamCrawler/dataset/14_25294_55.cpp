#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	int t;
	double C, F, X;

	freopen("B-large.in", "r", stdin);
	freopen("outB.txt", "w", stdout);

	ifstream fin;
	ofstream fout;
	//fin.open("B-small-attempt1.in");
	//fout.open("ansB.txt");

	//fin >> t;
	scanf("%d", &t);
	for(int cas = 1; cas <= t; ++cas) {
		//fin >> C >> F >> X;
		scanf("%lf%lf%lf", &C, &F, &X);
		double tmp =  (X * F - 2 * C) / (C * F);

		int n = 0;

		if(tmp < 0)
			n = 1;
		else
			n = (int)tmp + 1;

		double ans = 0;

		for(int i = n - 1; i >= 0; --i) {
			if(i == n - 1)
				ans += X / (2 + i * F);
			else
				ans += C / (2 + i * F);
		}

		//fout << setprecision(7) << ans << endl;
		printf("Case #%d: %.7f\n", cas, ans );
		//fout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;

}