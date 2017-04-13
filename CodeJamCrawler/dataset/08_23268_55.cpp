#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>


using namespace std;

int main()
{
	int tests;

	cin >> tests;
	for (int k=1; k<=tests; k++)
	{
		int engines, queries;
		map<string, int> engineNames;
		vector<int> queryInds;
		string tmp;

		cin >> engines;
		getline(cin, tmp);
		for (int i=0; i<engines; i++)
		{
			getline(cin, tmp);
			engineNames[tmp] = i;
		}

		cin >> queries;
		getline(cin, tmp);
		for (int i=0; i<queries; i++)
		{
			getline(cin, tmp);
			queryInds.push_back(engineNames[tmp]);
		}

		int switches = 0, left = engines;
		vector<bool> used(engines, false);

		int query = 0;
		while (query < queries)
		{
			if (!used[queryInds[query]] && left > 1)
			{
				used[queryInds[query]] = true;
				left--;
			}
			else if (!used[queryInds[query]] && left == 1)
			{
				switches++;
				left = engines;
				
				for (int i=0; i<engines; i++)
					used[i] = false;

				used[queryInds[query]] = true;
				left--;
			}

			query++;
		}

		cout << "Case #" << k << ": " << switches << endl;
	}

	return 0;
}