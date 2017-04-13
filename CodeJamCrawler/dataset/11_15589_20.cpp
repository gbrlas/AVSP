#include <vector>
#include <list>
#include <map>
#include <set>
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

struct CMD
{
	char who[4];
	int but;
};

int T, N;
CMD cmds[110];
int cmd[2][110], ncmd[2];

int solve()
{
	int ret = 0;
	int pos[2] = {1, 1};
	int who, who2;
	int icmd[2] = {0, 0};

	for (int i = 0; i < N; i ++) {
		if (cmds[i].who[0] == 'O')
			who = 0, who2 = 1;
		else
			who = 1, who2 = 0;

		int dest = cmd[who][ icmd[who]++ ];
		int dest2 = -1;
		if (icmd[who2] < ncmd[who2])
			dest2 = cmd[who2][ icmd[who2] ];

		if (dest == pos[who]) {
			ret ++;
			if (dest2 != -1 && dest2 != pos[who2])
				pos[who2] += (pos[who2]<dest2 ? 1 : -1);
		}
		else {
			int times = abs(dest - pos[who]) + 1;
			ret += times;
			pos[who] = dest;
			if (dest2 != -1 && dest2 != pos[who2]) {
				int times2 = abs(dest2 - pos[who2]);
				if (times >= times2)
					pos[who2] = dest2;
				else
					pos[who2] += (pos[who2]<dest2 ? times : -times);
			}
		}
	}
	return ret;
}

int main()
{
	freopen("A-large.in", "rb+", stdin);
	freopen("A-large.out", "wb+", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas ++) {
		scanf("%d", &N);
		ncmd[0] = ncmd[1] = 0;
		for (int i = 0; i < N; i ++) {
			scanf("%s %d", cmds[i].who, &cmds[i].but);
			if (cmds[i].who[0] == 'O')
				cmd[0][ ncmd[0]++ ] = cmds[i].but;
			else
				cmd[1][ ncmd[1]++ ] = cmds[i].but;
		}
		printf("Case #%d: %d\n", cas, solve());
	}
	return 0;
}