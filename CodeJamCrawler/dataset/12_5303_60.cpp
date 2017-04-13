#include <iostream>
#include <map.h>

using namespace std;

bool big_max_surp(int tot, int thresh)
{
	if (tot == 0 || tot == 1 || tot == 29 || tot == 30)
		return false;
	if (tot % 3 == 0)
		return (tot / 3) + 1 >= thresh;
	if (tot % 3 == 1)
		return (tot / 3) + 1 >= thresh;
	if (tot % 3 == 2)
		return (tot / 3) + 2 >= thresh;
}

bool big_max_reg(int tot, int thresh)
{
	if (tot == 0 || tot == 1)
		return tot >= thresh;
	if (tot == 29 || tot == 30)
		return 10 >= thresh;
	if (tot % 3 == 0)
		return (tot / 3) >= thresh;
	return (tot / 3) + 1 >= thresh;
}

int main()
{
	int i, c;
	int T, N, S, p;
	int ts[100];
	int bigsurp[100];
	int bigreg[100];
	int used[100];
	
	cin >> T;
	
	for (c = 1; c <= T; c++)
	{
		cin >> N >> S >> p;
		for (i = 0; i < N; i++)
			cin >> ts[i];
		
		
		/* meat */
		for (i = 0; i < N; i++)
		{
			used[i] = 0;
			bigsurp[i] = big_max_surp(ts[i], p);
			bigreg[i] = big_max_reg(ts[i], p);
		}
		
		i = 0;
		int t = 0;
		int ms = 0;
		while (t < S && i < N)
		{
			if (!bigreg[i] && bigsurp[i])
			{
				used[i] = 1;
				t++;
				ms++;
			}
			i++;
		}
		
		i = 0;
		while (t < S && i < N)
		{
			if (!used[i] && bigsurp[i])
			{
				used[i] = 1;
				t++;
				ms++;
			}
			i++;
		}
		
		int q = 0;
		i = 0;
		while (q < N-S && i < N)
		{
			if (!used[i] && bigreg[i])
			{
				used[i] = 1;
				q++;
				ms++;
			}
			i++;
		}
		
		cout << "Case #" << c << ": " << ms << endl;
	}
	
	
	return 0;
}