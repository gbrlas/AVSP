#include "..\..\my_header.h"


class solver
{
public:

	double dist(int x1, int y1, int x2, int y2)
	{
		int dx = x1 - x2;
		int dy = y1 - y2;

		return sqrt(double(dx * dx + dy * dy));
	}

	double solve(int N, int_v &X, int_v &Y, int_v &R)
	{
		if (N == 1)
			return R[0];

		if (N == 2)
			return max(R[0], R[1]);

		if (N > 3)
			return 0;

		double min_r = 1000000;

		for (int i_e=0 ; i_e < 3 ; i_e++)
		{
			int i_i1 = i_e == 0 ? 1 : 0;
			int i_i2 = i_e == 2 ? 1 : 2;

			double r1_2 = dist(X[i_i1], Y[i_i1], X[i_i2], Y[i_i2]) + R[i_i1] + R[i_i2];
			double r1 = r1_2 / 2;

			double r = r1 > R[i_e] ? r1 : R[i_e];

			if (r < min_r)
				min_r = r;
		}

		return min_r;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
	int N;
	read1(N);

	int_v X(N), Y(N), R(N);

	for (int i=0 ; i < N ; i++)
		read3(X[i], Y[i], R[i]);

	double res = solver().solve(N, X, Y, R);

	cout << "Case #" << case_num << ": " << res << endl;
	ofs << "Case #" << case_num << ": " << res << endl;
}

/*************************************************************************************/

void main(int argc, char **argv)
{
	ifstream ifs(argv[1], ifstream::in);
	ofstream ofs(argv[2]);

	ofs.precision(7);
	ofs << fixed;

	int n = to_int(get_line(ifs));

	assert(n > 0 && n < 200);

	for (int i=0 ; i < n ; i++)
	{
		if (i > 0)
			cout << "\n---------------------------------------------\n\n";
		process_test_case(i+1, ifs, ofs);
	}
}
