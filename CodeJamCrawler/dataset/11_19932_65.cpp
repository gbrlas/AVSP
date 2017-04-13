#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>

using namespace std;

typedef vector<string> Result;

Result solveOne(const vector<string>& input)
{
	Result res = input;

	for (int y = 0; y < input.size() - 1; y++)  {
		for (int x = 0; x < input[y].size() - 1; x++)  {
			char& px = res[y][x];
			if (px == '#')  {
				char& top_right = res[y][x + 1];
				char& bot_left = res[y + 1][x];
				char& bot_right = res[y + 1][x + 1];
				if (top_right == '#' && bot_left == '#' && bot_right == '#')  {
					px = '/';
					top_right = '\\';
					bot_left = '\\';
					bot_right = '/';
				} else {
					res.clear();
					res.push_back("Impossible");
					return res;
				}
			}
		}
	}

	for (int y = 0; y < res.size(); y++)  {
		for (int x = 0; x < res[y].size(); x++)  {
			if (res[y][x] == '#')  {
				res.clear();
				res.push_back("Impossible");
				return res;
			}
		}
	}

	return res;
}

list<Result> solve(const std::string& file)
{
	list<Result> res;
	std::ifstream fp;
	fp.open(file);
	if (!fp.is_open())
		return res;

	int tests;
	fp >> tests; fp.ignore();
	for (int i = 0; i < tests; ++i)  {
		int rows, cols;
		fp >> rows;
		fp >> cols;

		vector<string> image;
		for (int j = 0; j < rows; j++)  {
			string row;
			fp >> row;
			fp.ignore();
			image.push_back(row);
		}

		res.push_back(solveOne(image));
	}

	return res;
}

void printResults(const list<Result>& res)
{
	int i = 1;
	for (auto it = res.cbegin(); it != res.cend(); ++it, ++i)  {
		cout << "Case #" << i << ":";
		for (auto it2 = it->cbegin(); it2 != it->cend(); ++it2)  {
			cout << "\n" << *it2;
		}
		cout << "\n";
	}
	cout.flush();
}

int main(int argc, const char *argv[])
{
	if (argc < 2)
		return -1;

	auto res = solve(argv[1]);
	printResults(res);

#ifdef _DEBUG
	getchar();
#endif

	return 0;
}
