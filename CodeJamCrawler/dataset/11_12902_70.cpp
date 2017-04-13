#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
//	freopen("test.in", "r", stdin);
	
	int T; scanf("%d", &T);
	for(int test=1; test<=T; ++test)
	{
		int opos = 1, bpos = 1;
		int otime = 0, btime = 0;
		int time = 0;

		int N; scanf("%d ", &N);
		for(int i=0; i<N; ++i)
		{
			char r; int but;
			scanf("%c %d ", &r, &but);

			if( r == 'O' )
			{
				otime += abs(but - opos) + 1;
				opos = but;
				if(otime > time)
					time = otime;
				else
				{
					time++;
					otime = time;
				}
			}
			else
			{
				btime += abs(but - bpos) + 1;
				bpos = but;
				if(btime > time)
				{
					time = btime;
				}
				else
				{
					time++;
					btime = time;
				}
			}
		}

		printf("Case #%d: %d\n", test, time);
	}
}