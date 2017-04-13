#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


long long compute (long long rep, long long s)
{
	return rep * (rep - 1) * s; 
}


int main()
{
	ifstream cin("A-large.in");
	ofstream cout("A-large.out");

	int t;
	cin >> t;
	vector<int> x(100005), y(100005);
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
		
		long long mod[3 * 3] = {0};

		for (int i = 0; i < n; ++i)
		{
			++mod[ (x[i] % 3) * 3 + (y[i] %3)];
		}
		long long count = 0;

		for (int i = 0; i < 9; ++i)
			for(int j = 0; j < 9; ++j)
				for (int k = 0; k < 9; ++k)
				{
					if ( ((i / 3) + (j / 3) + (k / 3)) % 3 == 0 &&
						((i % 3) + (j % 3) + (k % 3)) % 3 == 0)
					{
						if (i == j && i == k)
						{
							if (mod [i] >= 3)
							{
								count += (mod[i] * (mod[i] - 1) * (mod[i] - 2));
							}
							continue;
						}
						if (i != j && j != k && k != i)
						{
							count += (mod[i] * mod[j] * mod[k]);
						}
						if ( i == j )
						{
							count += compute(mod[i], mod[k]);
							continue;
						}
						if (i == k)
						{
							count += compute(mod[i], mod[j]);
							continue;
						}
						if (j == k)
						{
							count += compute(mod[j], mod[i]);
							continue;
						}
					}
				}

		count /= 6;
		cout << "Case #" << tt <<": " << count  <<endl;

	}
	
	return 0;
}