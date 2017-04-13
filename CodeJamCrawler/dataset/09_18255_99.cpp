#include "..\..\my_header.h"


class solver
{
public:
	int H;
	int W;
	vector<int_v> elmap;

	solver(int H, int W, vector<int_v> &elmap) : H(H), W(W), elmap(elmap) {}

	vector<char_v> solve()
	{
		int_v sink_rows;
		int_v sink_cols;

		for (int row=0 ; row < H ; row++)
			for (int col=0 ; col < W ; col++)
				if (is_sink(row, col))
				{
					sink_rows.push_back(row);
					sink_cols.push_back(col);
				}

		int nb = sink_rows.size();

		assert(nb >= 1 && nb <= 26);

		vector<char_v> bmap = rep_vector(rep_vector(' ', W), H);

		for (int r=0 ; r < H ; r++)
			for (int c=0 ; c < W ; c++)
				assert(bmap[r][c] == ' ');

		for (int i=0 ; i < nb ; i++)
		{
			char ch = 'a' + i;
			int_v qr;
			int_v qc;

			qr.push_back(sink_rows[i]);
			qc.push_back(sink_cols[i]);

			while (qr.size() > 0)
			{
				assert(qr.size() == qc.size());

				int row = qr[qr.size()-1];
				int col = qc[qc.size()-1];

				qr.pop_back();
				qc.pop_back();
				
				assert(bmap[row][col] == ' ');

				bmap[row][col] = i;

				record_if_flows_here(row-1, col,   row, col, qr, qc);
				record_if_flows_here(row+1, col,   row, col, qr, qc);
				record_if_flows_here(row,   col-1, row, col, qr, qc);
				record_if_flows_here(row,   col+1, row, col, qr, qc);
			}
		}

		for (int r=0 ; r < H ; r++)
			for (int c=0 ; c < W ; c++)
				assert(bmap[r][c] != ' ');

		char_v n_to_c = rep_vector('\0', nb);

		assert(n_to_c.size() == nb);

		char next = 'a';
		for (int r=0 ; r < H ; r++)
			for (int c=0 ; c < W ; c++)
				if (n_to_c[bmap[r][c]] == '\0')
				{
					assert(next <= 'z');
					n_to_c[bmap[r][c]] = next;
					next++;
				}

		for (int i=0 ; i < nb ; i++)
			assert(islower(n_to_c[i]));

		for (int r=0 ; r < H ; r++)
			for (int c=0 ; c < W ; c++)
				bmap[r][c] = n_to_c[bmap[r][c]];

		return bmap;
	}

	void record_if_flows_here(int row, int col, int dest_row, int dest_col, int_v &qr, int_v &qc)
	{
		if (flows_here(row, col, dest_row, dest_col))
		{
			qr.push_back(row);
			qc.push_back(col);
		}
	}

	bool flows_here(int row, int col, int dest_row, int dest_col)
	{
		if (!is_valid(row, col))
			return false;

		int to_row, to_col;
		flows_to(row, col, to_row, to_col);
		return to_row == dest_row && to_col == dest_col;
	}

	void flows_to(int row, int col, int &to_row, int &to_col)
	{
		assert(is_valid(row, col));

		int el = elmap[row][col];

		int lowest = el;

		to_row = row;
		to_col = col;

		try_dir(row-1, col  , lowest, to_row, to_col);
		try_dir(row,   col-1, lowest, to_row, to_col);
		try_dir(row,   col+1, lowest, to_row, to_col);
		try_dir(row+1, col  , lowest, to_row, to_col);
	}

	void try_dir(int r, int c, int &lowest, int &to_row, int &to_col)
	{
		if (is_lower(r, c, lowest))
		{
			to_row = r;
			to_col = c;
			lowest = elmap[r][c];
		}
	}

	bool is_lower(int row, int col, int val)
	{
		return is_valid(row, col) && elmap[row][col] < val;
	}

	bool is_valid(int row, int col)
	{
		return row >= 0 && row < H && col >= 0 && col < W;
	}

	bool is_sink(int row, int col)
	{
		int el = elmap[row][col];

		return	!is_lower(row+1, col, el) &&
				!is_lower(row-1, col, el) &&
				!is_lower(row, col+1, el) &&
				!is_lower(row, col-1, el);				
	}
};

/*************************************************************************************/

template <typename T> vector<T> intermix(const vector<T> &vs, const T &v)
{
	int n = vs.size();

	vector<T> res(2*n - 1);

	for (int i=0 ; i < n ; i++)
		res[2*i] = vs[i];

	for (int i=0 ; i < n-1 ; i++)
		res[2*i + 1] = v;

	return res;
}

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
	int_v hw = get_ints(ifs);
	int H = hw[0];
	int W = hw[1];

	vector<int_v> elmap(H);

	for (int i=0 ; i < H ; i++)
	{
		elmap[i] = get_ints(ifs);
		assert(elmap[i].size() == W);
	}

	vector<char_v> bmap = solver(H, W, elmap).solve();

	ofs << "Case #" << case_num << ": " << endl;
	for (int r=0 ; r < H ; r++)
		ofs << to_string_from_char_v(intermix(bmap[r], ' ')) << endl;
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
