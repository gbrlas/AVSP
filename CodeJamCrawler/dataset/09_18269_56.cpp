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

	string solve_(string str)
	{
		value = to_int(str);
		best = -1;

		process("", str);
		process("", str + "0");

		return to_string(best);
	}

	/**********************************************************************/

	string sort_chars(const string &s)
	{
		char_v cv = to_char_v(s);
		sort(cv);
		return to_string_from_char_v(cv);
	}

	string solve(string str)
	{
		int len = str.length();
		int nmax = 1;

		for (int i=1 ; i < len ; i++)
			if (str[len-i-1] >= str[len-i])
				nmax++;
			else
				break;

		assert(nmax <= len);

		if (nmax == len)
		{
			// Check if it's already the maximum

			str.push_back('0');

			str = sort_chars(str);

			assert(str[0] == '0');
			assert(str[str.size()-1] != '0');

			int first_non_0 = 0;
			while (str[first_non_0] == '0')
				first_non_0++;

			str[0] = str[first_non_0];
			str[first_non_0] = '0';

			return str;
		}

		string right = str.substr(len-nmax);
		char ch_to_change = str[len-nmax-1];
		string left = str.substr(0, len-nmax-1);

		int ch_to_swap_idx = right.length() - 1;
		assert(ch_to_swap_idx >= 0);
		while (right[ch_to_swap_idx] <= ch_to_change)
		{
			ch_to_swap_idx--;
			assert(ch_to_swap_idx >= 0);
		}

		int tmp = ch_to_change;

		ch_to_change = right[ch_to_swap_idx];
		right[ch_to_swap_idx] = tmp;

		right = sort_chars(right);

		string res = left + ch_to_change + right;

		return res;
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

	//assert(n > 0 && n < 200);

	for (int i=0 ; i < n ; i++)
	{
		if (i > 0)
			cout << "\n---------------------------------------------\n\n";
		process_test_case(i+1, ifs, ofs);
	}
}
