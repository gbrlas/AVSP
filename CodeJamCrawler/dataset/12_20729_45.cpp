#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);

	int T;

	scanf("%d", &T);
	for(int c = 0; c < T; ++c)
	{
		int N, S, p;
		scanf("%d %d %d",&N, &S, &p);

		int res = 0;
		for(int i = 0; i < N; ++i)
		{
			int temp;
			scanf("%d", &temp);

			int q = temp / 3;
			int r = temp % 3;
			if( q >= p )
				++res;
			else if( r == 1 )
			{
				if( q + 1 >= p )
					++res;
			}
			else if( r == 2 )
			{
				if( q + 1 >= p )
					++res;
				else if( q + 2 >= p && S > 0)
				{
					++res;
					--S;
				}
			}
			else if( r == 0 )
			{
				if( q == 0 )
					continue;

				if( q + 1 >= p && S > 0 )
				{
					++res;
					--S;
				}
			}
		}

		printf("Case #%d: %d\n", (c+1), res);
	}
	return 0;
}