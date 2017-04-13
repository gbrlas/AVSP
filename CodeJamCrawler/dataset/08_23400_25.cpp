#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <complex>

using namespace std;

#define FOR(i,a,b) for (unsigned long long i = (a); i < (b); ++i)
#define DOWNFOR(i,a,b) for (unsigned long long i = (b)-1; i >= (a); --i)
#define CD complex<double>
#define All(x) (x).begin(), (x).end()

unsigned long long N;
unsigned long long n, A, B, C, D, x00, y00, M;
unsigned long long x, y, res;

int main()
{
	unsigned long long pole[3][3];

	cin >> N;
	FOR (icase, 0, N)
	{
		FOR (i, 0, 3)
			FOR (j, 0, 3)
				pole[i][j] = 0;

		res = 0;
		cin >> n >> A >> B >> C >> D >> x00 >> y00 >> M;
		x = x00;
		y = y00;

		FOR (i, 0, n)
		{
			pole[x%3][y%3]++;
			x = ((A*x + B) % M);
			y = ((C*y + D) % M);
		}

		FOR (i, 0, 3)
			FOR (j, 0, 3)
				res += pole[i][j]*(pole[i][j]-1)*(pole[i][j]-2)/6;
		FOR (i, 0, 3)
			res += pole[i][0]*pole[i][1]*pole[i][2] + pole[0][i]*pole[1][i]*pole[2][i];
		FOR (i, 0, 3)
			res += pole[0][0+i]*pole[1][(1+i)%3]*pole[2][(2+i)%3] + pole[2][0+i]*pole[1][(1+i)%3]*pole[0][(2+i)%3];

		cout << "Case #" << icase+1 << ": " << res << endl;
	}

	return 0;
}
