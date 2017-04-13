#include <iostream>
#include <fstream>
using namespace std;
#define MAXINT 1000000000

ifstream input;
ofstream output;

int main()
{
	input.open("C-small-attempt1.in");
	output.open("C-small-attempt1.out");

	int i, j, n, t, sum, xor, k, min;
	
	input >> t;
	for (i = 1; i <= t; i++)
	{
		input >> n;
		for (j = 0, sum = 0, xor = 0, min = MAXINT; j < n; j++)
		{
			input >> k;
			xor ^= k;
			sum += k;
			if ( k < min )
				min = k;
		}
		output << "Case #" << i << ": ";
		if ( xor == 0 )
			output << sum - min << endl;
		else
			output << "NO" << endl;
	}
	
	input.close();
	output.close();
	return 0;
}