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
		unsigned N;
		input >> N;

		char R_pre = ' ', R;
		int index_b = 1, index_o = 1, step_curr = 0, step_total = 0, step_overlap = 0, button;
		bool blues_turn = true;

		for (unsigned n = 0; n < N; n++)
		{
			input >> R >> button;

			if (n == 0)
			{
				blues_turn = (R == 'B');
			}

			if (R == 'O')
			{
				step_curr = abs(index_o - button) + 1;
				index_o = button;

				if (!blues_turn)
				{
					step_overlap += step_curr;
				}
				else
				{
					step_curr -= step_overlap;

					if (step_curr < 1) 
						step_curr = 1;

					step_overlap = step_curr;

					blues_turn = false;
				}
			}
			else // (R == 'B')
			{
				step_curr = abs(index_b - button) + 1;
				index_b = button;

				if (blues_turn)
				{
					step_overlap += step_curr;
				}
				else
				{
					step_curr -= step_overlap;

					if (step_curr < 1) 
						step_curr = 1;

					step_overlap = step_curr;

					blues_turn = true;
				}
			}

			step_total += step_curr;
		}

		output << "Case #" << t+1 << ": " << step_total << endl;
	}


	return 0;
}