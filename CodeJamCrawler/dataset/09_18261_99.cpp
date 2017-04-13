#include "..\..\my_header.h"


class solver
{
public:

	int solve(string &line)
	{
		string mstr("welcome to code jam");
		int ml = mstr.length();

		int ll = line.length();

		vector<int_v> ocs = rep_vector(rep_vector(0, ml), ll);

		// ocs[n][m] = number of times the last m+1 letters of the message appear
		//             in the last n+1 chars of the input string

		ocs[0][0] = line[ll-1] == mstr[ml-1] ? 1 : 0;

		for (int il=1 ; il < ll ; il++)
		{
			for (int im=0 ; im < ml ; im++)
			{
				int res = ocs[il-1][im];

				if (line[ll-il-1] == mstr[ml-im-1])
					if (im == 0)
						res += 1;
					else
						res += ocs[il-1][im-1];

				ocs[il][im] = res % 10000;
			}
		}

		return ocs[ll-1][ml-1];
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
	string line = get_line(ifs);

	int res = solver().solve(line);

	char buff[120];

	sprintf(buff, "%04d", res);

	cout << "Case #" << case_num << ": " << buff << endl;
	ofs << "Case #" << case_num << ": " << buff << endl;
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
