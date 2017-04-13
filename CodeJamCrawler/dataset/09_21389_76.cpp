#include <fstream>
#include <string>
using namespace std;

int main ()
{
	// Generic File Instantiations
	ifstream input;
	ofstream output;
	
	string inputname, outputname;
	
	inputname = "welcome_input.in";
	outputname = "welcome_output.out";
	input.open (inputname.c_str ());
	output.open (outputname.c_str ());
	
	// Input Read & Initializations
	int N; // number of test cases
	input >> N;

	int i, j, k, l, m;

	string str, z_padding, welcome = "welcome to code jam";
	unsigned int branch[19]; // Each character corresponds to an array slot

	getline(input, str); // Read to disregard N

	// Fill array and print	
	for (i = 1; i <= N; i++)
	{
		getline(input, str);

		for (j = 0; j < 19; j++)
		{
			branch[j] = 0;
		}

		for (k = 0; k < str.length(); k++)
		{
			if (str[k] == 'w')
			{
				branch[0]++;
			}
			else
			{
				for (l = 1; l < 19; l++)
				{
					if (branch[l-1] == 0) // to make the program skip unnecessary computation
						break;

					if (str[k] == welcome[l])
					{
						if (branch[l-1] > 0)
						{
							branch[l] = branch[l] + branch[l-1];
						}
					}
				}

				for (m = 0; m < 19; m++)
				{
					if (branch[m] == 0) // to make the program skip unnecessary computation
						break;

					while (branch[m] > 10000) // not to cause overflow
					{
						branch[m] = branch[m] - 10000;
					}
				}
			}


		}

		if (branch[18]<10)
			z_padding = "000";
		else if (branch[18]<100)
			z_padding = "00";
		else if (branch[18]<1000)
			z_padding = "0";
		else // if (branch[18]<10000)
			z_padding = "";

		output << "Case #" << i << ": " << z_padding << branch[18] << endl;
	}

	input.close();
	output.close();
	return 0;
}