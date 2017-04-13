#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct Tot {
	char x1, y1, x2, y2, x3, y3;
	Tot(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3) {
		x1 = _x1; y1 = _y1; x2 = _x2; y2 = _y2; x3 = _x3; y3 = _y3;
	}
};

int n, m, area;
vector<Tot> block[4001];

void init()
{
	int n = 60, m = 60;
	int x1 = 0, y1 = 0;
	for (int x2 = 0; x2 <= n; ++x2)
		for (int y2 = 0; y2 <= m; ++y2)
			for (int x3 = 0; x3 <= n; ++x3)
				for (int y3 = 0; y3 <= m; ++y3)
				{
					int xa = x2 - x1, ya = y2 - y1,
					    xb = x3 - x1, yb = y3 - y1;
					int cur = abs(xa * yb - ya * xb);
					if (cur > 3600)
						printf("error!\n");
					block[cur].push_back(Tot(x1, y1, x2, y2, x3, y3));
				}
}

int main()
{
	init();
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 0; caseNo < cases; ++caseNo)
	{
		scanf("%d %d %d", &n, &m, &area);
		printf("Case #%d: ", caseNo + 1);
		bool found = false;
		if (area <= 3000)
		for (vector<Tot>::iterator iter = block[area].begin(); iter != block[area].end(); ++iter)
			if (iter->x2 <= n && iter->y2 <= m && iter->x3 <= n && iter->y3 <= m)
			{
				printf("%d %d %d %d %d %d\n", 0, 0, iter->x2, iter->y2, iter->x3, iter->y3);
				found = true;
				break;
			}
		if (!found)
			printf("IMPOSSIBLE\n");
	}
	return 0;
}

