#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <boost/detail/workaround.hpp>
#include <boost/math/common_factor.hpp> 

using namespace std;

typedef long long Result;
typedef long long Tone;

Result solveOne(Tone low, Tone high, vector<Tone>& others)
{
	for (Tone t = low; t <= high; t++)  {
		bool all = true;
		for (auto it = others.begin(); it != others.end(); it++)  {
			if (t % (*it) == 0 || (*it) % t == 0) {
			} else {
				all = false;
				break;
			}
		}

		if (all)  {
			return t;
		}
	}

	return -1;
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
		int others;
		Tone low, high;
		fp >> others;
		fp >> low;
		fp >> high;
		
		assert(fp.good());

		vector<Tone> otherTones;
		for (int i = 0; i < others; i++)  {
			Tone t;
			fp >> t;
			otherTones.push_back(t);
		}

		res.push_back(solveOne(low, high, otherTones));
	}

	return res;
}

void printResults(const list<Result>& res)
{
	int i = 1;
	for (auto it = res.cbegin(); it != res.cend(); ++it, ++i)  {
		if (*it == -1)
			cout << "Case #" << i << ": NO\n";
		else 
			cout << "Case #" << i << ": " << *it << "\n";
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
