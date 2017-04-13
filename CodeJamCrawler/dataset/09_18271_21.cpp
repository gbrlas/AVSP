#include "..\..\my_header.h"


class solver
{
public:

	int solve(int N, str_v &m)
	{
		int_v h_pos(N);
		for (int i=0 ; i < N ; i++)
			for (int j=N-1 ; j >= 0 ; j--)
				if (m[i][j] != '0')
				{
					h_pos[i] = j;
					break;
				}

		int moves = 0;
		for (int i=0 ; i < N-1 ; i++)
			if (h_pos[i] > i)
			{
				int first = -1;
				for (int j=i+1 ; j < N ; j++)
					if (h_pos[j] <= i)
					{
						first = j;
						break;
					}

				assert(first != -1);

				moves += first - i;

				int tmp = h_pos[first];
				for (int j=first ; j > i ; j--)
					h_pos[j] = h_pos[j-1];
				h_pos[i] = tmp;
			}

		return moves;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
	int N;
	read1(N);

	str_v m(N);
	repeat(i, N)
		m[i] = get_line(ifs);

	int res = solver().solve(N, m);

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
