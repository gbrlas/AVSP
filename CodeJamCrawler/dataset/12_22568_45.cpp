#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream input;
	ofstream output;

	string inputname = "input.txt";
	string outputname = "output.txt";

	input.open(inputname.c_str());
	output.open(outputname.c_str());

	unsigned T;
	input >> T;

	for (unsigned t = 0; t < T; t++)
	{
		unsigned N, S, p;
		double t_i;
		input >> N >> S >> p;

		unsigned best = 0;
		unsigned best_surprise = 0;

		for (unsigned n = 0; n < N; n++)
		{
			input >> t_i;

			unsigned div = ceil(double(t_i/3));
			
			if (div >= p)
				best++;

			if ((unsigned(t_i) % 3 != 1) && t_i > 1)
				div++;

			if (div >= p)
				best_surprise++;
		}

		unsigned best_final;

		if (best_surprise > best + S)
			best_final = best + S;
		else
			best_final = best_surprise;

		output << "Case #" << t+1 << ": " << best_final << endl;
	}


	return 0;
}