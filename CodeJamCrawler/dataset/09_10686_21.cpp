#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <iostream>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	//freopen("A-test.in", "r", stdin);
	//freopen("A-test.out", "w", stdout);
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int casesNumber = 0;
	cin >> casesNumber;
	for (int testCase = 1; testCase <= casesNumber; ++ testCase)
	{
		int n = 0;
		scanf("%d", &n);
		vector <int> val;
		for (int i = 0; i < n; ++ i)
		{
			int pos = 0;
			string s;
			cin >> s;
			for (int j = 0; j < n; ++ j)
			{
				if (s[j] == '1') pos = j;
			}
			val.push_back(pos);
			//cout << pos << endl;
		}
		int ans = 0;
		for (int i = 0; i < n; ++ i)
		{
			if (val[i] > i)
			{
				for (int j = i + 1; j < n; ++ j)
					if (val[j] <= i)
					{
						ans += j - i;
						rotate(val.begin() + i, val.begin() + j, val.begin() + j + 1);
						break;
					}
			}
			//cout << val[i] << endl;
		}
		cout << "Case #" << testCase << ": " << ans << endl;
	}
	return 0;
}
