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

	unsigned T; string dummy;
	input >> T;
	getline (input, dummy);

	// dictionary found from sample input + qz
	string dictionary1 = "yhesocvxduiglbkrztnwjpfmaq"; // output
	string dictionary2 = "abcdefghijklmnopqrstuvwxyz"; // input

	for (unsigned t = 0; t < T; t++)
	{
		string G;
		int idx;
				
		output << "Case #" << t+1 << ": ";

		getline (input, G);
		int len = G.length();

		for (unsigned n = 0; n < len; n++)
		{
			idx = G[n] - 'a';

			if (idx < 28 && idx >= 0)
				output << dictionary1[idx];
			else
				output << G[n];
		}

		output << endl;
	}


	return 0;
}