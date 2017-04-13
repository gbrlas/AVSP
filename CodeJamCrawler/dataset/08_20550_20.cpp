#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>


using namespace std;

map<pair<string, pair<string, string> >, int> m[20000];

pair<string, pair<string, string> > mm(string a, string b, string c)
{
	return make_pair(a, make_pair(b, c));
}

struct offer
{
	int a, b;
	string color;
};

offer offers[500];
int no;

int MX = 1000000;

int f(int pos, string c1, string c2, string c3)
{
	if (m[pos].find(mm(c1, c2, c3)) == m[pos].end())
	{
		if (pos > 10000)
		{
			return m[pos][mm(c1, c2, c3)] = 0;
		}
		else 
		{
			int res = MX;
			for (int i = 0; i < no; i++)
			{
				if (offers[i].a <= pos && offers[i].b >= pos)
				{
					if (c1 == offers[i].color || c2 == offers[i].color || c3 == offers[i].color)
					{
						res = min(res, 1 + f(offers[i].b + 1, c1, c2, c3));
					}
					else 
					{
						if (c1 == "")
							res = min(res, 1 + f(offers[i].b + 1, offers[i].color, c2, c3));
						else if (c2 == "")
							res = min(res, 1 + f(offers[i].b + 1, c1, offers[i].color, c3));
						else if (c3 == "")
							res = min(res, 1 + f(offers[i].b + 1, c1, c2, offers[i].color));
					}
				}
			}
			m[pos][mm(c1, c2, c3)] = res;
		}

	}
	return m[pos][mm(c1, c2, c3)];
}

int main()
{
	//freopen("small.in", "rt", stdin);
	freopen("large.in", "rt", stdin);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		cin >> no;
		for (int i =0 ; i < no; i++)
			cin  >> offers[i].color >> offers[i].a >> offers[i].b;
		for (int i = 0; i < 11000; i++ )
			m[i].clear();
		int r = f(1, "", "", "");
		if (r < MX)
			cout << "Case #" << t << ": " << r << endl;
		else 
			cout << "Case #" << t << ": IMPOSSIBLE" << endl;

	}


	return 0;
}
