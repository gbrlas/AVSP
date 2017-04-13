#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

const int dir_h[] = {-1, 0, 0, 1};
const int dir_w[] = {0, -1, 1, 0};

int main()
{
	ifstream in("B.in");
	ofstream out("B.out");

	int map[100][100];
	char drain[100][100];

	int tests;
	in >> tests;
	for (int i=1; i<=tests; i++)
	{
		int height, width;
		in >> height >> width;

		for (int j=0; j<height; j++)
			for (int k=0; k<width; k++)
			{
				in >> map[j][k];
				drain[j][k] = ' ';
			}

		char nextBasin = 'a';

		for (int j=0; j<height; j++)
			for (int k=0; k<width; k++)
				if (drain[j][k] == ' ')
				{
					stack<pair<int, int> > trace;
					trace.push(make_pair(j, k));

					int h = j, w = k;
					for (;;)
					{
						bool basin = true;
						int best_h = -1, best_w = -1;

						for (int x=0; x<4; x++)
							if (h + dir_h[x] >= 0 && h + dir_h[x] < height && w + dir_w[x] >= 0 && w + dir_w[x] < width &&
								map[h + dir_h[x]][w + dir_w[x]] < map[h][w] && (basin || map[best_h][best_w] > map[h + dir_h[x]][w + dir_w[x]]))
							{
								basin = false;
								best_h = h + dir_h[x];
								best_w = w + dir_w[x];
							}

						if (basin)
							break;
						else
						{
							trace.push(make_pair(best_h, best_w));
							h = best_h;
							w = best_w;
						}
					}

					pair<int, int> basin = trace.top();
					char curBasin = nextBasin;
					if (drain[basin.first][basin.second] == ' ')
						nextBasin++;
					else
						curBasin = drain[basin.first][basin.second];

					while (trace.size() > 0)
					{
						pair<int, int> pos = trace.top();
						trace.pop();
						drain[pos.first][pos.second] = curBasin;
					}
				}

		out << "Case #" << i << ":" << endl;
		for (int j=0; j<height; j++)
		{
			for (int k=0; k<width; k++)
				out << drain[j][k] << " ";
			out << endl;
		}
	}
}
