#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define mp make_pair

int main()
{
	int t;
	scanf("%d", &t);
	
	int count[20];
	int grid[20][20];

	for(int test = 1; test <= t; test++)
	{

		for(int i = 0; i < 20; i++)
			count[i] = 0;

		int row;
		scanf("%d", &row);
		--row;

		for(int i = 0 ; i < 4; i++)
			for(int j = 0; j < 4; j++)
				scanf("%d", &grid[i][j]);

		for(int j = 0; j < 4; j++)
			count[ grid[row][j] ]++;

		scanf("%d", &row);
		--row;

		for(int i = 0 ; i < 4; i++)
			for(int j = 0; j < 4; j++)
				scanf("%d", &grid[i][j]);

		for(int j = 0; j < 4; j++)
			count[ grid[row][j] ]++;


		int total = 0;
		int num = 0;
		for(int i = 0; i < 20; i++)
		{
			if(count[i] == 2)
			{		
				total++;
				num = i;
			}
		}

		printf("Case #%d: ", test);

		if(total == 1)
			printf("%d\n", num);
		else if(total == 0)
			printf("Volunteer cheated!\n");
		else
			printf("Bad magician!\n");
	}

		
	return 0;
}