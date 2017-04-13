#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "TestCase.h"

std::list<TestCase::Output> loadAndSolve(const std::string& file)
{
	std::list<TestCase::Output> res;
	std::ifstream fp;
	fp.open(file);
	if (!fp.is_open())
		return res;

	int testCount;
	fp >> testCount;
	fp.ignore();

	for (int i = 0; i < testCount; ++i)  {
		int C;
		fp >> C;
		fp.ignore(1);

		TestCase *tc = new TestCase();

		for (int j = 0; j < C; ++j)  {
			std::string combine;
			fp >> combine;
			tc->addCombine((element)combine[0], (element)combine[1], (element)combine[2]);
			fp.ignore(1);
		}

		int D;
		fp >> D;
		fp.ignore(1);

		for (int j = 0; j < D; ++j)  {
			std::string opposite;
			fp >> opposite;
			tc->addOpposite((element)opposite[0], (element)opposite[1]);
			fp.ignore(1);
		}

		int N;
		fp >> N;
		fp.ignore(1);
		std::string input;
		if (N)  {
			fp >> input;
			fp.ignore(1);
			assert(input.size() == N);
		}

		TestCase::Output output;
		tc->solve(input, output);
		res.push_back(output);
		delete tc;
	}

	fp.close();
	return res;
}

void printResults(const std::list<TestCase::Output>& res)
{
	int i = 1;
	for (std::list<TestCase::Output>::const_iterator it = res.begin(); it != res.end(); ++it, ++i)  {
		std::cout << "Case #" << i << ": [";
		bool printcomma = false;
		for (TestCase::Output::const_iterator resit = it->begin(); resit != it->end(); ++resit)  {
			if (printcomma)  {
				std::cout << ", ";
			}
			printcomma = true;
			std::cout << (char)(*resit);
		}
		std::cout << "]\n";
	}
	std::cout.flush();
}

int main(int argc, const char *argv[])
{
	if (argc < 2) {
		std::cout << "Expected a file in the first argument" << std::endl;
		return -1;
	}

	std::list<TestCase::Output> res = loadAndSolve(argv[1]);
	printResults(res);

#ifdef _DEBUG
	getchar();
#endif

	return 0;
}
