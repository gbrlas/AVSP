#include "..\..\my_header.h"


class solver
{
public:

	string solve(int N, int M, int A)
	{
		int x1, y1, x2, y2, x3, y3;

		y1 = 0;
		x2 = 0;

		for (x1 = 0 ; x1 <= N ; x1++)
			for (y2 = 0 ; y2 <= M ; y2++)
				for (x3 = 0 ; x3 <= N ; x3++)
					for (y3 = 0 ; y3 <= M ; y3++)
						if (!(x1 == 0 && y1 == 0))
						{
							int a;

							if (x3 >= x1)
							{
								a = x3 * (y2 + y3) - (x3 - x1) * y3 - x1 * y2;
							}
							else
							{
								bool is_above;

								if (y3 >= y2)
								{
									is_above = true;
								}
								else
								{
									is_above = x3 * y3 >= (y2 - y3) * (x1 - x3);
								}

								if (is_above)
								{
									a = x3 * (y2 + y3) + (x1 - x3) * y3 - x1 * y2;
								}
								else
								{
									a = x3 * (y2 + y3) + (x1 - x3) * y3;
								}
							}

							if (a == A)
								return to_string(make_array(x1, y1, x2, y2, x3, y3));
						}

		return "IMPOSSIBLE";
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
	int N, M, A;
	read3(N, M, A);

	string res = solver().solve(N, M, A);

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

	assert(n > 0 && n <= 1000);

	for (int i=0 ; i < n ; i++)
	{
		if (i > 0)
			cout << "\n---------------------------------------------\n\n";
		process_test_case(i+1, ifs, ofs);
	}
}
