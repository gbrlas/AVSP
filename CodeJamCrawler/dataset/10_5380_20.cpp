#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream fin("A.in", ios_base::in);
	fstream fout("A.out", ios_base::out);

	int cases = 0;

	fin >> cases;
	cout << cases << " cases follow." << endl;

	for(int iterCases = 0; iterCases < cases; iterCases++)
	{
		int snappers, claps;
		fin >> snappers;
		fin >> claps;
		
		bool* state = new bool[snappers];

		for(int iter = 0; iter < snappers; iter++)
		{
			state[iter] = 0;
		}

		for(int clap = 0; clap < claps; clap++)
		{
			for(int index = 0; index < snappers; index++)
			{
				bool providingPower = state[index];
				state[index] = !state[index];
				if(!providingPower)
				{
					break;
				}
			}
		}

		bool lightOn = 1;
		for(int index = 0; index < snappers; index++)
		{
			if(!state[index])
			{
				lightOn = 0;
				break;
			}
		}

		char* result = lightOn ? "ON" : "OFF";

		cout << "Case #" << (iterCases + 1) << ": " << result << endl;
		fout << "Case #" << (iterCases + 1) << ": " << result << endl;
	}

	fout.close();
	cin.ignore();

	return 0;
}
