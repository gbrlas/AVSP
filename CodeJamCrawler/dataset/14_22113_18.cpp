#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);

	int T;
	cin >> T;

	for(int c = 1; c <= T; ++c)
	{
		int A, B, K;
		cin >> A >> B >> K;

		int res = 0;
		for(int i = 0; i < A; ++i)
		{
			for(int j = 0; j < B; ++j)
			{
				if((i & j) < K)
				{
					++res;
				}
			}
		}

		cout << "Case #"<< c << ": " << res << endl;
	}

	return 0;
}