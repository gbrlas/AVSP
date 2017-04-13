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
		int area, n, m;
		cin >> n >> m >> area;

		int x3 = 0, y3 = 0, x1, x2, y1, y2;
		bool done = false;

		for (x1 = 0; !done && x1<=n; x1++)
			for (y1 = 0; !done && y1<=m; y1++)
				for (x2 = 0; !done && x2<=n; x2++)
					for (y2 = 0; !done && y2<=m; y2++)
					{
						int T = abs((x1-x2)*(y1-y3)-(y1-y2)*(x1-x3));

						if (T == area)
						{
							done = true;
							cout << "Case #" << t << ": " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
						}
					}

		if (!done)
			cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
	}

	return 0;
}