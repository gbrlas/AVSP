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

	long long max = 1000;
	vector<long long> primes;
	primes.push_back(2);

	for (long long i=3; i<=max; i += 2)
	{
		bool prime = true;
		for (long long j=0; j<primes.size(); j++)
			if (i % primes[j] == 0)
			{
				prime = false;
				break;
			}

		if (prime)
			primes.push_back(i);
	}

	cin >> tests;
	for (int l=1; l<=tests; l++)
	{
		long long result = 0;

		long long A, B, P;

		cin >> A >> B >> P;

		vector<int> sets(primes.size());
		for (int i=0; i<sets.size(); i++)
			sets[i] = i;

		int pmin = 0, pmax;
		while (primes[pmin] < P)
			pmin++;

		pmax = pmin;
		while (pmax < primes.size() && primes[pmax] < B)
			pmax++;
		if (pmax >= primes.size() || primes[pmax] > B)
			pmax--;

		for (int i=pmin; i<=pmax; i++)
			for (int j=pmin; j<=pmax; j++)
			{
				if (sets[i] != sets[j])
				{
					int common = primes[i] * primes[j];
					if ((B / common) * common >= A)
					{
						int merge = sets[i];
						for (int k=pmin; k<=pmax; k++)
							if (sets[k] == merge)
								sets[k] = sets[j];
					}
				}
			}

		map<int, bool> seen;
		for (int i=pmin; i<=pmax; i++)
		{
			if ((B / primes[i]) * primes[i] >= A)
			{
				if (seen[sets[i]] == false)
					result++;
				seen[sets[i]] = true;
			}
		}


		for (long long i = A; i <= B; i++)
		{
			bool unseen = true;
			for (int p = pmin; p <= pmax; p++)
				if (i % primes[p] == 0)
				{
					unseen = false;
					break;
				}

			if (unseen)
				result++;
		}

		cout << "Case #" << l << ": " << result << endl;
	}

	return 0;
}