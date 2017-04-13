#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
//#include <sstream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define DOWNFOR(i,a,b) for (int i = (b-1); i >= (a); --i)

int N, S, Q;

map<string, int> msi;
bool pole[16];
int avail;

int main()
{
	string str;
	int ret;

	scanf("%d\n", &N);
	FOR (icase, 1, N+1)
	{
		scanf("%d\n", &S);

		msi.clear();
		memset(pole, false, S);
		avail = S;
		ret = 0;

		FOR (s, 0, S)
		{
			getline(cin, str);
			msi[str] = s;
		}

		scanf("%d\n", &Q);
		FOR (q, 0, Q)
		{
			getline(cin, str);
			if (pole[msi[str]] == false)
			{
				pole[msi[str]] = true;
				--avail;

				if (avail == 0)
				{
					ret++;
					memset(pole, false, S);
					pole[msi[str]] = true;
					avail = S-1;
				}
			}
		}

		printf("Case #%d: %d\n", icase, ret);
	}

	return 0;
}

