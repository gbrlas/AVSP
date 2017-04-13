#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
//#include <sstream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define DOWNFOR(i,a,b) for (int i = (b-1); i >= (a); --i)

int N, NA, NB;
int ca, cb;

vector<int> depa, arra, depb, arrb;

inline int time_to_int(int h, int m)
{
	return 60*h + m;
}

int main()
{
	int h, m, ta, pa, pd;

	scanf("%d", &N);
	FOR (icase, 1, N+1)
	{
		scanf("%d", &ta);

		scanf("%d", &NA);
		scanf("%d", &NB);

		depa.clear();
		depb.clear();
		arra.clear();
		arrb.clear();

		FOR (i, 0, NA)
		{
			scanf("%d:%d", &h, &m);
			depa.push_back(time_to_int(h, m));
			scanf("%d:%d", &h, &m);
			arrb.push_back(time_to_int(h, m)+ta);
		}

		FOR (i, 0, NB)
		{
			scanf("%d:%d", &h, &m);
			depb.push_back(time_to_int(h, m));
			scanf("%d:%d", &h, &m);
			arra.push_back(time_to_int(h, m)+ta);
		}

		sort(arra.begin(), arra.end());
		sort(arrb.begin(), arrb.end());
		sort(depa.begin(), depa.end());
		sort(depb.begin(), depb.end());

		ca = NA;
		cb = NB;

		pa = pd = 0;
		while (pa < arra.size() && pd < depa.size())
		{
			if (depa[pd] < arra[pa])
				++pd;
			else
			{
				--ca;
				++pd;
				++pa;
			}
		}

		pa = pd = 0;
		while (pa < arrb.size() && pd < depb.size())
		{
			if (depb[pd] < arrb[pa])
				++pd;
			else
			{
				--cb;
				++pd;
				++pa;
			}
		}

		printf("Case #%d: %d %d\n", icase, ca, cb);
	}

	return 0;
}

