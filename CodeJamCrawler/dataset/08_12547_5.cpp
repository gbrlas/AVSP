#include <fstream>
#include <iostream>
#include <utility>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	ifstream f("D-small-attempt1.in.txt");

	int N;
	f >> N;
	for(int i = 1; i <= N; ++i)
	{
		int H, W, R;
		f >> H >> W >> R;

		std::set<pair<int, int> > rocks;
		for(int r = 0; r < R; ++r)
		{
			pair<int, int> rock;
			f >> rock.first >> rock.second;
			rocks.insert(rock);
		}

		// Determine target moves
		int result = 0;
		if((2 * H - W - 1) % 3 == 0)
		{
			int targ_a = (2 * H - W - 1) / 3;
			int targ_b = H - 2 * targ_a - 1;
			if(targ_a >= 0 && targ_b >= 0)
			{
				int targ   = targ_a + targ_b;

				std::vector<int> ways(1, 1);
				int				 offset = 0;
				for(int m = 0; m < targ; ++m)
				{
					int base_row = 1 + 2 * m;
					int base_col = 1 + m;

					int new_m		 = m + 1;
					int new_base_row = 1 + 2 * new_m;
					int new_base_col = 1 + new_m;

					// Calculate the first index using <= than targ_a
					int first_index = (new_m < targ_a) ? 0 : (new_m - targ_a);
					int last_index  = (new_m < targ_b) ? new_m : targ_b;

					// Calculate the new number of ways
					std::vector<int> new_ways(last_index - first_index + 1, 0);
					for(int j = first_index; j <= last_index; ++j)
					{
						// If this is a rock, clear it
						if(rocks.count(pair<int, int>(new_base_row - j, new_base_col + j)) == 0)
						{
							if(j > 0)
								new_ways[j - first_index] += ways[j - offset - 1];
							if(j < new_m)
								new_ways[j - first_index] += ways[j - offset];
						}

						new_ways[j - first_index] %= 10007;
					}

					// Adjust
					ways.swap(new_ways);
					offset = first_index;
				}

				// Determine the result
				int base_col = 1 + targ;
				int index	 = W - base_col;
				result		 = ways[index - offset];
			}
		}

		cout << "Case #" << i << ": " << result << endl;
	}
	
	return 0;
}
