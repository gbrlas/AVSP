#include <iostream>
#include <fstream>
using namespace std;

#define INPUT_PATH "WorldCup.inp"
#define OUTPUT_PATH "WorldCup.out"


int T,P;
int miss[1025];
bool view[2100];
int price[2100];
int teamNumber;



void main()
{
	ifstream input;
	input.open(INPUT_PATH);

	ofstream output;
	output.open(OUTPUT_PATH);
	input >> T;
	for (int i=0; i< T; i++)
	{
		input >> P;
		teamNumber = 1;
		for (int j=0; j<P; j++)
			teamNumber *= 2;
		for (int j=0; j<teamNumber; j++)
			input >> miss[j];
		for (int j=0; j<teamNumber-1; j++)
		{
			input >> price[j];
			view[j] = false;
		}

		for (int j=0; j<teamNumber; j++)
		{
			int range = 1;
			int indexMatch = teamNumber-2;
			int startRange = teamNumber-2;
			for (int k=0; k<P-miss[j]; k++)
			{
				view[indexMatch] = true;
				range*=2;
				startRange = startRange - range;
				indexMatch = startRange + (j*range)/teamNumber;
			}
		}
		int count = 0;
		for (int j=0; j<teamNumber-1; j++)
		{
			count += view[j];
		}
		output << "Case #" <<i+1 << ": " <<count << endl;
	}
	input.close();
	output.close();

}