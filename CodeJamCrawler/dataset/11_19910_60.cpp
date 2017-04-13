#include "TestCase.h"

bool TestCase::elementMap[256];
bool TestCase::inited = false;

void TestCase::init()
{
	if (inited)
		return;

	element base[] = {'Q', 'W', 'E', 'R', 'A', 'S', 'D', 'F'};
	memset(elementMap, 0, sizeof(elementMap));
	for (unsigned i = 0; i < sizeof(base) / sizeof(base[0]); ++i)  {
		elementMap[base[i]] = true;
	}
}

TestCase::TestCase()
{
	init();
}

TestCase::~TestCase()
{

}

void TestCase::addCombine(element base1, element base2, element combined)
{
	combines[combine(base1, base2)] = combined;
	combines[combine(base2, base1)] = combined;
}

void TestCase::addOpposite(element base1, element base2)
{
	opposites[base1].push_back(base2);
	opposites[base2].push_back(base1);
}

std::string TestCase::combine(element e1, element e2)
{
	std::string res;
	res += e1;
	res += e2;
	return res;
}

void TestCase::updateOppositeMap(bool *map, element el, bool remove)
{
	for (OppositeList::iterator it = opposites[el].begin(); it != opposites[el].end(); ++it)  {
		map[*it] = !remove;
	}
}

void TestCase::solve(const std::string& input, Output& output)
{
	typedef std::string::const_iterator InputIter;
	bool oppositeMap[256];
	int refCounts[256];
	memset(oppositeMap, 0, sizeof(oppositeMap));
	memset(refCounts, 0, sizeof(refCounts));

	for (InputIter it = input.begin(); it != input.end(); ++it)  {
		element current = (element)(*it);
		if (output.empty())  {
			output.push_back(current);
			updateOppositeMap(oppositeMap, current, false);
			refCounts[current]++;
			continue;
		}

		element last = *output.rbegin();

		// Check combine
		CombineMap::iterator combination = combines.find(combine(last, current));
		if (combination != combines.end())  {
			output.pop_back();
			output.push_back(combination->second);
			refCounts[last]--;
			if (refCounts[last] == 0)
				updateOppositeMap(oppositeMap, last, true);
			updateOppositeMap(oppositeMap, combination->second, false);
			refCounts[combination->second]++;
			continue;
		}

		// Check opposite
		if (oppositeMap[current])  {
			output.clear();
			memset(oppositeMap, 0, sizeof(oppositeMap));
			memset(refCounts, 0, sizeof(refCounts));
			continue;
		}

		output.push_back(current);
		updateOppositeMap(oppositeMap, current, false);
		refCounts[current]++;
	}
}
