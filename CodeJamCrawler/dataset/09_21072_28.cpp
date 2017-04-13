#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

int main()
{
	int tc, t = 0;

	for (cin >> tc; t < tc; t++)
	{
		int n;
		cin >> n;
		string l;
		vector<int> last;
		for (int i = 0; i < n; i++)
		{
			cin >> l;
			int lastone = 0;
			for (int j = 0; j < n; j++)
				if (l[j] == '1') lastone = j;
			last.push_back(lastone);
		}
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (last[j] <= i)
				{
					for (int k = j; k - 1 >= i; k--)
					{
						swap(last[k], last[k - 1]);
						res++;
					}
					break;
				}
			}
		}
		cout << "Case #" << t + 1 << ": " << res << endl;
	}

	return 0;
}
