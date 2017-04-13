#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;

int main()
{
	int tests;

	cin >> tests;
	for (int t=1; t<=tests; t++)
	{
		int k, total, best = 999999999;
		string str;

		cin >> k >> str;

		vector<int> perm(k);
		for (int i=0; i<k; i++)
			perm[i] = i;

		total = 1;
		for (int i=1; i<=k; i++)
			total *= i;

		for (int i=0; i<total; i++)
		{
			string newStr = "";
			for (int j=0; j<str.length() / k; j++)
				for (int l=0; l<k; l++)
					newStr += str[perm[l] + j*k];

			int groups = 1;
			for (int j=1; j<newStr.length(); j++)
				if (newStr[j] != newStr[j-1])
					groups++;

			best = min(best, groups);

			next_permutation(perm.begin(), perm.end());
		}

		cout << "Case #" << t << ": " << best << endl;
	}

	return 0;
}