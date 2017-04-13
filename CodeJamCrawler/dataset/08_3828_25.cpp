#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;



vector <int> p;
int d[1001][1001];

struct Interval 
{
	Interval(int aa, int bb, int pp)
		:a(aa), b(bb), low(pp){}

	int setCount()
	{
		memset(d, 0, sizeof(d));
		for (int i = 0; i < p.size(); ++i)
		{
			if (p[i] < low)
			{
				continue;
			}
			for (int k = a; k <=b; ++k)
			{
				if (k % p[i] != 0) 
					continue;

				for (int l = k + 1; l <= b; ++l)
				{
					if (l % p[i] == 0) 
						d[k][l] = d[l][k] = 1;
				}
			}
		}

		int result = 0;
		v = vector<int>(b - a + 1);
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i] == 0)
			{
				++ result;
				fill(i);

			}
		}
		return result;
	}

	void fill(int i)
	{
		if (v[i] == 0)
		{
			v[i] = -1;
			for (int j = 0; j < v.size(); ++j)
			{
				if (d[a + i][a + j] == 1)
				{
					fill(j);
				}
			}
		}
	}

	int a, b, low;
	vector <int> v;
};

int main()
{
	ifstream cin("B-small-attempt0.in");
	ofstream cout("B-small-attempt0.out");
	int t;
	cin >> t;

	
	p.push_back(2);
	for (int i = 3; i < 1000; i += 2)
	{
		bool isPrime = true;
		for (int j = 0; p[j] * p[j] <= i; ++j)
			if (i % p[j] == 0)
			{
				isPrime = false;
				break;
			}
		if (isPrime)
			p.push_back(i);
	}

	for(int tt = 1; tt <= t; ++tt)
	{
		int a, b, pp, result = 0;
		cin >> a >> b >> pp;
		Interval inter(a, b, pp);
		result = inter.setCount();

				
		cout << "Case #" << tt <<": " << result  <<endl;
	}

	return 0;
}