#include <fstream>

using namespace std;

ifstream ifs("A-large.in");
ofstream ofs("A-large.out");

long long cc[3][3];

void gen(int n, int a, int b, int c, int d, int x0, int y0, int m)
{
	long long x = x0, y = y0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cc[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		++cc[x % 3][y % 3];
		x = (a * x + b) % m;
		y = (c * y + d) % m;
	}
}

int main(void)
{
	int re;
	int n, a, b, c, d, x0, y0, m;
	long long ans;

	ifs >> re;
	for (int ri = 1; ri <= re; ri++) {
		ifs >> n >> a >> b >> c >> d >> x0 >> y0 >> m;
		gen(n, a, b, c, d, x0, y0, m);
		ans = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				ans += cc[i][j] * (cc[i][j] - 1) * (cc[i][j] - 2) / 6;
			}
		}
		for (int i = 0; i < 3; i++) {
			ans += cc[i][0] * cc[i][1] * cc[i][2];
			ans += cc[0][i] * cc[1][i] * cc[2][i];
		}
		ans += cc[0][0] * cc[1][1] * cc[2][2];
		ans += cc[0][0] * cc[1][2] * cc[2][1];
		ans += cc[0][1] * cc[1][0] * cc[2][2];
		ans += cc[0][1] * cc[1][2] * cc[2][0];
		ans += cc[0][2] * cc[1][0] * cc[2][1];
		ans += cc[0][2] * cc[1][1] * cc[2][0];
		ofs << "Case #" << ri << ": " << ans << endl;
	}

	return 0;
}


