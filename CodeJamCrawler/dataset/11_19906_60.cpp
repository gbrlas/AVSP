#include <iostream>
#include <string>
#include <fstream>
#include "TestCase.h"

std::list<TestCase *> loadData(const std::string& file)
{
	std::list<TestCase *> res;
	std::ifstream fp;
	fp.open(file);
	if (!fp.is_open())
		return res;

	int count;
	fp >> count;
	fp.ignore(1);

	for (int i = 0; i < count; ++i)  {
		std::string line;
		std::getline(fp, line);
		res.push_back(new TestCase(line));
	}

	return res;
}


int main(int argc, const char* argv[])
{
	if (argc < 2)  {
		std::cout << "Expected filename as the first parameter" << std::endl;
		return 0;
	}
	std::list<TestCase *> cases = loadData(argv[1]);
	int i = 1;
	for (std::list<TestCase *>::iterator it = cases.begin(); it != cases.end(); ++it, ++i)  {
		std::cout << "Case #" << i << ": " << (*it)->solve() << "\n";
		delete (*it);
	}
	std::cout.flush();
#ifdef _DEBUG
	getchar();
#endif
	return 0;
}