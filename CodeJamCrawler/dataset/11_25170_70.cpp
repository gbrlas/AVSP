#include <iostream>
#include <fstream>
using namespace std;
#define N 101
ifstream input;
ofstream output;

int abs(int x)
{
	if ( x < 0 )
		return -x;
	return x;
}

int main()
{
	input.open("A-large.in");
	output.open("A-large.out");
	int x, b, o, t, i, j, n, sum, k;
	char c, c_now;

	input >> t;
	for (i = 1; i <= t; i++)
	{
		input >> n;
		k = 0; c = 'O'; b = 1; o = 1;
		sum = 0;
		for (j = 0; j < n; j++)
		{
			input >> c_now >> x;
			if ( c_now == 'O' )
			{
				if ( c == 'O' )
				{
					k += abs(x - o) + 1;
					sum += abs(x - o) + 1;
				}
				else
				{
					if ( abs(x - o) <= k )
					{
						k = 1;
						sum++;
					}
					else
					{
						sum += abs(x - o) - k + 1;
						k = abs(x - o) - k + 1;
					}
				}
				c = 'O';
				o = x;
			}
			else
			{
				if ( c == 'B' )
				{
					k += abs(x - b) + 1;
					sum += abs(x - b) + 1;
				}
				else
				{
					if ( abs(x - b) <= k )
					{
						k = 1;
						sum++;
					}
					else
					{
						sum += abs(x - b) - k + 1;
						k = abs(x - b) - k + 1;
					}
				}
				c = 'B';
				b = x;
			}
		}
		output << "Case #" << i << ": " << sum << endl;
	}
	input.close();
	output.close();
	return 0;
}