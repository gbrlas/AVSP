#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

#define mp make_pair

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int multitest;
	cin >> multitest;
	for (int i = 0; i < multitest; i++)
	{
		int n;
		cin >> n;
		vector< vector< pair<int, int> > > order(2);
		for (int i = 0; i < n; i++)
		{
			char who;
			int where;
			cin >> who >> where;
			if (who == 'O')
				order[0].push_back(mp(i, where-1));
			else
				order[1].push_back(mp(i, where-1));
		}
		
		order[0].push_back(mp(n, 101));
		order[1].push_back(mp(n, 101));
		vector< vector< pair<int, int> >::iterator > curorder(2);
		for (int i = 0; i < 2; i++)
			curorder[i] = order[i].begin();
		
		vector<int> curplace(2, 0);
		vector<bool> free(2, true);
		
		int ans = 0;
		for (int done = 0; done < n; ans++)
		{
			free[0] = free[1] = true;
			for (int i = 0; i < 2; i++)
			{
				if (curorder[i]->first == done && curplace[i] == curorder[i]->second)
				{
					curorder[i]++;
					done++;
					free[i] = false;
					break;
				}
			}
			for (int i = 0; i < 2; i++)
			{
				if (free[i] && curplace[i] != curorder[i]->second)
					curplace[i] += (curorder[i]->second > curplace[i] ? 1 : -1);
			}
		}
		
		printf("Case #%d: %d\n", i+1, ans);
	}
	
	return 0;
}