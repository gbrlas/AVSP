#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <cassert>
#include <algorithm>

using namespace std;

typedef list<double> Result;

double teamWp(const string& myTeam, int ignoreCol = -1)
{
	int gamesPlayed = 0, gamesWon = 0;
	for (int i = 0; i < myTeam.size(); i++)  {
		if (i != ignoreCol)  {
			if (myTeam[i] != '.')
				++gamesPlayed;
			if (myTeam[i] == '1')
				++gamesWon;
		}
	}

	return (double)gamesWon / gamesPlayed;
}

double teamOwp(vector<string>& table, int team)
{
	double OWP = 0;
	int count = 0;
	for (int i = 0; i < table.size(); i++)  {
		if (team != i && table[team][i] != '.')  {
			OWP += teamWp(table[i], team);
			count++;
		}
	}

	return OWP / count;
}

double solveTeam(vector<string>& table, int team)
{
	string myTeam = table[team];
	double WP, OWP, OOWP;

	WP = teamWp(myTeam);
	OWP = teamOwp(table, team);

	OOWP = 0;
	int count = 0;
	for (int i = 0; i < table.size(); i++)  {
		if (i != team && table[team][i] != '.')  {
			OOWP += teamOwp(table, i);
			count++;
		}
	}
	OOWP /= count;

	return 0.25 * WP + 0.50 * OWP + 0.25 * OOWP;
}

Result solveOne(vector<string>& table)
{
	Result res;
	for (int i = 0; i < table.size(); i++)  {
		res.push_back(solveTeam(table, i));
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
		int teams;
		fp >> teams;

		vector<string > table;
		for (int i = 0; i < teams; i++)  {
			string row;
			fp >> row;
			fp.ignore();
			assert(row.size() == teams);
			table.push_back(row);
		}
		
		res.push_back(solveOne(table));
	}

	return res;
}

void printResults(const list<Result>& res)
{
	int i = 1;
	cout.precision(15);
	for (auto it = res.cbegin(); it != res.cend(); ++it, ++i)  {
		cout << "Case #" << i << ":\n";
		for (auto it2 = it->cbegin(); it2 != it->cend(); ++it2)  {
			cout << *it2 << "\n";
		}
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
