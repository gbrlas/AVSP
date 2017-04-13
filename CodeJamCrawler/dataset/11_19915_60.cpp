#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

double solve(std::vector<int>& input)
{
  int writes = 0;
 
  // Loop through the array to find cycles to rotate.
  for (int cycleStart = 0; cycleStart < (int)input.size(); ++cycleStart) {
    int item = input[cycleStart];
 
    // Find where to put the item.
    int pos = cycleStart;
    for (int i = cycleStart + 1; i < (int)input.size(); ++i)  {
      if (input[i] < item)
        pos++;
	}
 
    // If the item is already there, this is not a cycle.
    if (pos == cycleStart)
      continue;
 
    // Otherwise, put the item there or right after any duplicates.
    while (item == input[pos])  {
      pos++;
	}
	std::swap(input[pos], item);
    writes++;
 
    // Rotate the rest of the cycle.
    while (pos != cycleStart)  {
 
      // Find where to put the item.
      pos = cycleStart;
	  for (int i = cycleStart + 1; i < (int)input.size(); ++i)  {
        if (input[i] < item)  {
          pos++;
		}
	  }
 
      // Put the item there or right after any duplicates.
      while (item == input[pos])  {
        pos++;
	  }
	  std::swap(input[pos], item);
      writes++;
	}
  }
 
  return writes;
}

std::list<double> loadAndSolve(const std::string& file)
{
	std::list<double> res;
	std::ifstream fp;
	fp.open(file);
	if (!fp.is_open())
		return res;

	int count;
	fp >> count;
	fp.ignore(1);
	for (int i = 0; i < count; ++i)  {
		int len;
		fp >> len;
		fp.ignore(1);

		std::vector<int> input;
		input.reserve(len);
		for (int j = 0; j < len; ++j)  {
			int item;
			fp >> item;
			fp.ignore(1);
			input.push_back(item);
		}

		res.push_back(solve(input));
	}

	return res;
}

void printResult(const std::list<double>& res)
{
	int i = 1;
	for (std::list<double>::const_iterator it = res.begin(); it != res.end(); ++it, ++i)  {
		std::cout << "Case #" << i << ": " << (*it) << "\n";
	}
	std::cout.flush();
}

int main(int argc, const char *argv[])
{
	if (argc < 2)  {
		std::cout << "Expected file name as the first parameter" << std::endl;
		return -1;
	}

	std::list<double> result = loadAndSolve(argv[1]);
	printResult(result);

#ifdef _DEBUG
	getchar();
#endif

	return 0;
}
