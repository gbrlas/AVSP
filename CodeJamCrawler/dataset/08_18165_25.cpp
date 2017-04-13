#include "my_header.h"


class solver
{
public:
	vector<int_v> decks;

	int_v solve(int n, int_v idxs)
	{
		decks.resize(n);

		for (int next = n ; next >= 1 ; next--)
			get_deck(next, n);

		int_v deck = decks[0];

		int_v res(idxs.size());

		repeat(i, idxs.size())
			res[i] = deck[idxs[i]-1];

		return res;
	}

	void get_deck(int next, int n)
	{
		int s = n - next + 1;

		int_v deck(s);

		if (next == n)
		{
			deck[0] = n;
			decks[n-1] = deck;
			return;
		}

		int pos = (next - 1) % s;
		deck[pos] = next;

		int left = pos;
		int right = s - pos - 1;

		int_v &deck2 = decks[next]; //+1, n);
		assert(deck2.size() > 0);

		for (int i=0 ; i < right ; i++)
			deck[i + pos + 1] = deck2[i];

		for (int i=0 ; i < left ; i++)
			deck[i] = deck2[i+right];

		decks[next-1] = deck;
	}


};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
	int n = get_int(ifs, "K");

	int_v idxs_ = get_ints(ifs, "indexes");
	int_v idxs(idxs_.size() - 1);
	repeat(i, idxs.size())
		idxs[i] = idxs_[i+1];

	int_v res = solver().solve(n, idxs);

	cout << "Case #" << case_num << ": " << to_string(res) << endl;
	ofs << "Case #" << case_num << ": " << to_string(res) << endl;
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
