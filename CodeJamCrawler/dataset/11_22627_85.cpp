#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct robot
{
	int pos, time;
};

int t, cases;
robot b, o;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		b.pos = o.pos = 1;
		b.time = o.time = 0;
		int n;
		scanf("%d", &n);
		while (n--)
		{
			char c[100];
			int x;
			scanf("%s%d", c, &x);
			robot *curRobot, *kRobot;
			if (c[0] == 'O')
			{
				curRobot = &o;
				kRobot = &b;
			}
			else
			{
				curRobot = &b;
				kRobot = &o;
			}

			curRobot->time = max(curRobot->time + abs(curRobot->pos - x), kRobot->time) + 1;
			curRobot->pos = x;
		}
		printf("Case #%d: %d\n", ++cases, max(b.time, o.time));
	}
}