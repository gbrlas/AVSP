#include<iostream>
#include<cmath>

using namespace std;


bool check_palin(int N)
{
	int tmp = N, reverse = 0;

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

int main()
{
	int A,B,T;

	cin >> T;
	for(int test = 1; test <= T; test++ )
	{
		cin >> A >> B;

		int cnt = 0;

		for(int i = A;  i <= B; i++)
		{
			int N = (int )sqrt((double) i);
		
			if(N * N == i)
			{
				if(check_palin(N) && check_palin(i))cnt++;
			}
		}

		cout << "Case #" << test << ": " << cnt << "\n";
	}

	return 0;
}