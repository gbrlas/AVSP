#include "my_header.h"


class solver
{
public:

	int solve(int A, int B, int P)
	{
		int n = B - A + 1;

		int_v gset(n);
		for (int i=0 ; i < n ; i++)
			gset[i] = A + i;

		for (int p=P; p <= B; p++)
			if (is_prime(p))
			{
				repeat(i, n)
				{
					int num = A + i;
					int pp = gset[i];

					if (num % p == 0 && pp != p)
					{
						repeat(i, n)
							if (gset[i] == pp)
								gset[i] = p;
					}
				}
		}

		int_v remcls = sort_and_remove_duplicates(gset);

		return remcls.size();
	}

	bool is_prime(int n)
	{
		for (int i=2 ; ; i++)
		{
			if (i * i > n)
				return true;

			if (n % i == 0)
				return false;
		}
	}
};


/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
	int_v inputs = get_ints(ifs);

	int res = solver().solve(inputs[0], inputs[1], inputs[2]);

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
