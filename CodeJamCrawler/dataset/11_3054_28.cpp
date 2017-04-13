#include <fstream>
using std :: ifstream;
using std :: ofstream;
#include <string>
using std :: string;

const int MAX_SIZE_X = 55;
const int MAX_SIZE_Y = 55;
const int OFFSET_X = 2;
const int OFFSET_Y = 2;


void solve (ofstream& output, int n, int size_x, int size_y,
			char map[MAX_SIZE_X][MAX_SIZE_Y])
{
	bool is_bad = false;
	for (int x = 0; x < size_x && !is_bad; ++x)
		for (int y = 0; y < size_y; ++y)
			if (map[x + 2][y + 2] == '#')
				if (map[x + 3][y + 2] == '#' &&
					map[x + 3][y + 3] == '#' &&
					map[x + 2][y + 3] == '#')
				{
					map[x + 2][y + 2] = '/';
					map[x + 3][y + 2] = '\\';
					map[x + 3][y + 3] = '/'; 
					map[x + 2][y + 3] = '\\';
				}
				else if (map[x + 2][y + 3] == '#' &&
						 map[x + 1][y + 3] == '#' &&
						 map[x + 1][y + 2] == '#')
				{
					map[x + 2][y + 2] = '\\';
					map[x + 2][y + 3] = '/';
					map[x + 1][y + 3] = '\\';
					map[x + 1][y + 2] = '/';
				}
				else if (map[x + 1][y + 2] == '#' &&
						 map[x + 1][y + 1] == '#' &&
						 map[x + 2][y + 1] == '#')
				{
					map[x + 2][y + 2] = '/';
					map[x + 1][y + 2] = '\\';
					map[x + 1][y + 1] = '/';
					map[x + 2][y + 1] = '\\';
				}
				else if (map[x + 2][y + 1] == '#' &&
						 map[x + 3][y + 1] == '#' &&
						 map[x + 3][y + 2] == '#')
				{
					map[x + 2][y + 2] = '\\';
					map[x + 2][y + 1] = '/';
					map[x + 3][y + 1] = '\\';
					map[x + 3][y + 2] = '/';
				}
				else
				{
					is_bad = true;
					break;
				}

	output << "Case #" << n + 1 << ":\n";
	if (is_bad)
		output << "Impossible\n";
	else
	{
		for (int x = 0; x < size_x; ++x)
		{
			for (int y = 0; y < size_y; ++y)
				output << map[x + 2][y + 2];
			output << '\n';
		}
	}
}

int main ()
{
	ifstream input ("input.txt");
	ofstream output ("output.txt");
	
	int all_query = 0;
	input >> all_query;
	for (int query = 0; query < all_query; ++query)
	{
		int size_x = 0,
			size_y = 0;
		input >> size_x >> size_y;
		char map[MAX_SIZE_X][MAX_SIZE_Y] = {{}};
		for (int i = 0; i < size_x; ++i)
		{
			string in_x_str;
			input >> in_x_str;
			for (int j = 0; j < size_y; ++j)
				map[i + 2][j + 2] = in_x_str[j];
		}

		solve (output, query, size_x, size_y, map);
	}

	return 0;
}