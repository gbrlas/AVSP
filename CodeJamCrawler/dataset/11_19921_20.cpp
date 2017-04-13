#include <iostream>
#include <fstream>
#include <list>

bool decide(unsigned long long N, int Pd, int Pg)
{
	if (Pg == 0)
		return Pd == 0;
	if (Pg == 100)
		return Pd == 100;

	if (N < 100)  {
		for (int i = 2; i <= N; ++i)  {
			if ((i * Pd) % 100 == 0)
				return true;
		}
		return false;
	}
	return true;
}

std::list<bool> solve(const std::string& file)
{
	std::list<bool> res;
	std::ifstream fp;
	fp.open(file);
	if (!fp.is_open())
		return res;

	int tests;
	fp >> tests; fp.ignore();
	for (int i = 0; i < tests; ++i)  {
		unsigned long long N;
		int Pd, Pg;
		fp >> N; fp.ignore();
		fp >> Pd; fp.ignore();
		fp >> Pg; fp.ignore();
		res.push_back(decide(N, Pd, Pg));
	}

	return res;
}

void printResults(const std::list<bool>& res)
{
	int i = 1;
	for (auto it = res.cbegin(); it != res.cend(); ++it, ++i)  {
		std::cout << "Case #" << i << ":" << (*it ? " Possible" : " Broken") << "\n";
	}
	std::cout.flush();
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