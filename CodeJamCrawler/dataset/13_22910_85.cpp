#include<iostream>
#include<cmath>

using namespace std;


bool check_palin(long long N)
{
	long long tmp = N, reverse = 0;

	while(tmp)
	{
		reverse += tmp % 10;
		
		tmp /= 10;
		reverse *= 10;
	}

	reverse /= 10;
	if(N == reverse)return true;
	
	return false;
}

const int MAX = (int)1e7;

int palin[MAX+5];

int main()
{
	int T;

	palin[0] = 0;

		for(int i = 1;  i <= MAX; i++)
		{	
			palin[i] = palin[i-1];

			if(check_palin((long long)i) && check_palin((long long)i * (long long) i))
				palin[i]++;		
		}



	long long A, B, a, b;
	int cnt;

	cin >> T;
	for(int test = 1; test <= T; test++ )
	{
		cin >> A >> B;

		a = (long long)sqrt((long double)A);
		if(a*a < A) a++;

		b = (long long)sqrt((long double)B);

		cnt = palin[b] - palin[a-1];

		cout << "Case #" << test << ": " << cnt << "\n";
	}

	return 0;
}