#include "..\..\my_header.h"


class solver
{
public:
	int value;
	int best;
	//string best_str;

	void process(const string &str, const string &unused)
	{
		if (unused == "")
		{
			int v = to_int(str);

			if (v > value)
			{
				if (best == -1 || v < best)
					best = v;
			}

			return;
		}

		for (int i=0 ; i < unused.length() ; i++)
		{
			string new_str = str + unused[i];
			string new_unused = unused.substr(0, i) + unused.substr(i+1);

			process(new_str, new_unused);
		}
	}

	string solve(string str)
	{
		value = to_int(str);
		best = -1;

		process("", str);
		process("", str + "0");

		return to_string(best);
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
	str_v strs = get_strs(ifs);

	assert(strs.size() == 1);

	string res = solver().solve(strs[0]);

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
