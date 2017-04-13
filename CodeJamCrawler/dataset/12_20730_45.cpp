#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);

	int T;
	scanf("%d", &T);

	
	for(int c = 0; c < T; ++c)
	{
		int A, B;
		scanf("%d %d", &A, &B);

		set<pair<int,int>> SET;
		for(int i = A; i <= B; ++i)
		{
			string a, b;
			stringstream out;
			out << i;
			out >> a;

			if( (int)a.size() == 1 )
				continue;

			for(int j = 0; j < a.size()-1; ++j)
			{
				int temp = 0;
				rotate(a.rbegin(), a.rbegin()+1, a.rend());
				stringstream out2;
				out2 << a;
				out2 >> temp;
				if( temp <= B && temp > i )
				{
					SET.insert(make_pair(i,temp));
				}
			}
		}

		printf("Case #%d: %d\n", (c+1), SET.size());
	}
	return 0;
}