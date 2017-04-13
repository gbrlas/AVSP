#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string Dump(long long v)
{
	if(v == 0)
		return "0";

	string ret;
	while(v > 0)
	{
		ret.insert(ret.begin(), '0' + v % 10);
		v /= 10;
	}

	return ret;
}

const int PRIME_LIMIT = 1000002;
bool is_prime[PRIME_LIMIT];
bool prime_used[PRIME_LIMIT];

int main()
{
	// Calculate the primes
	fill(&is_prime[0], &is_prime[PRIME_LIMIT], true);
	is_prime[0] = true;
	is_prime[1] = true;
	for(int i = 2; i < PRIME_LIMIT; ++i)
	{
		if(is_prime[i])
		{
			for(int k = 2 * i; k < PRIME_LIMIT; k += i)
				is_prime[k] = false;
		}
	}

	vector<int> primes;
	for(int i = 2; i < PRIME_LIMIT; ++i)
	{
		if(is_prime[i])
			primes.push_back(i);
	}

	int N;
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		long long A, B, P;
		cin >> A >> B >> P;

		// Create an array for the interval
		const int SIZE = static_cast<int>(B - A + 1);
		vector<int> sets(SIZE, 0);
		
		// Run through all primes
		for(size_t p = 0; p < primes.size(); ++p)
		{
			if(primes[p] >= P)
			{
				for(int j = 0; j < SIZE; ++j)
				{
					long long this_number = A + j;
					int		  this_prime  = primes[p];
					if((this_number % primes[p]) == 0)
					{
						if(sets[j] != 0)
						{
							// Replace
							int match = sets[j];
							for(int k = 0; k < SIZE; ++k)
							{
								if(sets[k] == match)
									sets[k] = this_prime;
							}
						}
						else
							sets[j] = this_prime;
					}
				}
			}
		}

		int  cnt = 0;
		fill(&prime_used[0], &prime_used[PRIME_LIMIT], false);
		for(int j = 0; j < SIZE; ++j)
		{
			if(sets[j] != 0)
				prime_used[sets[j]] = true;
			else
				++cnt;
		}
		for(int j = 0; j < PRIME_LIMIT; ++j)
		{
			if(prime_used[j])
				++cnt;
		}

		cout << "Case #" << (i + 1) << ": " << cnt << endl;
	}

	return 0;
}
