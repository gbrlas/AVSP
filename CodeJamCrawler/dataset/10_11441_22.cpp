#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("A-small-attempt0.in");
	ofstream output("A-small-attempt0.out");

	int t;

	int A[1001];
	int B[1001];

	input >> t;

	for (int tc = 1; tc<=t; tc++)
	{
		int n;
		int y = 0;
		input >> n;

		for (int i = 0; i<n; i++)
		{
			int a,b;
			input >> a >> b;

			for (int j=0; j<i; j++)
			{
				if ( a > A[j] )
				{
					if ( b < B[j] )
						y++;
				}
				else // ( a < A[j] )
				{
					if ( b > B[j] )
						y++; 
				}
			}

			A[i] = a;
			B[i] = b;
		}
		output << "Case #" << tc <<": " << y << endl;
	}

	return 0;
}