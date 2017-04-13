#include <iostream>
#include <string>
using namespace std;

string Dump(long long v)
{
	if(v == 0)
		return "0";

	string ret;
	while(v > 0)
	{
		ret.insert(ret.begin(), '0' + v % 10);
		v /= 10;
	}

	return ret;
}

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		int n, A, B, C, D, x0, y0, M;
		cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;

		int p[3][3] = { 0 };

		long long X = x0;
		long long Y = y0;
		do
		{
			++p[X % 3][Y % 3];
			X = (A * X + B) % M;
			Y = (C * Y + D) % M;
		}
		while(--n != 0);

		long long ret = 0;
		for(int a = 0; a < 9; ++a)
		{
			long long this_mult_a = p[a / 3][a % 3];
			--p[a / 3][a % 3];
			for(int b = 0; b < 9; ++b)
			{
				long long this_mult_b = this_mult_a * p[b / 3][b % 3];
				--p[b / 3][b % 3];
				for(int c = 0; c < 9; ++c)
				{
					long long this_mult_c = this_mult_b * p[c / 3][c % 3];
					--p[c / 3][c % 3];

					int this_x = (a / 3) + (b / 3) + (c / 3);
					int this_y = (a % 3) + (b % 3) + (c % 3);
					if(((this_x % 3) == 0) && ((this_y % 3) == 0))
						ret += this_mult_c;

					++p[c / 3][c % 3];
				}

				++p[b / 3][b % 3];
			}

			++p[a / 3][a % 3];
		}

		// We will have all permutations!
		ret /= 6;

		cout << "Case #" << (i + 1) << ": " << Dump(ret) << endl;
	}

	return 0;
}
