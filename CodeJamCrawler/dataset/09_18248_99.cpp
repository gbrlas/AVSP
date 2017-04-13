#include "..\..\my_header.h"


class solver
{
public:

	int solve(int L, int D, str_v &words, string &pattern)
	{
		str_v ptrns(L);

		int start = 0;

		for (int i=0 ; i < L ; i++)
		{
			assert(start < pattern.length());

			if (pattern[start] == '(')
			{
				int end = start + 1;

				for ( ; ; end++)
				{
					assert(end < pattern.length());

					if (pattern[end] == ')')
						break;
				}

				ptrns[i] = sort_chars(pattern.substr(start+1, end-start-1));
				start = end + 1;
			}
			else
			{
				ptrns[i] = sort_chars(pattern.substr(start, 1));
				start++;
			}
		}

		int_v idxs = inc_vector(0, words.size());

		for (int i=0 ; i < L ; i++)
			idxs = filter(idxs, words, ptrns[i], i);

		return idxs.size();
	}

	int_v filter(int_v &indexes, str_v &words, string &chars, int letter)
	{
		int_v fidxs;
		for (int ii=0 ; ii < indexes.size() ; ii++)
		{
			int idx = indexes[ii];
			int curr_char = words[idx][letter];

			for (int ic=0 ; ic < chars.length() ; ic++)
				if (curr_char == chars[ic])
				{
					fidxs.push_back(idx);
					break;
				}
		}

		return fidxs;
	}

	string sort_chars(string &str)
	{
		char_v cs = to_char_v(str);
		sort(cs);
		return to_string_from_char_v(cs);
	}
};

/*************************************************************************************/

void process_test_case(int L, int D, str_v &words, int case_num, ifstream &ifs, ofstream &ofs)
{
	string pattern = get_line(ifs);

	int res = solver().solve(L, D, words, pattern);

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

	int_v ns = to_ints(get_line(ifs));

	int L = ns[0];
	int D = ns[1];
	int N = ns[2];

	str_v words(D);
	for (int i=0 ; i < D ; i++)
		words[i] = get_line(ifs);
	sort(words);

	for (int i=0 ; i < N ; i++)
	{
		if (i > 0)
			cout << "\n---------------------------------------------\n\n";
		process_test_case(L, D, words, i+1, ifs, ofs);
	}
}
