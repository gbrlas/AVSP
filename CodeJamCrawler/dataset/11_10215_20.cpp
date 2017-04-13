#include <iostream>
#include <cstdio>

using namespace std;


int t, pd, pg, N, tt, d, wd, wg, g;
long long M;
bool ok;


int GCD(int a, int b)
{
	while (a && b)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	
	return a + b;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> M >> pd >> pg;
		
		cout << "Case #" << i + 1 << ": ";
		
		if (pg == 100)
		{
			cout << (pd == 100 ? "Possible\n" : "Broken\n");
			continue;
		}
		
		if (pg == 0)
		{
			cout << (pd == 0 ? "Possible\n" : "Broken\n");
			continue;
		}

			
		/*d = 100/GCD(100, Pd);
		
		
		if (d <= M)
			cout << "Possible";
		else
			cout << "Broken";
		
		cout << endl;*/
		
		ok = false;
		
		
		for (int d = 1; d <= M; d++)
			for (int g = d; g <= 1000; g++)
				for (int wg = 0; wg <= g; wg++)
					for (int wd = 0; wd <= d; wd++)
					{
						if (pd * d == wd * 100 && pg * g == wg * 100)
						{
							ok = true;
							//cout << wd << ' ' << d << ' ' << wg << ' ' << g << ' ';
							goto lab;
						}
					}
		
		lab:;
		
		if (ok)
			cout << "Possible\n";
		else
			cout << "Broken\n";
	}	
	
	return 0;
}
