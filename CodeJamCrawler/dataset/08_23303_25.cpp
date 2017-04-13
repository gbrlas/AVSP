#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;

vector<int> nodes;
vector<int> change;
vector<pair<int, int> > swaps;

const int inf = 99999999;

int changes(int index, bool outcome)
{
	if (outcome && swaps[index].first == -2)
	{
		int moves = -1;

		if (nodes[index] == 1 || change[index] == 1)
		{
			if (changes(index * 2 + 1, true) != -1 && changes(index * 2 + 2, true) != -1)
			{
				int pos = changes(index * 2 + 1, true) + changes(index * 2 + 2, true);
				if (nodes[index] == 0)
					pos++;

				if (moves == -1 || (pos != -1 && pos < moves))
					moves = pos;
			}
		}

		if (nodes[index] == 0 || change[index] == 1)
		{
			int pos;
				
			if (changes(index * 2 + 1, true) != -1 && changes(index * 2 + 2, true) != -1)
			{
				pos	= changes(index * 2 + 1, true) + changes(index * 2 + 2, true);
				if (nodes[index] == 1)
					pos++;

				if (moves == -1 || (pos != -1 && pos < moves))
					moves = pos;
			}

			if (changes(index * 2 + 1, true) != -1 && changes(index * 2 + 2, false) != -1)
			{
				pos = changes(index * 2 + 1, true) + changes(index * 2 + 2, false);
				if (nodes[index] == 1)
					pos++;

				if (moves == -1 || (pos != -1 && pos < moves))
					moves = pos;
			}

			if (changes(index * 2 + 1, false) != -1 && changes(index * 2 + 2, true) != -1)
			{
				pos = changes(index * 2 + 1, false) + changes(index * 2 + 2, true);
				if (nodes[index] == 1)
					pos++;

				if (moves == -1 || (pos != -1 && pos < moves))
					moves = pos;
			}
		}

		swaps[index] = make_pair(moves, swaps[index].second);
	}
	else if (!outcome && swaps[index].second == -2)
	{
		int moves = -1;

		if (nodes[index] == 0 || change[index] == 1)
		{
			if (changes(index * 2 + 1, false) != -1 && changes(index * 2 + 2, false) != -1)
			{
				int pos = changes(index * 2 + 1, false) + changes(index * 2 + 2, false);
				if (nodes[index] == 1)
					pos++;

				if (moves == -1 || (pos != -1 && pos < moves))
					moves = pos;
			}
		}

		if (nodes[index] == 1 || change[index] == 1)
		{
			int pos;

			if (changes(index * 2 + 1, false) != -1 && changes(index * 2 + 2, false) != -1)
			{
				pos = changes(index * 2 + 1, false) + changes(index * 2 + 2, false);
				if (nodes[index] == 0)
					pos++;

				if (moves == -1 || (pos != -1 && pos < moves))
					moves = pos;
			}

			if (changes(index * 2 + 1, true) != -1 && changes(index * 2 + 2, false) != -1)
			{
				pos = changes(index * 2 + 1, true) + changes(index * 2 + 2, false);
				if (nodes[index] == 0)
					pos++;

				if (moves == -1 || (pos != -1 && pos < moves))
					moves = pos;
			}

			if (changes(index * 2 + 1, false) != -1 && changes(index * 2 + 2, true) != -1)
			{
				pos = changes(index * 2 + 1, false) + changes(index * 2 + 2, true);
				if (nodes[index] == 0)
					pos++;

				if (moves == -1 || (pos != -1 && pos < moves))
					moves = pos;
			}
		}

		swaps[index] = make_pair(swaps[index].first, moves);
	}

	if (outcome)
		return swaps[index].first;
	else
		return swaps[index].second;
}

int main()
{
	int tests;

	cin >> tests;
	for (int t=1; t<=tests; t++)
	{
		int n, outcome;
		cin >> n >> outcome;

		nodes.clear();
		nodes.resize(n);
		change.clear();
		change.resize(n);
		swaps.clear();
		swaps.resize(n, make_pair(-2, -2));

		for (int i=0; i<(n-1)/2; i++)
		{
			cin >> nodes[i] >> change[i];
//			nodes[i] += 2;
		}

		for (int i=(n-1)/2; i<n; i++)
		{
			cin >> nodes[i];
			swaps[i] = make_pair(nodes[i] == 1 ? 0 : -1, nodes[i] == 0 ? 0 : -1);
		}

		int result = changes(0, outcome == 1);

		if (result != -1)
			cout << "Case #" << t << ": " << result << endl;
		else
			cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
	}

	return 0;
}