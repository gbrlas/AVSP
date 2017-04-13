#include "..\..\my_header.h"


class solver
{
public:
	int M, V;

	int nnodes;
	int nleaves;

	int_v node_types;
	int_v node_changable;

	int_v leave_values;

	void min_changes(int node, int &min_changes_for_0, int &min_changes_for_1)
	{
		min_changes_for_0 = INT_MAX;
		min_changes_for_1 = INT_MAX;

		if (node >= nnodes)
		{
			if (leave_values[node - nnodes] == 0)
				min_changes_for_0 = 0;
			else
				min_changes_for_1 = 0;

			return;
		}

		bool is_and = node_types[node] == 1;
		bool changeable = node_changable[node] == 1;

		int left_node = 2 * (node + 1) - 1;
		int right_node = left_node + 1;

		int min_left_changes_for_0;
		int min_left_changes_for_1;
		int min_right_changes_for_0;
		int min_right_changes_for_1;

		min_changes(left_node, min_left_changes_for_0, min_left_changes_for_1);
		min_changes(right_node, min_right_changes_for_0, min_right_changes_for_1);


		if (is_and || changeable)
		{
			if (min_left_changes_for_0 != INT_MAX || min_right_changes_for_0 != INT_MAX)
			{
				min_changes_for_0 = min(min_left_changes_for_0, min_right_changes_for_0);
				if (!is_and)
					min_changes_for_0++;
			}

			if (min_left_changes_for_1 != INT_MAX && min_right_changes_for_1 != INT_MAX)
			{
				min_changes_for_1 = min_left_changes_for_1 + min_right_changes_for_1;
				if (!is_and)
					min_changes_for_1++;
			}
		}

		if (!is_and || changeable)
		{
			if (min_left_changes_for_0 != INT_MAX && min_right_changes_for_0 != INT_MAX)
			{
				int min_changes_for_0_bis = min_left_changes_for_0 + min_right_changes_for_0;
				if (is_and)
					min_changes_for_0_bis++;

				min_changes_for_0 = min(min_changes_for_0_bis, min_changes_for_0);
			}

			if (min_left_changes_for_1 != INT_MAX || min_right_changes_for_1 != INT_MAX)
			{
				int min_changes_for_1_bis = min(min_left_changes_for_1, min_right_changes_for_1);
				if (is_and)
					min_changes_for_1_bis++;

				min_changes_for_1 = min(min_changes_for_1_bis, min_changes_for_1);
			}
		}
	}

	int solve()
	{
		int min_changes_for_0, min_changes_for_1;

		min_changes(0, min_changes_for_0, min_changes_for_1);

		if (V == 0)
			return min_changes_for_0;
		else
			return min_changes_for_1; 
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
	solver s;

	read2(s.M, s.V);

	s.nnodes = (s.M - 1) / 2;
	s.nleaves = (s.M + 1) / 2;

	s.node_types.resize(s.nnodes);
	s.node_changable.resize(s.nnodes);
	s.leave_values.resize(s.nleaves);

	repeat(i, s.nnodes)
		read2(s.node_types[i], s.node_changable[i]);

	repeat(i, s.nleaves)
		read1(s.leave_values[i]);

	int nc = s.solve();

	string res = to_string(nc);
	if (nc == INT_MAX)
		res = "IMPOSSIBLE";

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
