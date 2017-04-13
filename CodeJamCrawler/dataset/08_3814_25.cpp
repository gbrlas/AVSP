#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	ifstream cin("A-small-attempt0.in");
	ofstream cout("A-small.out");

	int t;
	cin >> t;
	vector<int> x(105), y(105);
	for(int tt = 1; tt <= t; ++tt)
	{
		long long n, a, b, c, d, x0, y0, M;
		cin >> n >> a >> b >> c >> d >> x0 >> y0 >> M;
		
		x[0] = x0;
		y[0] = y0;
		for (int i = 1; i < n; ++i)
		{
			x[i] = int((a * x[i - 1] + b) % M);
			y[i] = int((c * y[i - 1] + d) % M);
		}
		
		int count = 0;
		for (int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++j)
				for (int k = j + 1; k < n; ++k)
				{
					if (((x[i] % 3) + (x[j] %3) + (x[k] %3)) %3 == 0 &&
						((y[i] % 3) + (y[j] %3) + (y[k] %3)) %3 == 0 )
					{
						++count;
					}
				}

		cout << "Case #" << tt <<": " << count <<endl;

	}
	
	return 0;
}