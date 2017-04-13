#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int T = 0;
	ifstream input;
	ofstream output;
	const int SIZE = 50;
	int A[SIZE];
	int B[SIZE];
	int pairs[SIZE];

	input.open("Input.txt");
	output.open("Output.txt");

	input >> T;
	input.ignore(numeric_limits<streamsize>::max(), '\n' );
	
	for (int i = 0; i < T; i++)
	{
		pairs[i] = 0;
		input >> A[i] >> B[i];

		for (int k = A[i]; k <= B[i]; k++)
		{
			for (int j = k; j <= B[i]; j++)
			{
				if (B[i] < 100)
				{
					if ((((k%10)*10)+((k/10)) == j && k != j))
						pairs[i] ++;
				}
				else if (B[i] < 1000)
				{
					if (((k%100)*10)+((k/100)) == j && k != j)
						pairs[i] ++;
					if (((k%10)*100)+((k/10)) == j && k != j)
						pairs[i] ++;
				}
				
			}
		}
		output << "Case #" << i+1 << ": " << pairs[i] << endl;
	}

	input.close();
	output.close();
	return 0;
}