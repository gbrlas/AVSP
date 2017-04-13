#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);

	for(int c = 1; c <= T; ++c)
	{
		int r1, r2;
		vector< vector<int> > grid1, grid2;

		scanf("%d", &r1);
		for(int i = 0; i < 4; ++i)
		{
			vector<int> t;
			for(int j = 0; j < 4; ++j)
			{
				int n;
				scanf("%d", &n);
				t.push_back(n);
			}
			grid1.push_back(t);
		}

		scanf("%d", &r2);
		for(int i = 0; i < 4; ++i)
		{
			vector<int> t;
			for(int j = 0; j < 4; ++j)
			{
				int n;
				scanf("%d", &n);
				t.push_back(n);
			}
			grid2.push_back(t);
		}

		--r1;
		--r2;

		vector<int> v;
		
		for(int i = 0; i < 4; ++i)
		{
			for(int j = 0; j < 4; ++j)
			{
				if(grid1[r1][i] == grid2[r2][j])
				{
					v.push_back(grid1[r1][i]);
					break;
				}
			}
		}

		if((int)v.size() == 1)
		{
			printf("Case #%d: %d\n", c, v[0]);
		}
		else if((int)v.size() > 1)
		{
			printf("Case #%d: Bad magician!\n", c);
		}
		else
		{
			printf("Case #%d: Volunteer cheated!\n", c);
		}
	}
	return 0;
}