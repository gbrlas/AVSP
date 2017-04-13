#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>


using namespace std;

int main()
{
	int tests;

	cin >> tests;
	for (int l=1; l<=tests; l++)
	{
		long long n, A, B, C, D, X, Y, M;

		cin >> n >> A >> B >> C >> D >> X >> Y >> M;

		vector<long long> treeX(n);
		vector<long long> treeY(n);

		for (int i=0; i<n; i++)
		{
			treeX[i] = X;
			treeY[i] = Y;

			X = (A * X + B) % M;
			Y = (C * Y + D) % M;
		}

		long long result = 0;

		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++)
				for (int k=j+1; k<n; k++)
					if ((treeX[i] + treeX[j] + treeX[k]) % 3 == 0 &&
						(treeY[i] + treeY[j] + treeY[k]) % 3 == 0)
						result++;

		cout << "Case #" << l << ": " << result << endl;
	}

	return 0;
}