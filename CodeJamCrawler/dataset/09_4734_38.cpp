#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int numCell, numRel;

set <int> rel;
int mem[110][110];

int go( int i, int j)
{
	if(i >= j)
		return 0;

	if(mem[i][j] != -1)
		return mem[i][j];

	set <int> ::iterator it = rel.lower_bound(i);

	int ret = INT_MAX, tmp;


	while(it != rel.end() && (*it) <= j)
	{
		tmp = go(i, (*it)-1);
		tmp += go( (*it) + 1, j);
		ret = min(ret , tmp);
		it++;
	}

	if(ret == INT_MAX) return mem[i][j] = 0;
	

	return mem[i][j] = ret + j - i;

}
int main()
{
	ifstream cin("we.in");
	ofstream cout("aff.txt");
	int T, casenum = 1, ff;

	cin >> T;

	while(T--)
	{
		rel.clear();
		memset(mem, -1, sizeof(mem));
		cin >> numCell >> numRel;

		for(int x = 0; x < numRel; x++)
		{
			cin >> ff;
			rel.insert(ff);
		}

		cout << "Case #" << casenum++ << ": " << go(1, numCell) << endl;
	}

	cout.close();
	return 0;
}