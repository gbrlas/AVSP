#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>

using namespace std;

typedef long long Result;
typedef long long Time;

Result solveOne(int starCount, Time boosterTime, int boosters, const vector<int>& distInp)
{
	vector<int> distances;
	Time t = 0;
	int boostIndex = 0;  // First star with booster
	for (int i = 0; i < starCount - 1; i++)  {
		int d = distInp[i % distInp.size()];
		Time nextT = t + d * 2;
		if (nextT < boosterTime)  {
			distances.push_back(d);
		} else {
			if (t < boosterTime && nextT > boosterTime)  {
				// Split
				distances.push_back((boosterTime - t) / 2);
				boostIndex = distances.size();
				distances.push_back((nextT - boosterTime) / 2);
			} else {
				distances.push_back(d);
			}
		}

		t = nextT;
	}

	sort(distances.begin() + boostIndex, distances.end(), greater<int>());
	Time totalTime = 0;
	int usedBoosters = 0;
	for (int i = 0; i < distances.size(); i++)  {
		if (i < boostIndex)  {
			totalTime += distances[i] * 2;
		} else {
			if (usedBoosters < boosters)  {
				totalTime += distances[i];
				++usedBoosters;
			} else {
				totalTime += distances[i] * 2;
			}
		}
	}

	return totalTime;
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
		int boosters, lastStar, C;
		Time boosterTime;
		fp >> boosters;
		fp >> boosterTime;
		fp >> lastStar;
		fp >> C;
		assert(fp.good());

		vector<int> distInp;
		for (int i = 0; i < C; i++)  {
			int d;
			fp >> d;
			distInp.push_back(d);
		}

		res.push_back(solveOne(lastStar + 1, boosterTime, boosters, distInp));
	}

	return res;
}

void printResults(const list<Result>& res)
{
	int i = 1;
	for (auto it = res.cbegin(); it != res.cend(); ++it, ++i)  {
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
